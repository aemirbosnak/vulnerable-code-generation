//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel_t;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input image file '%s'\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output image file '%s'\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    // Read the header of the input image file
    unsigned char header[54];
    fread(header, 54, 1, input_file);

    // Check if the input image file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Input image file '%s' is not a valid BMP file\n", argv[1]);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    // Get the width and height of the input image
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];

    // Read the pixel data from the input image file
    pixel_t *pixels = malloc(width * height * sizeof(pixel_t));
    fread(pixels, width * height * sizeof(pixel_t), 1, input_file);

    // Flip the image vertically
    for (unsigned int y = 0; y < height / 2; y++) {
        for (unsigned int x = 0; x < width; x++) {
            pixel_t temp = pixels[y * width + x];
            pixels[y * width + x] = pixels[(height - y - 1) * width + x];
            pixels[(height - y - 1) * width + x] = temp;
        }
    }

    // Write the header of the output image file
    fwrite(header, 54, 1, output_file);

    // Write the pixel data to the output image file
    fwrite(pixels, width * height * sizeof(pixel_t), 1, output_file);

    // Free the memory allocated for the pixel data
    free(pixels);

    // Close the input and output image files
    fclose(input_file);
    fclose(output_file);

    return 0;
}