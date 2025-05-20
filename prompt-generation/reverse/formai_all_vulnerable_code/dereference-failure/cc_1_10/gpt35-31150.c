//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// ASCII values to represent grayscale
static const char ascii_grayscale[] = {'#', 'M', 'X', 'H', 'G', 'F', 'T', 'I', 'r', '!', ':', ';', ',', '.', ' '};

// Function to read image file and return pixel matrix
int** readImage(char* fileName, int* width, int* height) {
    FILE* file;
    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Unable to open image file.\n");
        exit(1);
    }

    // Read image width and height
    char buffer[MAX_SIZE];

    fgets(buffer, MAX_SIZE, file);
    *width = atoi(buffer);

    fgets(buffer, MAX_SIZE, file);
    *height = atoi(buffer);

    // Allocate memory for pixel matrix
    int** pixels = (int**)malloc(sizeof(int*) * (*height));

    for (int i = 0; i < *height; i++) {
        pixels[i] = (int*)malloc(sizeof(int) * (*width));
    }

    // Read pixels from image file
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fgets(buffer, MAX_SIZE, file);
            pixels[i][j] = atoi(buffer);
        }
    }

    // Close file and return pixel matrix
    fclose(file);
    return pixels;
}

// Function to convert pixel matrix to ASCII art and print to console
void convertToAsciiArt(int** pixels, int width, int height) {
    // Calculate ratio to scale grayscale values to ASCII character range
    double ratio = (double)(sizeof(ascii_grayscale)-1) / 255;

    // Loop through pixels and convert to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int grayscaleValue = pixels[i][j];
            int asciiIndex = (int)(grayscaleValue * ratio);
            printf("%c ", ascii_grayscale[asciiIndex]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    // Check for proper usage
    if (argc != 2) {
        printf("Usage: ./ascii_converter <input_image>\n");
        return 1;
    }

    // Read image and print ASCII art
    int width, height;
    int** pixels = readImage(argv[1], &width, &height);
    convertToAsciiArt(pixels, width, height);

    // Free pixel matrix memory
    for (int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}