//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum image size
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Define the image data structure
typedef struct {
    int width;
    int height;
    int data[MAX_HEIGHT][MAX_WIDTH];
} Image;

// Read an image from file
void ReadImage(Image *image, const char *filename) {
    // Open file in binary mode
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read the image header
    char magic[3];
    fscanf(file, "%2s", magic);
    if (strcmp(magic, "P2") != 0) {
        fprintf(stderr, "Invalid file format\n");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%d%d", &image->width, &image->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    if (maxval != 255) {
        fprintf(stderr, "Invalid file format\n");
        exit(EXIT_FAILURE);
    }

    // Read the image data
    for (int row = 0; row < image->height; row++) {
        for (int col = 0; col < image->width; col++) {
            fscanf(file, "%d", &image->data[row][col]);
        }
    }

    // Close the file
    fclose(file);
}

// Write an image to file
void WriteImage(const Image *image, const char *filename) {
    // Open file in binary mode
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Write the image header
    fprintf(file, "P2\n%d %d\n255\n", image->width, image->height);

    // Write the image data
    for (int row = 0; row < image->height; row++) {
        for (int col = 0; col < image->width; col++) {
            fprintf(file, "%d ", image->data[row][col]);
        }
        fprintf(file, "\n");
    }

    // Close the file
    fclose(file);
}

// Flip an image horizontally
void FlipHorizontal(Image *image) {
    for (int row = 0; row < image->height; row++) {
        for (int col = 0; col < image->width / 2; col++) {
            // Swap pixels
            int tmp = image->data[row][col];
            image->data[row][col] = image->data[row][image->width - col - 1];
            image->data[row][image->width - col - 1] = tmp;
        }
    }
}

// Change the brightness of an image
void Brightness(Image *image, int delta) {
    for (int row = 0; row < image->height; row++) {
        for (int col = 0; col < image->width; col++) {
            // Add delta to pixel value
            int value = image->data[row][col] + delta;
            // Clamp to [0, 255] range
            image->data[row][col] = fmax(0, fmin(255, value));
        }
    }
}

// Change the contrast of an image
void Contrast(Image *image, float factor) {
    for (int row = 0; row < image->height; row++) {
        for (int col = 0; col < image->width; col++) {
            // Multiply pixel value by factor
            int value = (int) round(factor * image->data[row][col]);
            // Clamp to [0, 255] range
            image->data[row][col] = fmax(0, fmin(255, value));
        }
    }
}

int main() {
    // Declare image object
    Image image;

    // Read image from file
    ReadImage(&image, "input.pgm");

    // Flip image horizontally
    FlipHorizontal(&image);

    // Change brightness by 50
    Brightness(&image, 50);

    // Change contrast by factor of 1.5
    Contrast(&image, 1.5);

    // Write image to file
    WriteImage(&image, "output.pgm");

    // Exit program
    return 0;
}