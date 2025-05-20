//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the characters used to represent different shades of gray
char *shades = " .:-=+*#%@";

// Read an image from a file
int read_image(char *filename, unsigned char *image, int *width, int *height) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }

    // Read the header information
    unsigned char header[18];
    fread(header, sizeof(header), 1, fp);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fclose(fp);
        return -1;
    }

    // Get the width and height of the image
    *width = *(int *)&header[18];
    *height = *(int *)&header[22];

    // Check if the image is too large
    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
        fclose(fp);
        return -1;
    }

    // Read the image data
    fread(image, sizeof(unsigned char), *width * *height, fp);

    // Close the file
    fclose(fp);

    return 0;
}

// Convert an image to ASCII art
void image_to_ascii(unsigned char *image, int width, int height) {
    // Create a 2D array to store the ASCII art
    char **ascii_art = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        ascii_art[i] = malloc(width * sizeof(char));
    }

    // Convert each pixel to an ASCII character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = image[i * width + j] / 16;
            ascii_art[i][j] = shades[index];
        }
    }

    // Print the ASCII art to the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the ASCII art
    for (int i = 0; i < height; i++) {
        free(ascii_art[i]);
    }
    free(ascii_art);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided an image file
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return -1;
    }

    // Read the image from the file
    unsigned char image[MAX_WIDTH * MAX_HEIGHT];
    int width, height;
    if (read_image(argv[1], image, &width, &height) != 0) {
        printf("Error reading image file\n");
        return -1;
    }

    // Convert the image to ASCII art
    image_to_ascii(image, width, height);

    return 0;
}