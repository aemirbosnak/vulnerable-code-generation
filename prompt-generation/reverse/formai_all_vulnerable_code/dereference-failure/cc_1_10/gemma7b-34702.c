//Gemma-7B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_WIDTH 1024
#define IMAGE_HEIGHT 768

typedef struct Pixel {
    int r;
    int g;
    int b;
} Pixel;

Pixel **load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    Pixel **image = (Pixel **)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(Pixel));
    if (image == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(image, IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(Pixel), 1, fp);
    fclose(fp);

    return image;
}

Pixel **flip_image(Pixel **image) {
    Pixel **flipped_image = (Pixel **)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(Pixel));
    if (flipped_image == NULL) {
        return NULL;
    }

    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            flipped_image[y][x] = image[IMAGE_HEIGHT - 1 - y][x];
        }
    }

    return flipped_image;
}

Pixel **change_brightness_contrast(Pixel **image, int brightness, int contrast) {
    Pixel **adjusted_image = (Pixel **)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(Pixel));
    if (adjusted_image == NULL) {
        return NULL;
    }

    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            Pixel pixel = image[y][x];

            int r = pixel.r + brightness;
            int g = pixel.g + brightness;
            int b = pixel.b + brightness;

            if (r > 255) {
                r = 255;
            }
            if (g > 255) {
                g = 255;
            }
            if (b > 255) {
                b = 255;
            }

            adjusted_image[y][x].r = r;
            adjusted_image[y][x].g = g;
            adjusted_image[y][x].b = b;
        }
    }

    return adjusted_image;
}

int main() {
    Pixel **image = load_image("image.jpg");
    Pixel **flipped_image = flip_image(image);
    Pixel **adjusted_image = change_brightness_contrast(flipped_image, 50, 20);

    free(image);
    free(flipped_image);
    free(adjusted_image);

    return 0;
}