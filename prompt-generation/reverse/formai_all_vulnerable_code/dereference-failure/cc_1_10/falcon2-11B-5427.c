//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for image size
#define WIDTH 100
#define HEIGHT 100

// Define function prototypes
void flip(unsigned char *pixels, int height, int width);
void change_brightness(unsigned char *pixels, int height, int width, float factor);
void change_contrast(unsigned char *pixels, int height, int width, float factor);

int main() {
    // Read image from file
    FILE *file = fopen("image.png", "rb");
    if (file == NULL) {
        printf("Failed to open image file.\n");
        return 1;
    }

    // Read image data into array
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *pixels = (unsigned char *)malloc(size);
    if (pixels == NULL) {
        printf("Failed to allocate memory for image data.\n");
        return 1;
    }

    fread(pixels, size, 1, file);
    fclose(file);

    // Flip the image horizontally
    flip(pixels, HEIGHT, WIDTH);

    // Change brightness of the image
    change_brightness(pixels, HEIGHT, WIDTH, 1.5);

    // Change contrast of the image
    change_contrast(pixels, HEIGHT, WIDTH, 1.2);

    // Write modified image to file
    FILE *outfile = fopen("output.png", "wb");
    if (outfile == NULL) {
        printf("Failed to open output file.\n");
        return 1;
    }

    fwrite(pixels, size, 1, outfile);
    fclose(outfile);

    // Free memory
    free(pixels);

    printf("Image processing completed successfully.\n");
    return 0;
}

void flip(unsigned char *pixels, int height, int width) {
    // Flip the image horizontally
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            unsigned char temp = pixels[i * width + j];
            pixels[i * width + j] = pixels[i * width + width - 1 - j];
            pixels[i * width + width - 1 - j] = temp;
        }
    }
}

void change_brightness(unsigned char *pixels, int height, int width, float factor) {
    // Change brightness of the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i * width + j] *= factor;
        }
    }
}

void change_contrast(unsigned char *pixels, int height, int width, float factor) {
    // Change contrast of the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i * width + j] += (unsigned char)((pixels[i * width + j] * factor) / 255);
        }
    }
}