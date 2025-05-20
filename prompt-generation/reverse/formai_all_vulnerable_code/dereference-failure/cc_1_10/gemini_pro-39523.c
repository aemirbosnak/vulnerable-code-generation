//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to flip an image horizontally
void flip_horizontally(uint8_t *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            uint8_t temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - j - 1];
            image[i * width + width - j - 1] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertically(uint8_t *image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            uint8_t temp = image[i * width + j];
            image[i * width + j] = image[(height - i - 1) * width + j];
            image[(height - i - 1) * width + j] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(uint8_t *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = (int)image[i * width + j] + brightness;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image[i * width + j] = (uint8_t)new_value;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(uint8_t *image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = factor * ((int)image[i * width + j] - 128) + 128;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image[i * width + j] = (uint8_t)new_value;
        }
    }
}

int main() {
    // Read the image from a file
    FILE *file = fopen("image.bmp", "rb");
    if (file == NULL) {
        printf("Error opening the file\n");
        return 1;
    }

    // Get the image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Allocate memory for the image data
    uint8_t *image = malloc(width * height * sizeof(uint8_t));
    if (image == NULL) {
        printf("Error allocating memory for the image\n");
        return 1;
    }

    // Read the image data from the file
    fread(image, sizeof(uint8_t), width * height, file);

    // Close the file
    fclose(file);

    // Flip the image horizontally
    flip_horizontally(image, width, height);

    // Flip the image vertically
    flip_vertically(image, width, height);

    // Change the brightness of the image
    change_brightness(image, width, height, 50);

    // Change the contrast of the image
    change_contrast(image, width, height, 1.5);

    // Write the modified image to a file
    file = fopen("modified_image.bmp", "wb");
    if (file == NULL) {
        printf("Error opening the file\n");
        return 1;
    }

    // Write the image dimensions to the file
    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);

    // Write the image data to the file
    fwrite(image, sizeof(uint8_t), width * height, file);

    // Close the file
    fclose(file);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}