//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
    int i, j;
    unsigned char temp;

    for (i = 0; i < height / 2; i++) {
        for (j = 0; j < width; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[(height - i - 1) * width + j];
            image[(height - i - 1) * width + j] = temp;
        }
    }
}

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
    int i, j;
    unsigned char temp;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[i * width + (width - j - 1)];
            image[i * width + (width - j - 1)] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i * width + j] = image[i * width + j] + brightness;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, float contrast) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i * width + j] = image[i * width + j] * contrast;
        }
    }
}

// Main function
int main() {
    // Read the image from a file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Get the dimensions of the image
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Allocate memory for the image data
    unsigned char *image = malloc(width * height);

    // Read the image data from the file
    fread(image, 1, width * height, fp);

    // Close the file
    fclose(fp);

    // Flip the image vertically
    flip_vertical(image, width, height);

    // Flip the image horizontally
    flip_horizontal(image, width, height);

    // Change the brightness of the image
    change_brightness(image, width, height, 50);

    // Change the contrast of the image
    change_contrast(image, width, height, 1.2);

    // Write the image to a file
    fp = fopen("new_image.bmp", "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Write the dimensions of the image to the file
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);

    // Write the image data to the file
    fwrite(image, 1, width * height, fp);

    // Close the file
    fclose(fp);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}