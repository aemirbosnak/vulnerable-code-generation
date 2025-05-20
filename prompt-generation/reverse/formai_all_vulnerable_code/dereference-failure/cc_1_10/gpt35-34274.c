//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to convert the input image to ASCII art
void convertToASCII(char *imgName) {
    // Open the input image file in binary mode
    FILE *imgFile = fopen(imgName, "rb");

    if (imgFile == NULL) {
        printf("Error: Unable to open the input image file!");
        return;
    }

    // Get the width and height of the image
    fseek(imgFile, 18, SEEK_SET);
    int imgWidth = getc(imgFile);
    int imgHeight = getc(imgFile);

    // Allocate memory to store the image data
    unsigned char *imgData = (unsigned char*)malloc(imgWidth * imgHeight * 3 * sizeof(unsigned char));

    // Read the image data into memory
    fseek(imgFile, 54, SEEK_SET);
    fread(imgData, 3, imgWidth * imgHeight, imgFile);

    // Close the input image file
    fclose(imgFile);

    // Open the output ASCII art file
    FILE *asciiFile = fopen("output.txt", "w");

    if (asciiFile == NULL) {
        printf("Error: Unable to open the output file!");
        return;
    }

    // Table of ASCII characters from darkest to lightest
    // 67 total characters mapped onto 0-255 range
    char asciiTable[67] = {'@', '#', '8', '&', 'o', ':', '*', '.', ' '};

    // Convert the image data to ASCII art
    for (int i = 0; i < imgHeight; i++) {
        for (int j = 0; j < imgWidth; j++) {
            // Calculate the pixel position in the image data array
            int pos = ((i * imgWidth) + j) * 3;

            // Get the brightness of the pixel
            int brightness = (imgData[pos] + imgData[pos+1] + imgData[pos+2]) / 3;

            // Map the brightness to an ASCII character
            int index = brightness / 4;
            char asciiChar = asciiTable[index];

            // Write the ASCII character to the output file
            fputc(asciiChar, asciiFile);
        }

        // Write a newline character after each row of ASCII characters
        fputc('\n', asciiFile);
    }

    // Close the output ASCII art file
    fclose(asciiFile);

    // Free the image data memory
    free(imgData);

    printf("Successfully converted %s to ASCII art!", imgName);
}

int main() {
    convertToASCII("input.bmp");

    return 0;
}