//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// This function converts an RGB color to a grayscale intensity value
uint8_t rgbToGray(uint8_t r, uint8_t g, uint8_t b) {
    return (uint8_t)(0.2126*r + 0.7152*g + 0.0722*b);
}

// This function converts an grayscale intensity value to an ASCII symbol
char grayToAscii(uint8_t gray) {
    const char *asciiSymbols = " .,-:;i1tfLCG08@";
    const uint8_t numSymbols = 13;
    return asciiSymbols[(gray*numSymbols)/255];
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./img2ascii <image_path> <output_path>\n");
        return 1;
    }

    const char *imgPath = argv[1];
    const char *outPath = argv[2];

    FILE *imgFile = fopen(imgPath, "rb");
    if (!imgFile) {
        printf("Error: could not open image %s\n", imgPath);
        return 1;
    }

    // Get image dimensions
    fseek(imgFile, 18, SEEK_SET);
    int32_t imgWidth, imgHeight;
    fread(&imgWidth, 4, 1, imgFile);
    fread(&imgHeight, 4, 1, imgFile);

    // Move to image data
    fseek(imgFile, 54, SEEK_SET);

    // Allocate memory for image data
    uint8_t *imgData = (uint8_t*)malloc(imgWidth*imgHeight*3);
    if (!imgData) {
        printf("Error: could not allocate memory for image data\n");
        return 1;
    }

    // Read image data
    fread(imgData, 3, imgWidth*imgHeight, imgFile);

    // Close image file
    fclose(imgFile);

    // Allocate memory for ASCII art
    char *asciiArt = (char*)malloc(imgWidth*imgHeight);
    if (!asciiArt) {
        printf("Error: could not allocate memory for ASCII art\n");
        free(imgData);
        return 1;
    }

    // Convert image to ASCII art
    for (int32_t y = 0; y < imgHeight; y++) {
        for (int32_t x = 0; x < imgWidth; x++) {
            uint8_t r = imgData[(y*imgWidth+x)*3];
            uint8_t g = imgData[(y*imgWidth+x)*3+1];
            uint8_t b = imgData[(y*imgWidth+x)*3+2];
            uint8_t gray = rgbToGray(r, g, b);
            char asciiChar = grayToAscii(gray);
            asciiArt[y*imgWidth+x] = asciiChar;
        }
    }

    // Open output file
    FILE *outFile = fopen(outPath, "w");
    if (!outFile) {
        printf("Error: could not open output file %s\n", outPath);
        free(imgData);
        free(asciiArt);
        return 1;
    }

    // Write ASCII art to output file
    for (int32_t y = 0; y < imgHeight; y++) {
        for (int32_t x = 0; x < imgWidth; x++) {
            char asciiChar = asciiArt[y*imgWidth+x];
            fputc(asciiChar, outFile);
        }
        fputc('\n', outFile);
    }

    // Close output file
    fclose(outFile);

    // Free memory
    free(imgData);
    free(asciiArt);

    printf("ASCII art created successfully!\n");
    return 0;
}