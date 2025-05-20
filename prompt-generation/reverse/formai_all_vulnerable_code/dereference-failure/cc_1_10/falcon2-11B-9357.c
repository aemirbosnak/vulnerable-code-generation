//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct Pixel {
    int x;
    int y;
    int intensity;
};

struct Image {
    int width;
    int height;
    struct Pixel *pixels;
};

void convert(struct Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf(" ");
        }
        for (int x = 0; x < image->width; x++) {
            int intensity = image->pixels[y * image->width + x].intensity;
            if (intensity < 50) {
                printf(" ");
            } else if (intensity < 100) {
                printf("*");
            } else {
                printf("+");
            }
        }
        printf("\n");
    }
}

int main() {
    struct Image image;
    image.width = 10;
    image.height = 10;
    image.pixels = (struct Pixel *)malloc(image.width * image.height * sizeof(struct Pixel));

    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            image.pixels[y * image.width + x].x = x;
            image.pixels[y * image.width + x].y = y;
            image.pixels[y * image.width + x].intensity = rand() % 150 + 50;
        }
    }

    convert(&image);

    return 0;
}