//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_ASCII_VALUES 90
#define CHAR_INDEX_OFFSET 32
#define ASPECT_RATIO 0.5

typedef struct {
    unsigned char r, g, b;
} RGB;

// Function prototypes
RGB** readImage(char* filename, int* width, int* height);
void freeImage(RGB** image, int height);
void imageToGrayscale(RGB** image, int width, int height);
void normalizeImage(RGB** image, int width, int height);
void printASCII(RGB** image, int width, int height);
void convertToASCII(RGB** image, int width, int height, char asciiValues[MAX_ASCII_VALUES], char asciiArt[MAX_HEIGHT][MAX_WIDTH]);

int main(int argc, char* argv[]) {
    char* filename;
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    } else {
        filename = argv[1];
    }

    int width, height;
    RGB** image = readImage(filename, &width, &height);

    imageToGrayscale(image, width, height);
    normalizeImage(image, width, height);

    printASCII(image, width, height);

    freeImage(image, height);

    return 0;
}

// Read in an image file
RGB** readImage(char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    // Read in the header (first line) of the image file
    char header[3];
    fgets(header, 3, file);

    // Check if the file format is P3
    if (strcmp(header, "P3") != 0) {
        printf("Error: File '%s' is not in P3 format\n", filename);
        exit(1);
    }

    // Get the width and height of the image
    fscanf(file, "%d %d\n", width, height);

    // Check that the width and height are within the supported range
    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
        printf("Error: Image size is too large. Maximum height = %d, Maximum width = %d\n", MAX_HEIGHT, MAX_WIDTH);
        exit(1);
    }

    // Get the maximum value of an RGB element
    int maxVal;
    fscanf(file, "%d\n", &maxVal);

    // Allocate memory for the image
    RGB** image = (RGB**) malloc(*height * sizeof(RGB*));
    for (int i = 0; i < *height; i++) {
        image[i] = (RGB*) malloc(*width * sizeof(RGB));
    }

    // Read in each RGB value for each pixel in the image
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            int r, g, b;
            fscanf(file, "%d %d %d", &r, &g, &b);

            image[i][j].r = (unsigned char) r;
            image[i][j].g = (unsigned char) g;
            image[i][j].b = (unsigned char) b;
        }
    }

    fclose(file);

    return image;
}

// Free the memory allocated for an image
void freeImage(RGB** image, int height) {
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }

    free(image);
}

// Convert the image to grayscale
void imageToGrayscale(RGB** image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char r = image[i][j].r;
            unsigned char g = image[i][j].g;
            unsigned char b = image[i][j].b;

            unsigned char gray = (unsigned char) (0.2126 * r + 0.7152 * g + 0.0722 * b);

            image[i][j].r = gray;
            image[i][j].g = gray;
            image[i][j].b = gray;
        }
    }
}

// Normalize the image
void normalizeImage(RGB** image, int width, int height) {
    int max = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = image[i][j].r;

            if (r > max) {
                max = r;
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = image[i][j].r;
            image[i][j].r = (unsigned char) round(r * (ASPECT_RATIO * MAX_ASCII_VALUES - 1) / (max + 1));
        }
    }
}

// Print the ASCII art to the console
void printASCII(RGB** image, int width, int height) {
    char asciiValues[MAX_ASCII_VALUES] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@',
                                          'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                                          'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                                          'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
                                          '4', '5', '6', '7', '8', '9', '(', ')', '{', '}'
                                          };

    char asciiArt[MAX_HEIGHT][MAX_WIDTH];

    convertToASCII(image, width, height, asciiValues, asciiArt);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }
}

// Convert the grayscale image to ASCII art
void convertToASCII(RGB** image, int width, int height, char asciiValues[MAX_ASCII_VALUES], char asciiArt[MAX_HEIGHT][MAX_WIDTH]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int idx = image[i][j].r + CHAR_INDEX_OFFSET;
            asciiArt[i][j] = asciiValues[idx];
        }
    }
}