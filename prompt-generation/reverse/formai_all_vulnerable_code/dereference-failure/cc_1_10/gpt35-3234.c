//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Define image dimensions
#define ROWS 480
#define COLS 640

// Function to flip the image horizontally
void flip_horizontal(unsigned char* image) {
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS / 2; x++) {
            int left_pixel_index = (y * COLS + x) * 3;
            int right_pixel_index = (y * COLS + (COLS - x - 1)) * 3;

            // Swap the left and right pixels
            unsigned char temp_1 = image[left_pixel_index];
            unsigned char temp_2 = image[left_pixel_index + 1];
            unsigned char temp_3 = image[left_pixel_index + 2];

            image[left_pixel_index] = image[right_pixel_index];
            image[left_pixel_index + 1] = image[right_pixel_index + 1];
            image[left_pixel_index + 2] = image[right_pixel_index + 2];

            image[right_pixel_index] = temp_1;
            image[right_pixel_index + 1] = temp_2;
            image[right_pixel_index + 2] = temp_3;
        }
    }
}

// Function to adjust the brightness of the image
void adjust_brightness(unsigned char* image, int brightness_factor) {
    for (int i = 0; i < ROWS * COLS * 3; i++) {
        // Add the brightness factor to each channel value
        int pixel_value = image[i] + brightness_factor;

        // Make sure the pixel value is within the valid range (0-255)
        if (pixel_value < 0) {
            pixel_value = 0;
        } else if (pixel_value > 255) {
            pixel_value = 255;
        }

        image[i] = (unsigned char)pixel_value;
    }
}

// Function to adjust the contrast of the image
void adjust_contrast(unsigned char* image, float contrast_factor) {
    // Calculate the scaling factor for the contrast adjustment
    float scaling_factor = (259.0 * (contrast_factor + 255.0)) / (255.0 * (259.0 - contrast_factor));

    for (int i = 0; i < ROWS * COLS * 3; i++) {
        // Apply the contrast adjustment to each channel value
        int pixel_value = (int)(scaling_factor * (image[i] - 128) + 128);

        // Make sure the pixel value is within the valid range (0-255)
        if (pixel_value < 0) {
            pixel_value = 0;
        } else if (pixel_value > 255) {
            pixel_value = 255;
        }

        image[i] = (unsigned char)pixel_value;
    }
}

int main() {
    // Load the image data from file
    FILE* image_file = fopen("image.raw", "rb");
    unsigned char* image = (unsigned char*)malloc(ROWS * COLS * 3 * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), ROWS * COLS * 3, image_file);
    fclose(image_file);

    // Flip the image horizontally
    flip_horizontal(image);

    // Adjust the brightness by adding 50 to each pixel value
    adjust_brightness(image, 50);

    // Adjust the contrast by multiplying the pixel values by 1.5
    adjust_contrast(image, 1.5);

    // Save the modified image data to file
    FILE* modified_image_file = fopen("modified_image.raw", "wb");
    fwrite(image, sizeof(unsigned char), ROWS * COLS * 3, modified_image_file);
    fclose(modified_image_file);

    free(image);

    return 0;
}