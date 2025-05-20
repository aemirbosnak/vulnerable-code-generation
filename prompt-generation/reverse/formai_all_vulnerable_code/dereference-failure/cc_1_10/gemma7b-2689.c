//Gemma-7B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

typedef struct Pixel {
    int r;
    int g;
    int b;
    int a;
} Pixel;

Pixel **load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    Pixel **pixels = (Pixel **)malloc(IMAGE_HEIGHT * sizeof(Pixel *));
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        pixels[i] = (Pixel *)malloc(IMAGE_WIDTH * sizeof(Pixel));
    }

    fread(pixels, IMAGE_HEIGHT * IMAGE_WIDTH * sizeof(Pixel), 1, fp);
    fclose(fp);

    return pixels;
}

void save_image(Pixel **pixels, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(pixels, IMAGE_HEIGHT * IMAGE_WIDTH * sizeof(Pixel), 1, fp);
    fclose(fp);
}

int main() {
    Pixel **pixels = load_image("image.jpg");
    Pixel **flipped_pixels = (Pixel **)malloc(IMAGE_HEIGHT * sizeof(Pixel *));
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        flipped_pixels[i] = (Pixel *)malloc(IMAGE_WIDTH * sizeof(Pixel));
    }

    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            flipped_pixels[y][x].r = pixels[y][x].b;
            flipped_pixels[y][x].g = pixels[y][x].r;
            flipped_pixels[y][x].b = pixels[y][x].g;
        }
    }

    save_image(flipped_pixels, "flipped_image.jpg");

    return 0;
}