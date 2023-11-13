#include "../include/parser.h"

bool is_pbm_file(FILE *image_file)
{
    char magic_number[MAX_LINE_SIZE];
    fgets(magic_number, MAX_LINE_SIZE, image_file);
    return magic_number[0] == 'P' || magic_number[1] == '1';
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

    // Ler largura e altura do arquivo no formato "número número"
    fscanf(image_file, "%d %d", &img.width, &img.height);

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