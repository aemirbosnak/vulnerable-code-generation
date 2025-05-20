//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The characters we will use for the output
const char *ASCII_CHARS = " .:-=+*#%@";

// Length of the characters string
const int CHARS_LENGTH = 10;

// Function to calculate the average pixel value of an image region
int getAveragePixelValue(unsigned char *image, int width, int startX, int endX, int startY, int endY) {
    int pixelTotal = 0;

    for (int y = startY; y < endY; y++) {
        for (int x = startX; x < endX; x++) {
            unsigned char pixelValue = image[(y * width) + x];
            pixelTotal += pixelValue;
        }
    }

    int pixelCount = (endX - startX) * (endY - startY);
    int averagePixelValue = pixelTotal / pixelCount;

    return averagePixelValue;
}

// Function to convert an image to ASCII art
void imageToAscii(unsigned char *image, int width, int height) {
    // Determine the size of each ASCII character block
    int blockWidth = width / CHARS_LENGTH;
    int blockHeight = blockWidth * 2;

    // Loop over each block and calculate the average pixel value
    for (int y = 0; y < height; y += blockHeight) {
        for (int x = 0; x < width; x += blockWidth) {
            // Calculate the start and end coordinates of this block
            int startX = x;
            int endX = x + blockWidth;
            int startY = y;
            int endY = y + blockHeight;

            // Handle edge case for block sizes that do not divide evenly into the image size
            if (endX > width) {
                endX = width;
            }

            if (endY > height) {
                endY = height;
            }

            // Calculate the average pixel value of this block
            int averagePixelValue = getAveragePixelValue(image, width, startX, endX, startY, endY);

            // Determine the index of the ASCII character to use based on the average pixel value
            int charIndex = ((averagePixelValue * (CHARS_LENGTH - 1)) / 255);

            // Output the appropriate ASCII character
            putchar(ASCII_CHARS[charIndex]);
        }

        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    // Open the input file
    FILE *inputFile = fopen(argv[1], "rb");

    if (inputFile == NULL) {
        printf("Cannot open file '%s'\n", argv[1]);
        return 1;
    }

    // Determine the size of the file
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    // Read the file contents into a buffer
    unsigned char *fileBuffer = (unsigned char*) malloc(fileSize);
    fread(fileBuffer, 1, fileSize, inputFile);

    // Close the input file
    fclose(inputFile);

    int width = fileBuffer[18] + (fileBuffer[19] << 8);
    int height = fileBuffer[22] + (fileBuffer[23] << 8);

    // Parse the image data
    unsigned char *imageData = fileBuffer + fileBuffer[10];

    // Convert the image to ASCII art
    imageToAscii(imageData, width, height);

    // Free the file buffer
    free(fileBuffer);

    return 0;
}