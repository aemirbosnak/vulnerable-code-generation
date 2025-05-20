//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare character array for ASCII art
char ascii_chars[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.'};

int main(int argc, char *argv[]) {
    // Check if command line argument for filename is provided
    if (argc < 2) {
        printf("Please provide a filename\n");
        return 1;
    }

    // Open image file
    FILE *fp = fopen(argv[1], "rb");

    // Check if file could be opened
    if (!fp) {
        printf("Could not open file\n");
        return 1;
    }

    // Read header information
    int width, height, color_depth;
    fscanf(fp, "P6 %d %d %d", &width, &height, &color_depth);

    // Allocate memory for pixel data
    unsigned char *pixels = (unsigned char*)malloc(width * height * 3);

    // Read pixel data
    fread(pixels, 1, width * height * 3, fp);

    // Close file
    fclose(fp);

    // Iterate through each pixel and convert to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Calculate pixel index
            int index = (i * width + j) * 3;

            // Get pixel color values
            int r = pixels[index];
            int g = pixels[index + 1];
            int b = pixels[index + 2];

            // Calculate grayscale value
            int grayscale = (r + g + b) / 3;

            // Calculate ASCII character index
            int char_index = (grayscale * 10) / 255;

            // Print corresponding ASCII character
            printf("%c", ascii_chars[char_index]);
        }

        // Print new line character
        printf("\n");
    }

    // Free allocated memory
    free(pixels);

    return 0;
}