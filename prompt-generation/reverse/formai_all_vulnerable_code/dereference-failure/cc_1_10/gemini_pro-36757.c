//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Macros for image dimensions
#define WIDTH  1280
#define HEIGHT 720

// Function to flip an image horizontally
void flip_horizontal(uint8_t *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            // Swap the pixels at (x, y) and (width - x - 1, y)
            uint8_t temp = image[y * width + x];
            image[y * width + x] = image[y * width + (width - x - 1)];
            image[y * width + (width - x - 1)] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertical(uint8_t *image, int width, int height) {
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            // Swap the pixels at (x, y) and (x, height - y - 1)
            uint8_t temp = image[y * width + x];
            image[y * width + x] = image[(height - y - 1) * width + x];
            image[(height - y - 1) * width + x] = temp;
        }
    }
}

// Function to change the brightness of an image
void adjust_brightness(uint8_t *image, int width, int height, int brightness) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Clamp the brightness to 0-255
            int new_value = image[y * width + x] + brightness;
            if (new_value < 0) new_value = 0;
            if (new_value > 255) new_value = 255;
            image[y * width + x] = new_value;
        }
    }
}

// Function to change the contrast of an image
void adjust_contrast(uint8_t *image, int width, int height, float contrast) {
    // Calculate the mean brightness of the image
    float mean = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            mean += image[y * width + x];
        }
    }
    mean /= width * height;

    // Adjust the contrast
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the new value based on the contrast setting
            int new_value = (image[y * width + x] - mean) * contrast + mean;
            // Clamp the value to 0-255
            if (new_value < 0) new_value = 0;
            if (new_value > 255) new_value = 255;
            image[y * width + x] = new_value;
        }
    }
}

int main() {
    // Allocate memory for the image
    uint8_t *image = malloc(WIDTH * HEIGHT);

    // Load the image from a file
    FILE *file = fopen("image.raw", "rb");
    if (file == NULL) {
        printf("Error loading image file.\n");
        return 1;
    }
    fread(image, 1, WIDTH * HEIGHT, file);
    fclose(file);

    // Flip the image horizontally
    flip_horizontal(image, WIDTH, HEIGHT);

    // Adjust the brightness
    adjust_brightness(image, WIDTH, HEIGHT, 30);

    // Adjust the contrast
    adjust_contrast(image, WIDTH, HEIGHT, 1.2);

    // Save the modified image to a file
    file = fopen("modified_image.raw", "wb");
    if (file == NULL) {
        printf("Error saving image file.\n");
        return 1;
    }
    fwrite(image, 1, WIDTH * HEIGHT, file);
    fclose(file);

    // Free the memory allocated for the image
    free(image);

    return 0;
}