//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
    int width;
    int height;
    unsigned char *pixels;
} Image;

Image *createImage(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height);
    return image;
}

void setImagePixels(Image *image, unsigned char *pixels, int pixelCount) {
    memcpy(image->pixels, pixels, pixelCount);
}

void printImageAsASCII(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char pixelValue = image->pixels[y * image->width + x];
            switch (pixelValue) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("$");
                    break;
                case 3:
                    printf("#");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    Image *image = createImage(8, 8);
    setImagePixels(image, "11111111\n"
                              "11111111\n"
                              "11111111\n"
                              "11111111\n"
                              "11111111\n"
                              "11111111\n"
                              "11111111\n"
                              "11111111", 32);

    printImageAsASCII(image);

    free(image);
    return 0;
}