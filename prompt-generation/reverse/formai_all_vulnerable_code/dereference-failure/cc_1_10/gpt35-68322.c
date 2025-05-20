//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Function to flip the given image horizontally
void flip_horizontal(int *image_data, int height, int width) {
    int i, j;
    int *temp_row = (int *)malloc(sizeof(int) * width);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            // swap corresponding pixels in this row
            int temp = *(image_data + i * width + j);
            *(image_data + i * width + j) = *(image_data + i * width + width - j - 1);
            *(image_data + i * width + width - j - 1) = temp;
        }
    }
    free(temp_row);
}

// Function to adjust the brightness of the given image
void adjust_brightness(int *image_data, int height, int width, int offset) {
    // Iterate through each pixel in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Adjust the brightness by offset value
            int val = *(image_data + i * width + j);
            val += offset;
            if (val < 0) val = 0;
            if (val > 255) val = 255;
            *(image_data + i * width + j) = val;
        }
    }
}

// Function to adjust the contrast of the given image
void adjust_contrast(int *image_data, int height, int width, float factor) {
    // Compute the mean pixel intensity in the image
    float sum = 0;
    int num_pixels = height * width;
    for (int i = 0; i < num_pixels; i++) {
        sum += *(image_data + i);
    }
    float mean = sum / num_pixels;

    // Compute the adjusted intensity of each pixel in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int val = *(image_data + i * width + j);
            val -= mean;
            val *= factor;
            val += mean;
            if (val < 0) val = 0;
            if (val > 255) val = 255;
            *(image_data + i * width + j) = val;
        }
    }
}

int main() {
    // Load the image from file
    const char *filename = "image.data";
    int height = 10, width = 10;
    int *image_data = (int *)malloc(sizeof(int) * height * width);
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s.\n", filename);
        exit(1);
    }
    fread(image_data, sizeof(int), height * width, fp);
    fclose(fp);

    // Flip the image horizontally and print it to console
    printf("Original image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", *(image_data + i * width + j));
        }
        printf("\n");
    }
    flip_horizontal(image_data, height, width);
    printf("Flipped image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", *(image_data + i * width + j));
        }
        printf("\n");
    }

    // Adjust the brightness of the image and print it to console
    int brightness_offset = 50;
    printf("Original image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", *(image_data + i * width + j));
        }
        printf("\n");
    }
    adjust_brightness(image_data, height, width, brightness_offset);
    printf("Brightness-adjusted image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", *(image_data + i * width + j));
        }
        printf("\n");
    }

    // Adjust the contrast of the image and print it to console
    float contrast_factor = 1.5;
    printf("Original image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", *(image_data + i * width + j));
        }
        printf("\n");
    }
    adjust_contrast(image_data, height, width, contrast_factor);
    printf("Contrast-adjusted image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", *(image_data + i * width + j));
        }
        printf("\n");
    }

    free(image_data);
    return 0;
}