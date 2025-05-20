//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void flip_image_horizontally(int width, int height, unsigned char* image);
void adjust_brightness(int width, int height, unsigned char* image, int brightness_offset);
void adjust_contrast(int width, int height, unsigned char* image, float contrast_factor);

int main() {
    // Load image from file
    FILE* image_file = fopen("image.raw", "rb");
    int width = 640;
    int height = 480;
    unsigned char* image = (unsigned char*) malloc(width * height * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), width * height, image_file);
    fclose(image_file);

    // Flip image horizontally
    flip_image_horizontally(width, height, image);

    // Adjust brightness
    adjust_brightness(width, height, image, 50);

    // Adjust contrast
    adjust_contrast(width, height, image, 1.5);

    // Save processed image to file
    FILE* processed_image_file = fopen("processed_image.raw", "wb");
    fwrite(image, sizeof(unsigned char), width * height, processed_image_file);
    fclose(processed_image_file);

    // Free allocated memory
    free(image);

    return 0;
}

void flip_image_horizontally(int width, int height, unsigned char* image) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            unsigned char temp = image[y * width + x];
            image[y * width + x] = image[y * width + (width - 1 - x)];
            image[y * width + (width - 1 - x)] = temp;
        }
    }
}

void adjust_brightness(int width, int height, unsigned char* image, int brightness_offset) {
    for (int i = 0; i < width * height; i++) {
        int new_value = (int)image[i] + brightness_offset;
        if (new_value < 0) {
            new_value = 0;
        } else if (new_value > 255) {
            new_value = 255;
        }
        image[i] = (unsigned char)new_value;
    }
}

void adjust_contrast(int width, int height, unsigned char* image, float contrast_factor) {
    float factor = (259.0 * (contrast_factor + 255.0)) / (255.0 * (259.0 - contrast_factor));

    for (int i = 0; i < width * height; i++) {
        int new_value = (int)(factor * (image[i] - 128) + 128);
        if (new_value < 0) {
            new_value = 0;
        } else if (new_value > 255) {
            new_value = 255;
        }
        image[i] = (unsigned char)new_value;
    }
}