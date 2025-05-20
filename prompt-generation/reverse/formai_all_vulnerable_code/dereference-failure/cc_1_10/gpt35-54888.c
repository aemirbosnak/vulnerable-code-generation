//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Change these values to adjust the size of the output
#define OUTPUT_WIDTH 80
#define OUTPUT_HEIGHT 50

// Change these values to adjust the character set used for the ASCII art
#define CHAR_SET_SIZE 10
const char charSet[CHAR_SET_SIZE] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// Function to convert an image to ASCII art
void convertImageToASCII(char *inputFile, char *outputFile){

    // Open the input file
    FILE *input = fopen(inputFile, "rb");

    // Get the size of the input file
    fseek(input, 0L, SEEK_END);
    long fileSize = ftell(input);
    rewind(input);

    // Allocate memory for the image data
    unsigned char *imageData = (unsigned char*) malloc(sizeof(unsigned char) * fileSize);

    // Read the image data from the input file
    fread(imageData, sizeof(unsigned char), fileSize, input);

    // Close the input file
    fclose(input);

    // Open the output file for writing
    FILE *output = fopen(outputFile, "w");

    // Convert the image to ASCII art
    for (int y = 0; y < OUTPUT_HEIGHT; y++){
        for (int x = 0; x < OUTPUT_WIDTH; x++){

            // Calculate the position in the image data
            int pixelX = x * (fileSize / OUTPUT_WIDTH);
            int pixelY = y * (fileSize / OUTPUT_HEIGHT);

            // Get the brightness of the pixel
            unsigned char pixelValue = imageData[pixelY * (OUTPUT_WIDTH * (fileSize / OUTPUT_WIDTH)) + pixelX];

            // Calculate the index in the character set based on the brightness
            int charIndex = (int) (pixelValue / 255.0 * (CHAR_SET_SIZE - 1));

            // Write the corresponding character to the output file
            fputc(charSet[charIndex], output);
        }

        // Write a newline character after each row
        fputc('\n', output);
    }

    // Close the output file
    fclose(output);

    // Free the memory used for the image data
    free(imageData);
}

int main(int argc, char **argv){

    // Check that the input and output file names were provided
    if (argc != 3){
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    // Convert the image to ASCII art
    convertImageToASCII(argv[1], argv[2]);

    printf("Image conversion complete!\n");

    return 0;
}