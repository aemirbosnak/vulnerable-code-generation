//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// ASCII characters for different shades of gray
char *ascii_chars[] = {" ", ".", ":", "-", "=", "+", "*", "#", "%", "@"};

// Convert RGB values to grayscale
int get_grayscale(uint8_t r, uint8_t g, uint8_t b) {
    return (r * 0.2126 + g * 0.7152 + b * 0.0722);
}

int main(int argc, char **argv) {
    // Open image file
    FILE *infile = fopen(argv[1], "rb");
    if (!infile) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Read image header
    char magic[2];
    int width, height, maxval;
    fscanf(infile, "%2s\n%d %d\n%d\n", magic, &width, &height, &maxval);

    // Check if image is valid
    if (magic[0] != 'P' || magic[1] != '6') {
        fprintf(stderr, "Invalid image format: %s\n", argv[1]);
        fclose(infile);
        return 1;
    }

    // Allocate memory for image data
    uint8_t *data = (uint8_t *)malloc(width * height * 3 * sizeof(uint8_t));
    if (!data) {
        fprintf(stderr, "Error allocating memory\n");
        fclose(infile);
        return 1;
    }

    // Read image data
    fread(data, sizeof(uint8_t), width * height * 3, infile);

    // Close image file
    fclose(infile);

    // Convert image to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Compute grayscale value
            int gray = get_grayscale(data[(y * width + x) * 3],
                                      data[(y * width + x) * 3 + 1],
                                      data[(y * width + x) * 3 + 2]);

            // Map grayscale value to ASCII character
            int index = gray * 10 / 255;
            printf("%s", ascii_chars[index]);
        }
        printf("\n");
    }

    // Free memory
    free(data);

    return 0;
}