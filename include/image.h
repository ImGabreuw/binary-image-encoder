#ifndef BINARY_IMAGE_ENCODER_INCLUDE_IMAGE
#define BINARY_IMAGE_ENCODER_INCLUDE_IMAGE

typedef struct Image {
    int width;
    int height;
    int *pixels;
} Image;

#endif // BINARY_IMAGE_ENCODER_INCLUDE_IMAGE