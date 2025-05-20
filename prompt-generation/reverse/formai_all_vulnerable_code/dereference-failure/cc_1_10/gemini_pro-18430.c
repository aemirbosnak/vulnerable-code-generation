//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main() {
    // Open the input image
    FILE *input = fopen("input.bmp", "rb");
    if (!input) {
        perror("Error opening input image");
        return 1;
    }

    // Read the BMP header
    unsigned char header[54];
    fread(header, sizeof(header), 1, input);

    // Check if the file is a valid BMP
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Invalid BMP file\n");
        return 1;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the pixel data
    unsigned char *data = malloc(width * height * sizeof(pixel));
    fread(data, sizeof(pixel), width * height, input);
    fclose(input);

    // Create the output image
    FILE *output = fopen("output.bmp", "wb");
    if (!output) {
        perror("Error opening output image");
        return 1;
    }

    // Write the BMP header
    fwrite(header, sizeof(header), 1, output);

    // Write the pixel data
    fwrite(data, sizeof(pixel), width * height, output);
    fclose(output);

    // Free the memory
    free(data);

    return 0;
}