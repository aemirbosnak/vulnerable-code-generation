//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define IMAGE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

int main() {
    // Load the image from a file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening the image file.\n");
        return EXIT_FAILURE;
    }

    // Read the header of the BMP file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // Read the pixel data from the BMP file
    pixel *image = malloc(IMAGE_SIZE * sizeof(pixel));
    fread(image, sizeof(pixel), IMAGE_SIZE, fp);
    fclose(fp);

    // Flip the image horizontally
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH / 2; x++) {
            pixel temp = image[y * IMAGE_WIDTH + x];
            image[y * IMAGE_WIDTH + x] = image[y * IMAGE_WIDTH + IMAGE_WIDTH - 1 - x];
            image[y * IMAGE_WIDTH + IMAGE_WIDTH - 1 - x] = temp;
        }
    }

    // Change the brightness and contrast of the image
    float brightness = 1.2;
    float contrast = 0.8;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        image[i].r = (unsigned char) ((float) image[i].r * brightness + contrast * 128);
        image[i].g = (unsigned char) ((float) image[i].g * brightness + contrast * 128);
        image[i].b = (unsigned char) ((float) image[i].b * brightness + contrast * 128);
    }

    // Write the modified image to a file
    fp = fopen("modified_image.bmp", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening the modified image file.\n");
        return EXIT_FAILURE;
    }

    // Write the header of the BMP file
    fwrite(header, sizeof(unsigned char), 54, fp);

    // Write the pixel data to the BMP file
    fwrite(image, sizeof(pixel), IMAGE_SIZE, fp);
    fclose(fp);

    // Free the memory allocated for the image
    free(image);

    return EXIT_SUCCESS;
}