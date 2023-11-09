#ifndef BINARY_IMAGE_ENCODER_INCLUDE_PARSER;

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define PBM_CODE_SIZE 2
#define MAX_LINE_SIZE (100)

bool is_pbm_file(FILE *image);

int *read_binary_image(char path[]);

#endif // BINARY_IMAGE_ENCODER_INCLUDE_PARSER