#include "../include/parser.h"
#include "../include/cli.h"
#include "../include/encoder.h"

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        if (strcmp(argv[1], "-?") == 0 || strcmp(argv[1], "--help") == 0)
        {
            help();
            return 0;
        }

        manual(argc, argv);
        return 0;
    }

    if (argc == 3)
    {
        file(argc, argv);
        return 0;
    }

    help();

    return 0;
}

void help()
{
    puts("Uso: ImageEncoder [-? | -m | -f ARQ]");
    puts("Codifica imagens binárias dadas em arquivos PBM ou por dados informados manualmente.");
    puts("Argumentos:");
    puts("-?, --help  : apresenta essa orientação na tela.");
    puts("-m, --manual: ativa o modo de entrada manual, em que o usuário fornece todos os dados da imagem informando-os através do teclado.");
    puts("-f, --file: considera a imagem representada no arquivo PBM (Portable bitmap).");
}

void manual(int argc, char const *argv[])
{
    if (strcmp(argv[1], "-m") != 0 && strcmp(argv[1], "--manual") != 0)
    {
        return;
    }

    Image img;
    img.width = 0;
    img.height = 0;
    img.pixels = NULL;

    scanf("%d %d", &img.width, &img.height);

    img.pixels = (int *)malloc(img.width * img.height * sizeof(int));

    for (int i = 0; i < img.height; ++i)
    {
        char line[MAX_LINE_SIZE];
        scanf(" %[^\n]", line); // Adicionando um espaço antes de %[^\n] para consumir o \n no buffer ("line")

        char *token = strtok(line, " ");
        int j = 0;

        while (token != NULL && j < img.width)
        {
            img.pixels[i * img.width + j] = atoi(token);

            token = strtok(NULL, " ");
            j++;
        }
    }

    char *code = (char *)malloc(sizeof(char));
    code[0] = '\0';
    encode(img, 0, img.height - 1, 0, img.width - 1, code);
    printf("%s\n", code);

    free(code);
}

void file(int argc, char const *argv[])
{
    if (strcmp(argv[1], "-f") != 0 && strcmp(argv[1], "--file") != 0)
    {
        return;
    }

    Image img = read_binary_image(argv[2]);

    char *code = (char *)malloc(sizeof(char));
    code[0] = '\0';
    encode(img, 0, img.height - 1, 0, img.width - 1, code);
    printf("%s\n", code);

    free(code);
}