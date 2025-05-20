//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an image to ASCII art
char *image_to_ascii(const char *filename) {
    // Open the image file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the image header
    unsigned char header[14];
    fread(header, sizeof(header), 1, fp);

    // Check if the file is a valid BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP image\n", filename);
        fclose(fp);
        return NULL;
    }

    // Get the image dimensions
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height * 3);
    if (data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        return NULL;
    }

    // Read the image data
    fread(data, width * height * 3, 1, fp);

    // Close the image file
    fclose(fp);

    // Convert the image data to ASCII art
    char *ascii_art = malloc(width * height * 4);
    if (ascii_art == NULL) {
        fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
        free(data);
        return NULL;
    }

    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the RGB values of the pixel
            unsigned char r = data[y * width * 3 + x * 3 + 2];
            unsigned char g = data[y * width * 3 + x * 3 + 1];
            unsigned char b = data[y * width * 3 + x * 3 + 0];

            // Convert the RGB values to a grayscale value
            unsigned char grayscale = (r + g + b) / 3;

            // Convert the grayscale value to an ASCII character
            char c;
            if (grayscale < 32) {
                c = '#';
            } else if (grayscale < 64) {
                c = '%';
            } else if (grayscale < 96) {
                c = '@';
            } else if (grayscale < 128) {
                c = '*';
            } else if (grayscale < 160) {
                c = ':';
            } else if (grayscale < 192) {
                c = ';';
            } else if (grayscale < 224) {
                c = ',';
            } else {
                c = ' ';
            }

            // Add the ASCII character to the ASCII art string
            ascii_art[index++] = c;
        }

        // Add a newline character to the ASCII art string
        ascii_art[index++] = '\n';
    }

    // Null-terminate the ASCII art string
    ascii_art[index++] = '\0';

    // Free the memory allocated for the image data
    free(data);

    // Return the ASCII art string
    return ascii_art;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified an image file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Convert the image file to ASCII art
    char *ascii_art = image_to_ascii(argv[1]);
    if (ascii_art == NULL) {
        return 1;
    }

    // Print the ASCII art to the console
    printf("%s", ascii_art);

    // Free the memory allocated for the ASCII art
    free(ascii_art);

    return 0;
}