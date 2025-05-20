//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the ASCII art image
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the characters to use for the ASCII art
const char *ASCII_ART = "@%#*+=-:. ";

// Function to convert an RGB pixel to a grayscale value
int rgb_to_gray(int r, int g, int b) {
    return (r * 0.299 + g * 0.587 + b * 0.114);
}

// Main function
int main(int argc, char **argv) {
    // Check that input file was specified
    if (argc < 2) {
        printf("Error: no input file specified!\n");
        return 1;
    }

    // Open the input file in binary mode
    FILE *infile = fopen(argv[1], "rb");

    // Check that file was opened successfully
    if (!infile) {
        printf("Error: could not open input file\n");
        return 1;
    }

    // Read the header of the BMP file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, infile);

    // Extract metadata from the header
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int bits_per_pixel = *(short *)&header[28];

    // Check that the image is grayscale 8-bit
    if (bits_per_pixel != 8) {
        printf("Error: input image is not grayscale 8-bit\n");
        fclose(infile);
        return 1;
    }

    // Check that the image is not too large
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: input image is too large\n");
        fclose(infile);
        return 1;
    }

    // Allocate memory for the image data
    unsigned char *imgdata = (unsigned char*)malloc(width * height * sizeof(unsigned char));

    // Read the image data from the file
    fread(imgdata, sizeof(unsigned char), width * height, infile);

    // Close the input file
    fclose(infile);

    // Allocate memory for the ASCII art image
    char art[MAX_HEIGHT][MAX_WIDTH];

    // Convert each pixel to an ASCII character
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int gray_val = imgdata[y * width + x];
            int index = (int)(gray_val / (256.0 / strlen(ASCII_ART)));
            art[y][x] = ASCII_ART[index];
        }
    }

    // Print the ASCII art image to the console
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", art[y][x]);
        }
        printf("\n");
    }

    // Free the memory used by the images
    free(imgdata);

    // Done!
    return 0;
}