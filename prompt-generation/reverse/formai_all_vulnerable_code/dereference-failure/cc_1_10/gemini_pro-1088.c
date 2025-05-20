//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main() {
    // Open the input image
    FILE *input = fopen("input.ppm", "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input image\n");
        return 1;
    }

    // Read the image header
    char header[100];
    fscanf(input, "%s", header);
    if (strcmp(header, "P3") != 0) {
        fprintf(stderr, "Error: input image is not a PPM file\n");
        return 1;
    }
    int width, height;
    fscanf(input, "%d %d", &width, &height);
    int maxval;
    fscanf(input, "%d", &maxval);

    // Allocate memory for the image data
    pixel *image = malloc(sizeof(pixel) * width * height);
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        return 1;
    }

    // Read the image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(input, "%hhu %hhu %hhu", &image[i * width + j].red, &image[i * width + j].green, &image[i * width + j].blue);
        }
    }

    // Close the input image
    fclose(input);

    // Open the output image
    FILE *output = fopen("output.ppm", "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output image\n");
        return 1;
    }

    // Write the image header
    fprintf(output, "P3\n");
    fprintf(output, "%d %d\n", width, height);
    fprintf(output, "%d\n", maxval);

    // Write the image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(output, "%hhu %hhu %hhu ", image[i * width + j].red, image[i * width + j].green, image[i * width + j].blue);
        }
    }

    // Close the output image
    fclose(output);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}