//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    unsigned char r, g, b;
} pixel;

void flip_image(pixel *image) {
    int i, j;
    pixel temp;
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH / 2; i++) {
            temp = image[j * WIDTH + i];
            image[j * WIDTH + i] = image[j * WIDTH + WIDTH - i - 1];
            image[j * WIDTH + WIDTH - i - 1] = temp;
        }
    }
}

void change_brightness(pixel *image, int brightness) {
    int i, j;
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            image[j * WIDTH + i].r = image[j * WIDTH + i].r + brightness;
            image[j * WIDTH + i].g = image[j * WIDTH + i].g + brightness;
            image[j * WIDTH + i].b = image[j * WIDTH + i].b + brightness;
        }
    }
}

void change_contrast(pixel *image, int contrast) {
    int i, j;
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            image[j * WIDTH + i].r = image[j * WIDTH + i].r * contrast;
            image[j * WIDTH + i].g = image[j * WIDTH + i].g * contrast;
            image[j * WIDTH + i].b = image[j * WIDTH + i].b * contrast;
        }
    }
}

void save_image(pixel *image, char *filename) {
    FILE *f = fopen(filename, "wb");
    fwrite(image, sizeof(pixel), WIDTH * HEIGHT, f);
    fclose(f);
}

int main() {
    pixel *image = malloc(sizeof(pixel) * WIDTH * HEIGHT);

    // Load the image from a file
    FILE *f = fopen("input.bmp", "rb");
    fread(image, sizeof(pixel), WIDTH * HEIGHT, f);
    fclose(f);

    // Flip the image
    flip_image(image);

    // Change the brightness
    change_brightness(image, 50);

    // Change the contrast
    change_contrast(image, 1.5);

    // Save the image to a file
    save_image(image, "output.bmp");

    free(image);
    return 0;
}