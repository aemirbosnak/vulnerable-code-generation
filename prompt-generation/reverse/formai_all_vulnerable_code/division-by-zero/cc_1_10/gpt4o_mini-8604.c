//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WIDTH 70 // Width of the ASCII art
#define HEIGHT 50 // Height of the ASCII art
#define MAX_RGB_VALUE 255

// Function to get the brightness value from RGB components
float getBrightness(uint8_t r, uint8_t g, uint8_t b) {
    // Using perceived luminance
    return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

// Function to map brightness to ASCII characters
char getAsciiChar(float brightness) {
    const char *asciiChars = "@%#*+=-:. "; // ASCII characters sorted by perceived brightness
    int index = (int)(brightness / (MAX_RGB_VALUE / 10)); // Map the brightness to index
    if (index < 0) index = 0; // Ensure index does not go below 0
    if (index > 9) index = 9; // Ensure index does not exceed array bounds
    return asciiChars[index];
}

// Function to convert an image file to ASCII art
void convertToASCII(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open image file %s\n", filename);
        return;
    }

    // Skipping to the start of the pixel data for a simple BMP image reader
    fseek(file, 18, SEEK_SET);
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    fseek(file, 54, SEEK_SET); // Move to the pixel data

    // Process the image
    for (int y = height - 1; y >= 0; y -= height / HEIGHT) {
        for (int x = 0; x < width; x += width / WIDTH) {
            uint8_t r, g, b;
            fread(&b, sizeof(uint8_t), 1, file);
            fread(&g, sizeof(uint8_t), 1, file);
            fread(&r, sizeof(uint8_t), 1, file);
        
            float brightness = getBrightness(r, g, b);
            char asciiChar = getAsciiChar(brightness);

            // Determine how many pixels to skip
            if (x % (width / WIDTH) == 0) {
                printf("%c", asciiChar);
            }
        }
        printf("\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *imagePath = argv[1];
    convertToASCII(imagePath);

    return EXIT_SUCCESS;
}