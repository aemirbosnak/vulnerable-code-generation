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
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i * width + j] = (unsigned char) (image[i * width + j] + brightness);
        }
    }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, int contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i * width + j] = (unsigned char) (128 + contrast * (image[i * width + j] - 128));
        }
    }
}

int main() {
    // Read the image from a file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Get the image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Allocate memory for the image data
    unsigned char *image = (unsigned char *) malloc(width * height * sizeof(unsigned char));
    if (image == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read the image data
    fread(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    // Flip the image horizontally
    flip_horizontal(image, width, height);

    // Flip the image vertically
    flip_vertical(image, width, height);

    // Change the brightness of the image
    change_brightness(image, width, height, 50);

    // Change the contrast of the image
    change_contrast(image, width, height, 50);

    // Write the image to a file
    fp = fopen("new_image.bmp", "wb");
    if (fp == NULL) {
        perror("Error opening file");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Write the image dimensions
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);

    // Write the image data
    fwrite(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    // Free the memory allocated for the image data
    free(image);

    return EXIT_SUCCESS;
}