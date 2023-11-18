#include "../include/parser.h"

bool is_pbm_file(FILE *image_file)
{
    char magic_number[PBM_CODE_SIZE];
    fscanf(image_file, "%2s", magic_number);
    return strcmp(magic_number, "P1") == 0;
}

Image read_binary_image(const char path[])
{
    FILE *image_file = fopen(path, "r");

    if (image_file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    Image img;
    img.width = 0;
    img.height = 0;
    img.pixels = NULL;

    if (!is_pbm_file(image_file))
    {
        fprintf(stderr, "Formato PBM inválido\n");
        exit(EXIT_FAILURE);
    }

    // Ingnorar comentários
    int break_char;
    while ((break_char = fgetc(image_file)) == '#' || isspace(break_char))
    {
        if (break_char == '#')
        {
            fscanf(image_file, "%*[^\n]"); // Pular a linha de comentário
        }
    }
    ungetc(break_char, image_file); // Devolver o caractere que encerrou o loop

    // Ler largura e altura do arquivo
    if (fscanf(image_file, "%d %d", &img.width, &img.height) != 2)
    {
        fprintf(stderr, "Error reading width and height.\n");
        exit(EXIT_FAILURE);
    }

    img.pixels = (int *)malloc(img.width * img.height * sizeof(int));

    // Ler os pixels
    for (int i = 0; i < img.height; ++i)
    {
        for (int j = 0; j < img.width; ++j)
        {
            int pixel;
            fscanf(image_file, "%d", &pixel);
            img.pixels[i * img.width + j] = pixel;
        }
    }

    fclose(image_file);
    return img;
}