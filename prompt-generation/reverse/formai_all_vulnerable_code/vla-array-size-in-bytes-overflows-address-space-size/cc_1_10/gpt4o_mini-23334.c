//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100 // Maximum width of the output ASCII art
#define MAX_HEIGHT 100 // Maximum height of the output ASCII art
#define ASCII_CHARS "@%#*+=-:. " // Characters used for ASCII art

// Function to calculate the brightness value (grayscale) of a pixel
float calculateBrightness(unsigned char r, unsigned char g, unsigned char b) {
    return (0.3 * r + 0.59 * g + 0.11 * b);
}

// Function to map brightness to ASCII character
char mapBrightnessToAscii(float brightness) {
    int index = (int)(brightness * (strlen(ASCII_CHARS) - 1) / 255);
    return ASCII_CHARS[index];
}

// Function to convert image to ASCII art
void convertImageToAscii(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }
    
    // Simple representation for image loading (assuming 24-bit BMP format here for simplicity)
    fseek(file, 18, SEEK_SET);
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    
    // Check dimensions
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Image dimensions exceed maximum allowed (width: %d, height: %d)\n", MAX_WIDTH, MAX_HEIGHT);
        fclose(file);
        return;
    }
    
    fseek(file, 54, SEEK_SET); // Skip to pixel array
    
    unsigned char bitmap[height][width][3];
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            fread(bitmap[y][x], sizeof(unsigned char), 3, file);
        }
    }
    
    fclose(file);
    
    // Convert to ASCII
    for (int y = 0; y < height; y += height / MAX_HEIGHT) {
        for (int x = 0; x < width; x += width / MAX_WIDTH) {
            unsigned char r = bitmap[y][x][2];
            unsigned char g = bitmap[y][x][1];
            unsigned char b = bitmap[y][x][0];
            float brightness = calculateBrightness(r, g, b);
            char asciiChar = mapBrightnessToAscii(brightness);
            putchar(asciiChar);
        }
        putchar('\n'); // Newline after each row of ASCII characters
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image-file.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *imageFilename = argv[1];
    convertImageToAscii(imageFilename);

    return EXIT_SUCCESS;
}