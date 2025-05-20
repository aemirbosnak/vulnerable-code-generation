//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII characters to use for conversion
char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// Define the size of the ASCII characters array
int ascii_size = 10;

// Define the size of the character buffer
int char_buffer_size = 512;

// Define the size of the image buffer
int image_buffer_size = 1024;

// Function to convert an image to ASCII art
void convert_to_ascii(const char* image_path) {
    // Open the image file
    FILE* file = fopen(image_path, "rb");
    if (!file) {
        printf("Error: could not open file\n");
        return;
    }

    // Allocate a buffer to hold the image data
    unsigned char* image_buffer = malloc(image_buffer_size * sizeof(unsigned char));
    if (!image_buffer) {
        printf("Error: could not allocate memory\n");
        return;
    }

    // Read the image data into the buffer
    fread(image_buffer, sizeof(unsigned char), image_buffer_size, file);

    // Close the image file
    fclose(file);

    // Define the dimensions of the image
    int width = 32;
    int height = 32;

    // Allocate a buffer to hold the converted image data
    char* char_buffer = malloc(char_buffer_size * sizeof(char));
    if (!char_buffer) {
        printf("Error: could not allocate memory\n");
        return;
    }

    // Loop through each pixel of the image
    for (int i = 0; i < width * height; i++) {
        // Compute the grayscale value of the pixel
        int grayscale = (int) ((float) image_buffer[i] / 255.0 * (float) (ascii_size - 1));

        // Map the grayscale value to an ASCII character
        char ascii_char = ascii_chars[grayscale];

        // Add the ASCII character to the buffer
        sprintf(char_buffer + strlen(char_buffer), "%c", ascii_char);
    }

    // Print the converted image data
    printf("%s\n", char_buffer);

    // Free the memory used by the buffers
    free(char_buffer);
    free(image_buffer);
}

// Main function
int main(int argc, const char* argv[]) {
    // Check for the image path argument
    if (argc < 2) {
        printf("Error: no image path supplied\n");
        return 1;
    }

    // Convert the image to ASCII art
    convert_to_ascii(argv[1]);

    return 0;
}