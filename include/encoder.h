#ifndef BINARY_IMAGE_ENCODER_INCLUDE_ENCODER

#include <stdbool.h>
#include <stdlib.h>

bool is_uniform(Image image, int start_row, int end_row, int start_col, int end_col);

void encode(Image image, int start_row, int end_row, int start_col, int end_col, char *code);

#endif // BINARY_IMAGE_ENCODER_INCLUDE_ENCODER