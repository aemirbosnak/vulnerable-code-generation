//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to map pixel values to ASCII characters
char getChar(int pixelVal, int maxVal) {
    const char pixelToCharMap[] = {'@', '#', 'O', 'o', '+', ':', '.', ' '};
    int numPixels = sizeof(pixelToCharMap)/sizeof(char);
    int pixelStep = ceil(maxVal/numPixels);
    
    for (int i = 0; i < numPixels; i++) {
        if (pixelVal <= (i+1)*pixelStep) {
            return pixelToCharMap[i];
        }
    }

    // If pixel value is greater than maximum value, return last character in map
    return pixelToCharMap[numPixels - 1];
}

int main(int argc, char** argv) {

    // Check if filename has been provided as argument
    if (argc != 2) {
        printf("Please provide filename as argument!\n");
        exit(EXIT_FAILURE);
    }

    // Open image file
    FILE* imgFile = fopen(argv[1], "rb");

    if (!imgFile) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    // Read image metadata
    char magicNum[2];
    int width, height, maxVal;
    fscanf(imgFile, "%2s\n%d %d\n%d\n", magicNum, &width, &height, &maxVal);

    // Check if image is PGM format
    if (magicNum[0] != 'P' || magicNum[1] != '5') {
        printf("File format not supported!\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for pixel values
    unsigned char* pixelVals = (unsigned char*) malloc(sizeof(unsigned char)*width*height);

    if (!pixelVals) {
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }

    // Read pixel values from image file
    fread(pixelVals, sizeof(unsigned char), width*height, imgFile);

    // Close image file
    fclose(imgFile);

    // Print ASCII art
    printf("ASCII Art:\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char pixelChar = getChar(pixelVals[i*width + j], maxVal);
            printf("%c", pixelChar);
        }
        printf("\n");
    }

    // Free memory
    free(pixelVals);

    return 0;
}