//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 60

// The characters to use for different brightness levels
const char CHARACTERS[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// The number of characters to choose from
const int NUM_CHARACTERS = sizeof(CHARACTERS) / sizeof(char);

// The brightness level to character mapping function
char getCharForBrightness(int brightness, int style) {
    int mappedBrightness = (brightness * NUM_CHARACTERS) / 255;
    return CHARACTERS[mappedBrightness];
}

int main(int argc, char **argv) {
    // Load the input binary image file
    FILE *inputFile = fopen("input.bin", "rb");
    if (!inputFile) {
        printf("Error: Unable to open input file.\n");
        return -1;
    }

    // Determine the width and height of the image
    int width = WIDTH, height = HEIGHT;
    if (argc > 1) {
        width = atoi(argv[1]);
        if (argc > 2) {
            height = atoi(argv[2]);
        }
    }

    // Create the output ASCII art image
    char asciiArt[height][width + 1];

    // Read the binary input image data and convert it to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Read the next byte from the input file
            unsigned char pixelBrightness;
            if (fread(&pixelBrightness, sizeof(unsigned char), 1, inputFile) != 1) {
                printf("Error: Input file is not correct size.\n");
                return -1;
            }

            // Map the brightness to a character and store it in the output buffer
            asciiArt[y][x] = getCharForBrightness(pixelBrightness, 0);
        }
        asciiArt[y][width] = '\0';
    }

    // Close the input file
    fclose(inputFile);

    // Output the ASCII art image to the console
    for (int y = 0; y < height; y++) {
        printf("%s\n", asciiArt[y]);
    }

    return 0;
}