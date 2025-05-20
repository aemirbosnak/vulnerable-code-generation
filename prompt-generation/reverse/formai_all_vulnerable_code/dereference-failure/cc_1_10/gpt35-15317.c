//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_WIDTH 80 // Width of ASCII output
#define ASCII_HEIGHT 40 // Height of ASCII output
#define GRAYSCALE_SCALE 10 // Scale for converting grayscale to ASCII
#define MAX_FILENAME_LENGTH 256 // Maximum length of file name 

// Function that converts an image to ASCII art
void image_to_ascii(char* filename) {
    // Open the image file
    FILE* fp;
    fp = fopen(filename, "rb");

    // Check if the file exists
    if(fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }

    // Read the header of the image file
    char type[3]; // Type of image (PBM/PGM/PPM)
    int width; // Width of image
    int height; // Height of image
    int maxval; // Maximum pixel value
    fscanf(fp, "%s\n%d %d\n%d\n", type, &width, &height, &maxval);

    // Allocate memory for pixel data
    unsigned char* pixels;
    pixels = (unsigned char*) malloc(sizeof(unsigned char) * width * height);

    // Read pixel data from file
    fread(pixels, sizeof(unsigned char), width * height, fp); 

    // Close the image file
    fclose(fp);

    // Prepare ASCII art data
    char ascii[ASCII_HEIGHT][ASCII_WIDTH + 1]; // ASCII art data
    memset(ascii, ' ', ASCII_HEIGHT * (ASCII_WIDTH + 1)); // Fill with spaces

    // Convert pixel data to ASCII art
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            // Get the grayscale value of the pixel
            int grayscale = pixels[row * width + col];

            // Convert grayscale value to ASCII character
            int index = (grayscale * GRAYSCALE_SCALE) / (maxval + 1);
            char ascii_char = " .:-=+*#%@"[index];

            // Add ASCII character to ASCII art data
            int ascii_row = (row * ASCII_HEIGHT) / height; 
            int ascii_col = (col * ASCII_WIDTH) / width;
            ascii[ascii_row][ascii_col] = ascii_char;
        }
    }

    // Print the ASCII art to the console
    for(int row = 0; row < ASCII_HEIGHT; row++) {
        printf("%s\n", ascii[row]);
    }

    // Free memory
    free(pixels);
}

int main() {
    // Get the name of the image file from the user
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    // Convert the image to ASCII art
    image_to_ascii(filename);

    return 0;
}