//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} pixel;

int main() {
    // Read the image file
    FILE *fp = fopen("image.ppm", "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening image file\n");
        return 1;
    }

    // Read the header information
    char header[256];
    fgets(header, 256, fp);
    if (strncmp(header, "P6", 2) != 0) {
        fprintf(stderr, "Error: Invalid image format\n");
        return 1;
    }

    int width, height, maxval;
    fscanf(fp, "%d %d %d", &width, &height, &maxval);

    // Allocate memory for the image data
    pixel *image = malloc(sizeof(pixel) * width * height);
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        return 1;
    }

    // Read the image data
    fread(image, sizeof(pixel), width * height, fp);
    fclose(fp);

    // Convert the image to ASCII art
    char *ascii = malloc(sizeof(char) * width * height);
    if (ascii == NULL) {
        fprintf(stderr, "Error allocating memory for ASCII art\n");
        return 1;
    }

    for (int i = 0; i < width * height; i++) {
        // Calculate the brightness of the pixel
        double brightness = (double)(image[i].r + image[i].g + image[i].b) / 3 / maxval;

        // Convert the brightness to an ASCII character
        char c = (char)floor(brightness * 70 + 32);

        // Store the ASCII character in the output buffer
        ascii[i] = c;
    }

    // Print the ASCII art to the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii[i * width + j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(image);
    free(ascii);

    return 0;
}