//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80
#define MAX_PIXEL_VALUE 255

void pixelToAscii(int ,int ,int ,char** ,char*);
void imageToAscii(char* ,char**);
void writeFile(char* ,char**);

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Incorrect number of parameters!\n");
        printf("Usage: ./convert input.ppm output.txt\n");
        exit(1);
    }
    char* inputFile = argv[1];
    char* outputFile = argv[2];

    // Open ppm file
    FILE* file = fopen(inputFile, "r");
    if (file == NULL) {
        printf("Could not open file!\n");
        exit(1);
    }

    // Read ppm file header and dimensions
    char buffer[200];
    fgets(buffer, 200, file);
    if (buffer[0] != 'P' || buffer[1] != '3') {
        printf("This is not a P3 ppm file!\n");
        exit(1);
    }
    int width, height, maxPixelValue;
    fscanf(file, "%d%d%d", &width, &height, &maxPixelValue);

    // Allocate memory for 2D char array
    char** asciiImg = (char**) malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        asciiImg[i] = (char*) malloc((width+1) * sizeof(char));
    }

    // Convert ppm image to ASCII art
    imageToAscii(inputFile, asciiImg);

    // Write ASCII art to output file
    writeFile(outputFile, asciiImg);

    // Free memory for 2D char array
    for (int i = 0; i < height; i++) {
        free(asciiImg[i]);
    }
    free(asciiImg);

    // Close the ppm file
    fclose(file);
    return 0;
}

// Function to convert a RGB pixel value to ASCII char
void pixelToAscii(int red, int green, int blue, char** asciiImg, char* asciiChars) {
    int maxChar = strlen(asciiChars) - 1;
    int grayscale = 0.2126 * red + 0.7152 * green + 0.0722 * blue;
    int charIdx = (int)(grayscale / ((float)MAX_PIXEL_VALUE / maxChar));
    asciiImg[0][0] = asciiChars[maxChar - charIdx];
}

// Function to convert ppm image to ASCII art
void imageToAscii(char* filename, char** asciiImg) {
    char asciiChars[] = "@#S%=+^*. ";
    int maxChar = strlen(asciiChars) - 1;

    // Open ppm file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file!\n");
        exit(1);
    }

    // Read ppm image pixel values
    char buffer[200];
    fgets(buffer, 200, file);
    fgets(buffer, 200, file);
    fgets(buffer, 200, file);
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            int red, green, blue;
            fscanf(file, "%d%d%d", &red, &green, &blue);
            pixelToAscii(red, green, blue, asciiImg, asciiChars);
            asciiImg[i][j] = asciiImg[0][0];
        }
    }

    // Close ppm file
    fclose(file);
}

// Function to write ASCII art to output file
void writeFile(char* filename, char** asciiImg) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file!\n");
        exit(1);
    }
    int height = MAX_HEIGHT;
    int width = MAX_WIDTH;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fputc(asciiImg[i][j], file);
        }
        fputc('\n', file);
    }
    fclose(file);
}