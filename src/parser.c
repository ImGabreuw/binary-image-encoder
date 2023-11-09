#include "../include/parser.h"

bool is_pbm_file(FILE *image_file)
{
    char first_line[PBM_CODE_SIZE];
    fscanf(image_file, "%[^\n]", first_line);
    return strcmp(first_line, "P1");
}

int *read_binary_image(char path[])
{
    FILE *image_file = fopen(path, "r");

    int width = 0;
    int height = 0;
    int *image = (int *)malloc(0);

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, image_file) != NULL)
    {
        if (line[0] == '#')
            continue;

        realloc(image, width * ++height * sizeof(int));

        char *bits = strtok(line, " ");
        int bits_size = sizeof(bits) / sizeof(bits[0]);

        for (int i = 0; i < bits_size; ++i)
        {
            realloc(image, ++width * height * sizeof(int));
            int offset = height - 1 + i;
            image[offset] = bits[i];
        }
    }

    return image;
}