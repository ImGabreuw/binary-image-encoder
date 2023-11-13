#ifndef BINARY_IMAGE_ENCODER_INCLUDE_PARSER

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "image.h"

#define PBM_CODE_SIZE 2
#define MAX_LINE_SIZE 1024

bool is_pbm_file(FILE *image);

Image read_binary_image(const char path[]);

#endif // BINARY_IMAGE_ENCODER_INCLUDE_PARSER