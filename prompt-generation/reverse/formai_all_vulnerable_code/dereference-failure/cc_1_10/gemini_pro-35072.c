//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: careful
#include <stdio.h>
#include <stdlib.h>

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
            int new_value = image[i * width + j] + brightness;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image[i * width + j] = new_value;
        }
    }
}

// Function to change the contrast of an image
void adjust_contrast(unsigned char *image, int width, int height, int contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = (image[i * width + j] - 128) * contrast + 128;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image[i * width + j] = new_value;
        }
    }
}

int main() {
    // Read the input image from a file
    FILE *input_file = fopen("input.bmp", "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Get the image dimensions and data
    int width, height;
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);
    unsigned char *image = malloc(width * height);
    fread(image, 1, width * height, input_file);
    fclose(input_file);

    // Flip the image horizontally
    flip_horizontal(image, width, height);

    // Flip the image vertically
    flip_vertical(image, width, height);

    // Adjust the brightness of the image
    adjust_brightness(image, width, height, 50);

    // Adjust the contrast of the image
    adjust_contrast(image, width, height, 150);

    // Write the output image to a file
    FILE *output_file = fopen("output.bmp", "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fwrite(&width, sizeof(int), 1, output_file);
    fwrite(&height, sizeof(int), 1, output_file);
    fwrite(image, 1, width * height, output_file);
    fclose(output_file);

    // Free the allocated memory
    free(image);

    return 0;
}