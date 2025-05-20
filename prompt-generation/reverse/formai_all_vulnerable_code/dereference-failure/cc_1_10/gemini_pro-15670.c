//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480

// Function to convert an RGB pixel to a grayscale value
unsigned char rgb_to_grayscale(unsigned char r, unsigned char g, unsigned char b) {
    return (r * 0.3 + g * 0.59 + b * 0.11);
}

// Function to convert a grayscale value to an ASCII character
char grayscale_to_ascii(unsigned char grayscale) {
    char ascii_chars[] = " .:-=+*#%@";
    return ascii_chars[grayscale / 16];
}

int main() {
    // Load the image from a file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Read the header information from the image file
    unsigned char header[54];
    fread(header, 1, 54, image_file);

    // Check if the image is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: Invalid BMP file.\n");
        return 1;
    }

    // Get the width and height of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Check if the image is the correct size
    if (width != IMAGE_WIDTH || height != IMAGE_HEIGHT) {
        printf("Error: Image is not the correct size.\n");
        return 1;
    }

    // Create an array to store the grayscale values of the image
    unsigned char grayscale_image[IMAGE_WIDTH * IMAGE_HEIGHT];

    // Read the pixel data from the image file
    fread(grayscale_image, 1, IMAGE_WIDTH * IMAGE_HEIGHT, image_file);

    // Close the image file
    fclose(image_file);

    // Convert the grayscale values to ASCII characters
    char ascii_image[IMAGE_WIDTH * IMAGE_HEIGHT];
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
        ascii_image[i] = grayscale_to_ascii(grayscale_image[i]);
    }

    // Print the ASCII art to the console
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            printf("%c", ascii_image[i * IMAGE_WIDTH + j]);
        }
        printf("\n");
    }

    return 0;
}