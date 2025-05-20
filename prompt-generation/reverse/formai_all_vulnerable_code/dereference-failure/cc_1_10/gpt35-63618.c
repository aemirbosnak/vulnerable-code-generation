//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
/*
Image to ASCII Art Converter Program
Author: AI Bot
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 80
#define HEIGHT 60

// Function to convert RGB to grayscale
uint8_t rgb2gray(uint8_t r, uint8_t g, uint8_t b) {
    return (uint8_t) (0.21*r + 0.71*g + 0.07*b);
}

// Function to convert image to ASCII art
void imageToAscii(uint8_t *image, int width, int height) {

    // Define the characters and their corresponding grayscale values
    char asciiChars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int charCount = sizeof(asciiChars) / sizeof(char);

    // Scale the grayscale values to fit the ASCII characters
    float scale = 255.0 / (float) (charCount - 1);

    // Loop through each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            // Get the RGB values of the current pixel
            uint8_t r = image[(y * width + x) * 3];
            uint8_t g = image[(y * width + x) * 3 + 1];
            uint8_t b = image[(y * width + x) * 3 + 2];

            // Convert RGB to grayscale
            uint8_t gray = rgb2gray(r, g, b);

            // Scale the grayscale value to fit the ASCII characters
            int index = (int) (gray / scale);

            // Print the corresponding ASCII character
            printf("%c", asciiChars[index]);
        }

        // Add line break between rows
        printf("\n");
    }
}

// Main program
int main(int argc, char **argv) {

    // Open the image file
    FILE *fp = fopen("image.rgb", "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file.\n");
        return -1;
    }

    // Read the image data
    uint8_t *image = (uint8_t *) malloc(WIDTH * HEIGHT * 3);
    fread(image, 1, WIDTH * HEIGHT * 3, fp);

    // Close the image file
    fclose(fp);

    // Convert the image to ASCII art
    imageToAscii(image, WIDTH, HEIGHT);

    // Free the image data memory
    free(image);

    return 0;
}