//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255
#define MIN_PIXEL_VALUE 0

// Function to flip the image horizontally
void horizontal_flip(unsigned char *image_data, int width, int height) {
    int row, col;

    for (row = 0; row < height; row++) {
        for (col = 0; col < width / 2; col++) {
            unsigned char temp = image_data[row * width + col];
            image_data[row * width + col] = image_data[row * width + (width - col - 1)];
            image_data[row * width + (width - col - 1)] = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjust_brightness(unsigned char *image_data, int width, int height, int brightness) {
    int i;

    for (i = 0; i < width * height; i++) {
        int pixel_value = (int)image_data[i] + brightness;

        if (pixel_value > MAX_PIXEL_VALUE) {
            image_data[i] = MAX_PIXEL_VALUE;
        } else if (pixel_value < MIN_PIXEL_VALUE) {
            image_data[i] = MIN_PIXEL_VALUE;
        } else {
            image_data[i] = (unsigned char)pixel_value;
        }
    }
}

// Function to adjust the contrast of the image
void adjust_contrast(unsigned char *image_data, int width, int height, float contrast) {
    int i;

    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for (i = 0; i < width * height; i++) {
        int pixel_value = (int)(factor * (image_data[i] - 128) + 128);

        if (pixel_value > MAX_PIXEL_VALUE) {
            image_data[i] = MAX_PIXEL_VALUE;
        } else if (pixel_value < MIN_PIXEL_VALUE) {
            image_data[i] = MIN_PIXEL_VALUE;
        } else {
            image_data[i] = (unsigned char)pixel_value;
        }
    }
}

int main() {
    unsigned char *image_data = NULL;
    char *filename = "image.raw";
    int width = 512;
    int height = 512;

    // Read image data from file
    FILE *file = fopen(filename, "rb");

    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    image_data = (unsigned char*) malloc(width * height * sizeof(unsigned char));

    if (!image_data) {
        printf("Memory allocation error\n");
        return 1;
    }

    fread(image_data, sizeof(unsigned char), width * height, file);
    fclose(file);

    // Perform image processing operations
    horizontal_flip(image_data, width, height);
    adjust_brightness(image_data, width, height, 50);
    adjust_contrast(image_data, width, height, 50.0);

    // Write image data to file
    filename = "processed_image.raw";
    file = fopen(filename, "wb");

    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    fwrite(image_data, sizeof(unsigned char), width * height, file);
    fclose(file);

    free(image_data);

    printf("Image processing complete!\n");

    return 0;
}