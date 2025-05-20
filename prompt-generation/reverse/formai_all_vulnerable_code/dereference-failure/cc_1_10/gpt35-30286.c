//FormAI DATASET v1.0 Category: Image Editor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for image dimensions
#define IMG_WIDTH  500
#define IMG_HEIGHT 500

// Define function to convert RGB values to grayscale
float grayscale(int r, int g, int b) {
    return (0.2126 * r) + (0.7152 * g) + (0.0722 * b);
}

int main() {

    // Allocate memory for image matrix
    float **image = malloc(IMG_HEIGHT * sizeof(float *));
    for (int i = 0; i < IMG_HEIGHT; i++) {
        image[i] = malloc(IMG_WIDTH * sizeof(float));
    }

    // Read image data from file into matrix
    FILE *fp = fopen("image.rgb", "rb");
    unsigned char buffer[3];
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            fread(buffer, 3, 1, fp);
            image[i][j] = grayscale(buffer[0], buffer[1], buffer[2]);
        }
    }
    fclose(fp);

    // Manipulate image matrix (e.g. apply edge detection)

    // Write image data from matrix to file
    fp = fopen("edited_image.rgb", "wb");
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            unsigned char pixel = (unsigned char) image[i][j];
            fwrite(&pixel, 1, 1, fp);
            fwrite(&pixel, 1, 1, fp);
            fwrite(&pixel, 1, 1, fp);
        }
    }
    fclose(fp);

    // Deallocate image matrix memory
    for (int i = 0; i < IMG_HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}