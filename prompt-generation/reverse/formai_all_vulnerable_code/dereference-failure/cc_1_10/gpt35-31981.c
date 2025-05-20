//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Function to convert C image to ASCII art
void convertToAsciiArt(char image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    // Define ASCII characters with different intensity level
    char asciiChars[] = {' ', '.', '+', '*', 'X', '#', '%', '@'};

    // Calculate the intensity of each pixel and map it to a corresponding ASCII character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int intensity = (int) image[i][j] * 7 / 255;
            printf("%c", asciiChars[intensity]);
        }
        printf("\n");
    }
}

int main() {
    // Read the C image file
    FILE *fp;
    fp = fopen("image.bin", "rb");
    if (!fp) {
        printf("Error: Unable to open C image file.\n");
        return 1;
    }

    // Read the image dimensions
    int width, height;
    if (fread(&width, sizeof(int), 1, fp) != 1 || fread(&height, sizeof(int), 1, fp) != 1) {
        printf("Error: Unable to read image dimensions.\n");
        return 1;
    }

    // Allocate memory for the image pixels
    char image[MAX_HEIGHT][MAX_WIDTH];
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image dimensions too large.\n");
        return 1;
    }

    // Read the image pixels
    if (fread(image, sizeof(char), width * height, fp) != width * height) {
        printf("Error: Unable to read image pixels.\n");
        return 1;
    }

    // Close the file
    fclose(fp);

    // Convert the C image to ASCII art
    convertToAsciiArt(image, width, height);

    return 0;
}