#include "../include/parser.h"

bool is_pbm_file(FILE *image_file)
{
    char magic_number[MAX_LINE_SIZE];
    fgets(magic_number, MAX_LINE_SIZE, image_file);
    return magic_number[0] != 'P' || magic_number[1] != '1';
}

Image read_binary_image(char path[])
{
    FILE *file = fopen(path, "r");

    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    Image img;
    img.width = 0;
    img.height = 0;
    img.pixels = NULL;

    char magic_number[MAX_LINE_SIZE];
    fgets(magic_number, MAX_LINE_SIZE, file);

    if (!is_pbm_file(file))
    {
        fprintf(stderr, "Formato PBM inválido\n");
        exit(EXIT_FAILURE);
    }

    // Ignorar comentários
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file) != NULL)
    {
        if (line[0] != '#')
        {
            break;
        }
    }

    // Ler largura e altura de forma segura
    sscanf(line, "%d %d", &img.width, &img.height);

    img.pixels = (int *)malloc(img.width * img.height * sizeof(int));

    // Ler os pixels
    for (int i = 0; i < img.height; ++i)
    {
        for (int j = 0; j < img.width; ++j)
        {
            int pixel;
            fscanf(file, "%d", &pixel);
            img.pixels[i * img.width + j] = pixel;
        }

    }

    fclose(file);
    return img;
}