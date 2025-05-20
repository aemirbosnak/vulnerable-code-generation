//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    uint8_t r, g, b;
} pixel_t;

void flip_image(pixel_t *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            pixel_t temp = image[y * width + x];
            image[y * width + x] = image[y * width + width - 1 - x];
            image[y * width + width - 1 - x] = temp;
        }
    }
}

void adjust_brightness(pixel_t *image, int width, int height, float brightness_factor) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y * width + x].r = (uint8_t)fmin(255, image[y * width + x].r * brightness_factor);
            image[y * width + x].g = (uint8_t)fmin(255, image[y * width + x].g * brightness_factor);
            image[y * width + x].b = (uint8_t)fmin(255, image[y * width + x].b * brightness_factor);
        }
    }
}

void adjust_contrast(pixel_t *image, int width, int height, float contrast_factor) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float factor = (image[y * width + x].r / 127.5) - 1;
            image[y * width + x].r = (uint8_t)fmin(255, 127.5 * (contrast_factor * factor + 1));
            factor = (image[y * width + x].g / 127.5) - 1;
            image[y * width + x].g = (uint8_t)fmin(255, 127.5 * (contrast_factor * factor + 1));
            factor = (image[y * width + x].b / 127.5) - 1;
            image[y * width + x].b = (uint8_t)fmin(255, 127.5 * (contrast_factor * factor + 1));
        }
    }
}

int main() {
    // Allocate memory for the image
    pixel_t *image = malloc(WIDTH * HEIGHT * sizeof(pixel_t));

    // Load the image from a file
    FILE *file = fopen("image.bmp", "rb");
    if (file == NULL) {
        printf("Error opening file");
        return -1;
    }
    fread(image, sizeof(pixel_t), WIDTH * HEIGHT, file);
    fclose(file);

    // Flip the image horizontally
    flip_image(image, WIDTH, HEIGHT);

    // Adjust the brightness of the image
    adjust_brightness(image, WIDTH, HEIGHT, 1.2);

    // Adjust the contrast of the image
    adjust_contrast(image, WIDTH, HEIGHT, 1.5);

    // Save the image to a file
    file = fopen("processed_image.bmp", "wb");
    if (file == NULL) {
        printf("Error opening file");
        return -1;
    }
    fwrite(image, sizeof(pixel_t), WIDTH * HEIGHT, file);
    fclose(file);

    // Free the memory allocated for the image
    free(image);

    return 0;
}