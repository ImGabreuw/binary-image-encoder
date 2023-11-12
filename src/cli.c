#include "../include/parser.h"

int main(int argc, char const *argv[])
{
    Image img = read_binary_image("/home/gabriel/Projects/binary-image-encoder/images/image1.pbm");
    printf("%d\n", img.width);
    printf("%d\n", img.height);
    printf("%d\n", img.pixels[0]);
    return 0;
}
