//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 2500 // maximum number of pixels in input image
#define MAX_WIDTH 50 // maximum width of output ASCII art
#define MAX_GRAYSCALE 255 // maximum grayscale value of input image
#define MAX_CHARACTERS 70 // maximum number of characters to use in output ASCII art

char characters[MAX_CHARACTERS] = {' ', '.', '\'', '`', ':', ';', 'c', 'o', 'x', 'k', 'X', 'K', '0', 'O', '8', '@'};

int getGrayScaleValue(char* pixel) {
    int r = pixel[0];
    int g = pixel[1];
    int b = pixel[2];
    return (0.2126 * r) + (0.7152 * g) + (0.0722 * b);
}

char getCharacter(int grayscale) {
    double interval = MAX_GRAYSCALE / MAX_CHARACTERS;

    for (int i = 0; i < MAX_CHARACTERS; i++) {
        double endValue = (i + 1) * interval;
        if (grayscale <= endValue) {
            return characters[i];
        }
    }

    return '@'; // in case something goes wrong
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input image> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* inputFilePath = argv[1];
    char* outputFilePath = argv[2];

    FILE* inputFile = fopen(inputFilePath, "rb");
    if (inputFile == NULL) {
        printf("Could not open input file: %s\n", inputFilePath);
        exit(EXIT_FAILURE);
    }

    fseek(inputFile, 0L, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);

    if (fileSize > MAX_PIXELS * 3) {
        printf("Input image is too large\n");
        exit(EXIT_FAILURE);
    }

    char pixels[MAX_PIXELS][3] = {0};
    int width = 0;
    int height = 0;
    int pixelCount = 0;

    while (1) {
        int r = fgetc(inputFile);
        int g = fgetc(inputFile);
        int b = fgetc(inputFile);

        if (r == EOF || g == EOF || b == EOF) {
            break;
        }

        pixels[pixelCount][0] = r;
        pixels[pixelCount][1] = g;
        pixels[pixelCount][2] = b;

        pixelCount++;

        if (pixelCount >= MAX_PIXELS) {
            break;
        }

        if (pixelCount % width == 0) {
            height++;
        }
    }

    width = pixelCount / height;

    if (width > MAX_WIDTH) {
        printf("Output width is too large\n");
        exit(EXIT_FAILURE);
    }

    FILE* outputFile = fopen(outputFilePath, "w");
    if (outputFile == NULL) {
        printf("Could not open output file: %s\n", outputFilePath);
        exit(EXIT_FAILURE);
    }

    int index = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int grayscale = getGrayScaleValue(pixels[index]);

            char character = getCharacter(grayscale);

            fprintf(outputFile, "%c", character);

            index++;
        }

        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}