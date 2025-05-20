//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the width and height of the image
#define WIDTH 50
#define HEIGHT 50

// Define the maximum number of characters in the ASCII art
#define MAX_CHARACTERS 2000

// Function to convert a pixel to ASCII character
char pixelToChar(int pixel) {
    // Define a set of ASCII characters for different brightness levels
    char chars[] = {'#', 'M', 'X', 'W', 'u', 'w', ':', '.', ' '};
    
    // Calculate the brightness level of the pixel
    int brightness = (pixel >> 16 & 0xFF) * 0.3 + (pixel >> 8 & 0xFF) * 0.59 + (pixel & 0xFF) * 0.11;
    
    // Scale the brightness level to fit within the range of available characters
    int index = (int)(brightness / 25.5);
    
    // Return the corresponding ASCII character
    return chars[index];
}

int main() {
    // Load the input image from file
    FILE *inputFile = fopen("input.bmp", "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    
    // Read the BMP file header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, inputFile);
    
    // Extract the image width, height, and color depth from the header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int colorDepth = *(int*)&header[28];
    
    // Check if the input image is valid for conversion
    if (width != WIDTH || height != HEIGHT || colorDepth != 24) {
        printf("Error: Input image is not compatible with this program.\n");
        fclose(inputFile);
        return 1;
    }
    
    // Allocate memory for the input and output images
    unsigned char *inputImage = (unsigned char*)malloc(width * height * 3);
    char *asciiArt = (char*)malloc(MAX_CHARACTERS);
    
    // Read the input image data from file
    fread(inputImage, sizeof(unsigned char), width * height * 3, inputFile);
    
    // Close the input file
    fclose(inputFile);
    
    // Loop over each pixel in the image and convert it to ASCII character
    int index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = (inputImage[(i * width + j) * 3] << 16) +
                        (inputImage[(i * width + j) * 3 + 1] << 8) +
                        (inputImage[(i * width + j) * 3 + 2]);
            char asciiChar = pixelToChar(pixel);
            asciiArt[index++] = asciiChar;
        }
        asciiArt[index++] = '\n';
    }
    
    // Print the ASCII art to console
    printf("%s", asciiArt);
    
    // Write the ASCII art to file
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }
    fwrite(asciiArt, sizeof(char), strlen(asciiArt), outputFile);
    fclose(outputFile);
    
    // Free the allocated memory
    free(inputImage);
    free(asciiArt);
    
    return 0;
}