//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

// Define the number of ASCII characters to use
#define NUM_ASCII_CHARS 70

// Define the ASCII character map
char ascii_map[NUM_ASCII_CHARS] = {
    ' ', '.', ',', '-', '_', ':', ';', '!', '?', ']', '[', '}', '{', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'w', 'q', 'p', 'b', 'd', 'x', 'n', 'v', 'u', 'c', 'y', 'g', 't', 'f', 'r', 'e', 'a', 's', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'M', 'N', 'B', 'V', 'C', 'X', 'Z', 'L', 'K', 'J', 'H', 'G', 'F', 'E', 'D', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '@', '#', '$', '%', '^', '&', '*', '(', ')', '+', '=', '<', '>', '/', '\\'
};

// Load an image from a file
unsigned char* load_image(const char* filename, int* width, int* height) {
    // Open the file
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    // Read the header
    unsigned char header[18];
    if (fread(header, 1, 18, file) != 18) {
        fprintf(stderr, "Error reading header from file: %s\n", filename);
        exit(1);
    }

    // Check the header
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: not a BMP file\n");
        exit(1);
    }

    // Get the width and height
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    // Check the width and height
    if (*width <= 0 || *width > MAX_WIDTH || *height <= 0 || *height > MAX_HEIGHT) {
        fprintf(stderr, "Error: image is too large\n");
        exit(1);
    }

    // Allocate memory for the image data
    unsigned char* data = malloc(*width * *height * 3);
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        exit(1);
    }

    // Read the image data
    if (fread(data, 1, *width * *height * 3, file) != *width * *height * 3) {
        fprintf(stderr, "Error reading image data from file: %s\n", filename);
        exit(1);
    }

    // Close the file
    fclose(file);

    // Return the image data
    return data;
}

// Convert an image to ASCII art
char* convert_image_to_ascii(unsigned char* data, int width, int height) {
    // Allocate memory for the ASCII art
    char* ascii_art = malloc(width * height + 1);
    if (ascii_art == NULL) {
        fprintf(stderr, "Error allocating memory for ASCII art\n");
        exit(1);
    }

    // Convert the image data to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the RGB values of the pixel
            unsigned char r = data[(y * width + x) * 3];
            unsigned char g = data[(y * width + x) * 3 + 1];
            unsigned char b = data[(y * width + x) * 3 + 2];

            // Calculate the brightness of the pixel
            double brightness = (r + g + b) / 3.0;

            // Find the closest ASCII character to the brightness
            int index = (int)round((brightness / 255.0) * (NUM_ASCII_CHARS - 1));

            // Set the ASCII character in the ASCII art
            ascii_art[y * width + x] = ascii_map[index];
        }
    }

    // Add a newline character to the end of the ASCII art
    ascii_art[width * height] = '\0';

    // Return the ASCII art
    return ascii_art;
}

// Print the ASCII art to the console
void print_ascii_art(char* ascii_art, int width, int height) {
    // Print the ASCII art to the console
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", ascii_art[y * width + x]);
        }
        printf("\n");
    }
}

// Free the memory allocated for the image data and ASCII art
void free_memory(unsigned char* data, char* ascii_art) {
    // Free the memory allocated for the image data
    free(data);

    // Free the memory allocated for the ASCII art
    free(ascii_art);
}

// Main function
int main(int argc, char** argv) {
    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        exit(1);
    }

    // Load the image
    int width, height;
    unsigned char* data = load_image(argv[1], &width, &height);

    // Convert the image to ASCII art
    char* ascii_art = convert_image_to_ascii(data, width, height);

    // Print the ASCII art to the console
    print_ascii_art(ascii_art, width, height);

    // Free the memory allocated for the image data and ASCII art
    free_memory(data, ascii_art);

    return 0;
}