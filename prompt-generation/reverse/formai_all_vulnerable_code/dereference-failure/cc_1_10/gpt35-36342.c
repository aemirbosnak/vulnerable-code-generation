//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ultraprecise
#include <stdio.h>

// A function to map pixel intensity values to ASCII characters
char intensityToChar(int intensity) {
    if (intensity <= 25) {
        return '@';
    } else if (intensity <= 50) {
        return '#';
    } else if (intensity <= 75) {
        return '%';
    } else if (intensity <= 100) {
        return '*';
    } else if (intensity <= 125) {
        return '+';
    } else if (intensity <= 150) {
        return '=';
    } else if (intensity <= 175) {
        return '-';
    } else if (intensity <= 200) {
        return ':';
    } else if (intensity <= 225) {
        return '.';
    } else {
        return ' ';
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please specify an input image file.\n");
        return -1;
    }

    // Open the image file in binary mode and read the header information
    FILE *imageFile = fopen(argv[1], "rb");
    if (!imageFile) {
        printf("Could not open input file '%s'\n", argv[1]);
        return -1;
    }

    // Extract the dimensions and bit depth from the header
    int width, height, bitDepth;
    fscanf(imageFile, "%*s %d %d %d", &width, &height, &bitDepth);

    // Skip the remainder of the header and get to the pixel data
    fseek(imageFile, 15, SEEK_SET);
    
    // Calculate the number of pixels in the image
    int numPixels = width * height;

    // Allocate memory for the pixel data and read the pixel data into it
    unsigned char* pixels = malloc(numPixels);
    fread(pixels, sizeof(unsigned char), numPixels, imageFile);

    // Close the image file
    fclose(imageFile);

    // Loop through the pixel data and convert each pixel's intensity to an ASCII character
    for (int i = 1; i <= numPixels; i++) {
        printf("%c", intensityToChar(pixels[i]));
        // Add a newline character after each row of pixels
        if (i % width == 0) {
            printf("\n");
        }
    }

    // Free the dynamically allocated memory
    free(pixels);

    return 0;
}