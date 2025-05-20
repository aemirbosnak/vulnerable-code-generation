//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - j - 1];
            image[i * width + width - j - 1] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[(height - i - 1) * width + j];
            image[(height - i - 1) * width + j] = temp;
        }
    }
}

// Function to change the brightness of an image
void adjust_brightness(unsigned char *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_brightness = image[i * width + j] + brightness;
            if (new_brightness > 255) {
                new_brightness = 255;
            } else if (new_brightness < 0) {
                new_brightness = 0;
            }
            image[i * width + j] = new_brightness;
        }
    }
}

// Function to change the contrast of an image
void adjust_contrast(unsigned char *image, int width, int height, int contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_contrast = (image[i * width + j] - 128) * contrast + 128;
            if (new_contrast > 255) {
                new_contrast = 255;
            } else if (new_contrast < 0) {
                new_contrast = 0;
            }
            image[i * width + j] = new_contrast;
        }
    }
}

int main() {
    // Define the image dimensions
    int width = 640;
    int height = 480;

    // Create an image buffer
    unsigned char *image = malloc(width * height);

    // Load the image from a file
    FILE *file = fopen("image.bmp", "rb");
    fread(image, 1, width * height, file);
    fclose(file);

    // Flip the image horizontally
    flip_horizontal(image, width, height);

    // Flip the image vertically
    flip_vertical(image, width, height);

    // Adjust the brightness of the image
    adjust_brightness(image, width, height, 50);

    // Adjust the contrast of the image
    adjust_contrast(image, width, height, 1.5);

    // Save the modified image to a file
    file = fopen("modified_image.bmp", "wb");
    fwrite(image, 1, width * height, file);
    fclose(file);

    // Free the image buffer
    free(image);

    return 0;
}