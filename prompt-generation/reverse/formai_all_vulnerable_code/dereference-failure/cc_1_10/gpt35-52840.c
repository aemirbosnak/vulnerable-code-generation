//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH_MULTIPLIER 0.5 // ASCII character width multiplier
#define MAX_PIXEL_VALUE 255 // maximum pixel value for RGB

// Function prototypes
char get_ascii_character(int grayscale_value, int use_color);
double map_pixel_value_to_ascii(double pixel_value, int use_color);
void print_ascii_art(char* ascii_art);

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: ./img2ascii <filename>\n");
        return 1; // Exit program with error
    }

    const int MAX_ASCII_CHARS = 80; // Maximum columns in the ASCII art
    const int MAX_PIXELS = MAX_ASCII_CHARS * MAX_ASCII_CHARS; // Maximum number of pixels in the image

    // Open and read image file
    FILE* fp = fopen(argv[1], "rb");
    if(fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }
    unsigned char header[54]; // Header size of BMP is 54 bytes
    fread(header, sizeof(unsigned char), 54, fp);

    // Get dimensions of image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Ensure image is not too large
    if(width > MAX_ASCII_CHARS || height > MAX_ASCII_CHARS) {
        printf("Error: image dimensions are too large. Maximum dimensions are %dx%d.\n", MAX_ASCII_CHARS, MAX_ASCII_CHARS);
        return 1;
    }

    // Compute image data size
    int padding = (4 - (width * 3) % 4) % 4; // BMP image data is padded to a multiple of 4 bytes
    int imageSize = (width * height * 3) + (padding * height);

    // Create image data buffer
    unsigned char* imageData = (unsigned char*) malloc(sizeof(unsigned char) * imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, fp);
    fclose(fp);

    // Create ASCII art buffer
    char* ascii_art = (char*) malloc(sizeof(char) * MAX_PIXELS);
    ascii_art[0] = '\0';

    // Process each pixel and convert to grayscale
    int pixel_index = 0;
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int blue = imageData[pixel_index++];
            int green = imageData[pixel_index++];
            int red = imageData[pixel_index++];
            int grayscale_value = (red + green + blue) / 3;
            char ascii_char = get_ascii_character(grayscale_value, 0);
            strncat(ascii_art, &ascii_char, 1);
        }
        strncat(ascii_art, "\n", 1); // Add new line character after each row
        pixel_index += padding; // Skip over padding bytes
    }

    // Print ASCII art to console
    print_ascii_art(ascii_art);

    // Free memory
    free(imageData);
    free(ascii_art);

    return 0;
}

// Convert grayscale value to ASCII character
char get_ascii_character(int grayscale_value, int use_color) {
    int color_value = map_pixel_value_to_ascii(grayscale_value, use_color);
    const char* ascii_chars = " .:-=+*#%@";
    int num_chars = strlen(ascii_chars);
    int char_index = color_value * (num_chars - 1) / MAX_PIXEL_VALUE;
    return ascii_chars[char_index];
}

// Map pixel value to ASCII character width
double map_pixel_value_to_ascii(double pixel_value, int use_color) {
    if(use_color) {
        return pixel_value;
    }
    else {
        const double LOW = 0.0;
        const double HIGH = MAX_PIXEL_VALUE;
        const double NEW_LOW = 0.0;
        const double NEW_HIGH = 10.0;
        return ((pixel_value - LOW) / (HIGH - LOW) * (NEW_HIGH - NEW_LOW)) + NEW_LOW;
    }
}

// Print ASCII art to console
void print_ascii_art(char* ascii_art) {
    printf("%s", ascii_art);
}