//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 640
#define HEIGHT 480

void flip_horizontally(uint8_t *image, int width, int height) {
    int half_width = width / 2;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < half_width; x++) {
            uint8_t temp = image[y * width + x];
            image[y * width + x] = image[y * width + width - 1 - x];
            image[y * width + width - 1 - x] = temp;
        }
    }
}

void flip_vertically(uint8_t *image, int width, int height) {
    int half_height = height / 2;
    for (int y = 0; y < half_height; y++) {
        for (int x = 0; x < width; x++) {
            uint8_t temp = image[y * width + x];
            image[y * width + x] = image[(height - 1 - y) * width + x];
            image[(height - 1 - y) * width + x] = temp;
        }
    }
}

void change_brightness(uint8_t *image, int width, int height, int brightness) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y * width + x] = image[y * width + x] + brightness;
            if (image[y * width + x] > 255) {
                image[y * width + x] = 255;
            } else if (image[y * width + x] < 0) {
                image[y * width + x] = 0;
            }
        }
    }
}

void change_contrast(uint8_t *image, int width, int height, float contrast) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y * width + x] = image[y * width + x] * contrast;
            if (image[y * width + x] > 255) {
                image[y * width + x] = 255;
            } else if (image[y * width + x] < 0) {
                image[y * width + x] = 0;
            }
        }
    }
}

int main() {
    // Read the image from a file
    FILE *file = fopen("image.bmp", "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fseek(file, 54, SEEK_SET); // Skip the header
    uint8_t *image = malloc(WIDTH * HEIGHT);
    fread(image, 1, WIDTH * HEIGHT, file);
    fclose(file);

    // Flip the image horizontally
    flip_horizontally(image, WIDTH, HEIGHT);

    // Flip the image vertically
    flip_vertically(image, WIDTH, HEIGHT);

    // Change the brightness of the image
    change_brightness(image, WIDTH, HEIGHT, 50);

    // Change the contrast of the image
    change_contrast(image, WIDTH, HEIGHT, 1.5);

    // Write the image to a file
    file = fopen("modified_image.bmp", "wb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fseek(file, 54, SEEK_SET); // Skip the header
    fwrite(image, 1, WIDTH * HEIGHT, file);
    fclose(file);

    free(image);

    return 0;
}