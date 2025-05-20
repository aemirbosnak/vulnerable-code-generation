//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 80   // Maximum width for our ASCII art image
#define MAX_HEIGHT 80  // Maximum height for our ASCII art image
#define ASCII_RANGE 94 // Number of ASCII characters to choose from

// The characters we will use to represent different shades of gray
const char *GRAYSCALE_CHARACTERS = " .:-=+*#%@";

// Function to load an image from file
int loadImage(char *filename, int pixels[MAX_HEIGHT][MAX_WIDTH], int *width, int *height) {
    int x, y;
    char line[MAX_WIDTH + 1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return -1;
    }
    fgets(line, MAX_WIDTH + 1, fp);
    *width = strlen(line) - 1;
    x = 0;
    y = 0;
    while (fgets(line, MAX_WIDTH + 1, fp) != NULL) {
        for (x = 0; x < *width; x++) {
            if (line[x] == '\n') {
                // Ignore newline characters
                continue;
            } else if (isdigit(line[x])) {
                // Convert pixel value from ASCII to integer
                pixels[y][x] = line[x] - '0';
            } else {
                printf("Error: invalid character in %s at (%d,%d)\n", filename, y, x);
                return -1;
            }
        }
        y++;
        if (*height < y) {
            *height = y;
        }
    }
    fclose(fp);
    return 0;
}

// Function to convert a pixel value into a grayscale character
char grayscalePixel(int grayscaleValue) {
    int characterIndex = round(grayscaleValue / 255.0 * (ASCII_RANGE - 1));
    return GRAYSCALE_CHARACTERS[characterIndex];
}

// Function to convert an image to ASCII art and print it to the console
void convertImageToAscii(int pixels[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            putchar(grayscalePixel(pixels[y][x]));
        }
        putchar('\n');
    }
}

// Main function
int main(int argc, char *argv[]) {
    int pixels[MAX_HEIGHT][MAX_WIDTH];
    int width = 0;
    int height = 0;
    if (argc != 2) {
        printf("Usage: %s [image file]\n", argv[0]);
        return -1;
    }
    if (loadImage(argv[1], pixels, &width, &height) != 0) {
        printf("Error: could not load image %s\n", argv[1]);
        return -1;
    }
    convertImageToAscii(pixels, width, height);
    return 0;
}