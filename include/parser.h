#ifndef BINARY_IMAGE_ENCODER_INCLUDE_PARSER

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define PBM_CODE_SIZE 2
#define MAX_LINE_SIZE 1024

typedef struct {
    int width;
    int height;
    int *pixels;
} Image;

bool is_pbm_file(FILE *image);

Image read_binary_image(char path[]);

#endif // BINARY_IMAGE_ENCODER_INCLUDE_PARSER