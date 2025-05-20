//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Macros for image dimensions
#define WIDTH 50;
#define HEIGHT 50;

// Helper function to convert a pixel to its grayscale value
int get_pixel_value(int red, int green, int blue) {
    return 0.2126 * red + 0.7152 * green + 0.0722 * blue;
}

int main(int argc, char *argv[]) {
    // Check if there is a file argument
    if (argc < 2) {
        printf("Please provide a file name as an argument.\n");
        return 1;
    }

    // Load the image file
    FILE *file;
    file = fopen(argv[1], "rb");
    if (!file) {
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }

    // Read the image header (54 bytes)
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Get image dimensions from the header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Verify that the image is suitable for conversion
    if (header[0] != 'B' || header[1] != 'M' || *(int*)&header[10] != 54 || *(int*)&header[14] != 40) {
        printf("Unsupported image format.\n");
        return 1;
    }

    // Determine the padding needed to align each row to 4 bytes
    int padding = 0;
    if ((width * 3) % 4 > 0) {
        padding = 4 - ((width * 3) % 4);
    }

    // Allocate memory for the image and read it from the file
    unsigned char image[height][width * 3 + padding];
    fread(image, sizeof(unsigned char), (width * 3 + padding) * height, file);

    // Close the file
    fclose(file);

    // Print the ASCII art
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            // Get the grayscale value of the current pixel
            int value = get_pixel_value(image[y][x * 3 + 2], image[y][x * 3 + 1], image[y][x * 3]);

            // Choose the ASCII character based on the grayscale value
            char c = ' ';
            if (value > 200) {
                c = ' ';
            } else if (value > 150) {
                c = '.';
            } else if (value > 100) {
                c = '*';
            } else if (value > 50) {
                c = '+';
            } else if (value > 0) {
                c = '#';
            }

            // Print the character
            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}