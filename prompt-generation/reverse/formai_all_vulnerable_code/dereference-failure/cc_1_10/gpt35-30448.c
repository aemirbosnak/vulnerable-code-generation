//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define image width and height
#define WIDTH 100
#define HEIGHT 100

// Define ASCII character set size
#define CHAR_SET_SIZE 11

// Define ASCII character set
char charSet[CHAR_SET_SIZE] = {' ', '.', '\'', ':', 'o', '&', '8', '#', '@', 'O', 'M'};

// Recursive function to convert image pixels to ASCII characters
void imageToAscii(char **asciiImage, int *imagePixels, int width, int height, int charIndex) {
    // Base case: if image width or height is less than 1, return
    if (width < 1 || height < 1) {
        return;
    }
    
    // Calculate average pixel value for current block
    int numPixels = width * height;
    int pixelSum = 0;
    for (int i = 0; i < numPixels; i++) {
        pixelSum += imagePixels[i];
    }
    int pixelAvg = pixelSum / numPixels;

    // Find corresponding ASCII character for pixel average value
    int charSize = CHAR_SET_SIZE - 1;
    char charValue = charSet[(int)((float)pixelAvg / 255 * charSize)];

    // Fill ASCII character block with corresponding character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            asciiImage[i][j] = charValue;
        }
    }

    // Divide image into 4 sub-blocks and recursively call function on each sub-block
    int newWidth = width / 2;
    int newHeight = height / 2;
    imageToAscii(asciiImage, imagePixels, newWidth, newHeight, charIndex + 1);
    imageToAscii(asciiImage + newHeight, imagePixels + newWidth, newWidth, newHeight, charIndex + 1);
    imageToAscii(asciiImage + newHeight * 2, imagePixels + newWidth * height, newWidth, newHeight, charIndex + 1);
    imageToAscii(asciiImage + newHeight, imagePixels + newHeight * width + newWidth, newWidth, newHeight, charIndex + 1);
}

int main() {
    // Initialize image pixel array
    int *imagePixels = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        imagePixels[i] = rand() % 256;
    }

    // Initialize ASCII image array
    char **asciiImage = (char **)malloc(HEIGHT * sizeof(char *));
    for (int i = 0; i < HEIGHT; i++) {
        asciiImage[i] = (char *)malloc(WIDTH * sizeof(char));
    }

    // Convert image pixels to ASCII characters recursively
    imageToAscii(asciiImage, imagePixels, WIDTH, HEIGHT, 0);

    // Print ASCII image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", asciiImage[i][j]);
        }
        printf("\n");
    }

    // Free memory
    free(imagePixels);
    for (int i = 0; i < HEIGHT; i++) {
        free(asciiImage[i]);
    }
    free(asciiImage);

    return 0;
}