//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 50

// Define the ASCII characters to use for each grayscale value
char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// Function to convert a grayscale pixel to an ASCII character
char pixel_to_ascii(int pixel) {
    int char_index = (pixel * (sizeof(ascii_chars) - 1)) / 255;
    return ascii_chars[char_index];
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: img2ascii <image_file>\n");
        return 1;
    }

    FILE *image_file = fopen(argv[1], "rb");
    if (!image_file) {
        printf("Error: could not open image file.\n");
        return 1;
    }

    // Read the header info from the image file
    char header[54];
    fread(header, sizeof(char), 54, image_file);

    // Get the width and height of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Make sure the image is not too big
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image is too large.\n");
        return 1;
    }

    // Allocate memory for the pixel data
    int pixel_data_size = width * height * 3; // 3 bytes per pixel (RGB)
    unsigned char *pixel_data = (unsigned char*)malloc(pixel_data_size);

    // Read the pixel data from the image file
    fread(pixel_data, sizeof(unsigned char), pixel_data_size, image_file);

    // Close the image file
    fclose(image_file);

    // Convert the pixel data to ASCII art
    char ascii_art[MAX_HEIGHT][MAX_WIDTH+1]; // +1 for the null terminator
    memset(ascii_art, 0, MAX_HEIGHT * (MAX_WIDTH+1)); // Initializing all elements to 0 (null character)
    int pixel_index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the grayscale value of the pixel
            int r = pixel_data[pixel_index];
            int g = pixel_data[pixel_index + 1];
            int b = pixel_data[pixel_index + 2];
            int gray = (r + g + b) / 3;

            // Convert the grayscale value to an ASCII character and store it in ascii_art
            ascii_art[y][x] = pixel_to_ascii(gray);

            // Move to the next pixel in pixel_data
            pixel_index += 3;
        }
    }

    // Print the ASCII art to the console
    for (int y = 0; y < height; y++) {
        printf("%s\n", ascii_art[y]);
    }

    // Free the memory allocated for pixel_data
    free(pixel_data);

    return 0;
}