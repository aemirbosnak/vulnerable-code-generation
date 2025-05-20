//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

void convert_image_to_ascii(const char *filename) {
    // Open the image file
    FILE *image_file = fopen(filename, "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", filename);
        return;
    }

    // Read the image header
    unsigned char header[14];
    fread(header, sizeof(header), 1, image_file);

    // Check if the image is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Invalid BMP file\n");
        fclose(image_file);
        return;
    }

    // Get the image dimensions
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];

    // Allocate memory for the image data
    unsigned char *image_data = malloc(width * height * 3);
    if (image_data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(image_file);
        return;
    }

    // Read the image data
    fread(image_data, width * height * 3, 1, image_file);

    // Close the image file
    fclose(image_file);

    // Convert the image data to ASCII art
    char *ascii_art = malloc(width * height * 2 + 1);
    if (ascii_art == NULL) {
        fprintf(stderr, "Error allocating memory for ASCII art\n");
        free(image_data);
        return;
    }

    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            // Get the RGB values for the pixel
            unsigned char red = image_data[(y * width + x) * 3];
            unsigned char green = image_data[(y * width + x) * 3 + 1];
            unsigned char blue = image_data[(y * width + x) * 3 + 2];

            // Convert the RGB values to a grayscale value
            unsigned char grayscale = (red + green + blue) / 3;

            // Convert the grayscale value to an ASCII character
            char ascii_character = ' ';
            if (grayscale <= 32) {
                ascii_character = '@';
            } else if (grayscale <= 64) {
                ascii_character = '%';
            } else if (grayscale <= 96) {
                ascii_character = '=';
            } else if (grayscale <= 128) {
                ascii_character = '+';
            } else if (grayscale <= 160) {
                ascii_character = '*';
            } else if (grayscale <= 192) {
                ascii_character = ':';
            } else {
                ascii_character = ' ';
            }

            // Append the ASCII character to the ASCII art string
            ascii_art[(y * width + x) * 2] = ascii_character;
            ascii_art[(y * width + x) * 2 + 1] = ' ';
        }
    }

    ascii_art[width * height * 2] = '\0';

    // Print the ASCII art to the console
    printf("%s\n", ascii_art);

    // Free the memory allocated for the image data and ASCII art
    free(image_data);
    free(ascii_art);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    convert_image_to_ascii(argv[1]);

    return 0;
}