//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define MAX_PIXEL_VALUE 255

char asciiChars[] = {' ', '.', '*', ':', 'o', '&', '8', '#', '@'};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./imageToAscii <input_file> <output_file>\n");
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        printf("Error: Could not open input file: %s\n", argv[1]);
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        printf("Error: Could not open output file: %s\n", argv[2]);
        return 1;
    }

    char header[100];
    fgets(header, sizeof(header), inputFile);
    if (strcmp(header, "P5\n") != 0) {
        printf("Error: Only binary PGM files are supported\n");
        return 1;
    }

    int width = 0, height = 0, maxPixelValue = 0;
    fscanf(inputFile, "%d %d\n%d\n", &width, &height, &maxPixelValue);
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image is too large\n");
        return 1;
    }

    unsigned char imageData[MAX_HEIGHT][MAX_WIDTH];
    fread(imageData, 1, width * height, inputFile);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int pixelValue = (int)imageData[i][j];
            int asciiIndex = pixelValue * (sizeof(asciiChars) / sizeof(char)) / MAX_PIXEL_VALUE;
            fputc(asciiChars[asciiIndex], outputFile);
        }
        fputc('\n', outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Image converted successfully from PGM to ASCII art\n");
    return 0;
}