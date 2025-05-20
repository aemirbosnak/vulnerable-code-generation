//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for ASCII art
#define ROWS 10
#define COLS 60

// Define characters for ASCII art
char chars[] = {'@', '#', '$', '%', '*', '+', '-', '.', ' '};

// Method to get ASCII character based on pixel value
char getChar(int pixelValue, int charCount) {
    int step = 255 / (charCount - 1);
    int index = pixelValue / step;
    return chars[index];
}

// Method to print ASCII art
void printAsciiArt(unsigned char *pixelData, int pixelDataSize, int charCount) {
    // Create output buffer for ASCII art
    char asciiArt[ROWS][COLS];

    // Clear output buffer
    memset(asciiArt, 0, ROWS * COLS);

    // Iterate through pixel data and set output buffer accordingly
    for (int i = 0; i < pixelDataSize; i += 3) {
        int row = (i / 3) / COLS;
        int col = (i / 3) % COLS;
        int pixelValue = (pixelData[i] + pixelData[i + 1] + pixelData[i + 2]) / 3;
        asciiArt[row][col] = getChar(pixelValue, charCount);
    }

    // Print output buffer
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Read image data from file
    FILE *imageFile = fopen("image.rgb", "rb");
    if (imageFile == NULL) {
        printf("Unable to open file!\n");
        return 1;
    }
    int pixelDataSize = ROWS * COLS * 3;
    unsigned char *pixelData = malloc(pixelDataSize);
    fread(pixelData, 1, pixelDataSize, imageFile);
    fclose(imageFile);

    // Generate ASCII art from pixel data
    printAsciiArt(pixelData, pixelDataSize, sizeof(chars) / sizeof(chars[0]));

    return 0;
}