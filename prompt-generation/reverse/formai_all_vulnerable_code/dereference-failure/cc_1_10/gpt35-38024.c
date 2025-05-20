//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width / height for the image
#define MAX_DIMENSION 100

// Define the maximum characters allowed for ASCII art
#define MAX_ASCII_CHARS 11

// Define the characters used for the ASCII art
char ascii_chars[MAX_ASCII_CHARS] = {' ', '.', '\'', ':', 'o', '&', '8', '#', '@', '%', '$'};

int main()
{
    // Open the input file
    FILE* input_file = fopen("input_image.bmp", "rb");

    // Check if the file was opened successfully
    if (input_file == NULL)
    {
        printf("Error: could not open input file\n");
        return 1;
    }

    // Read the BMP header (skip the first 54 bytes)
    fseek(input_file, 54L, SEEK_SET);

    // Read the image dimensions
    unsigned int width = 0, height = 0;
    fread(&width, sizeof(width), 1, input_file);
    fread(&height, sizeof(height), 1, input_file);

    // Check if the image dimensions are valid
    if (width > MAX_DIMENSION || height > MAX_DIMENSION)
    {
        printf("Error: image dimensions are too large\n");
        fclose(input_file);
        return 1;
    }

    // Calculate the number of bytes required to store the image
    unsigned int row_size_bytes = (width * 3 + 3) & ~3;
    unsigned int image_size_bytes = row_size_bytes * height;

    // Allocate memory for the image data
    unsigned char* image_data = (unsigned char*)malloc(image_size_bytes);

    // Read the image data
    fread(image_data, 1, image_size_bytes, input_file);
    fclose(input_file);

    // Create the ASCII art image
    char ascii_art[MAX_DIMENSION][MAX_DIMENSION];
    memset(ascii_art, ' ', MAX_DIMENSION * MAX_DIMENSION);

    for (unsigned int y = 0; y < height; y++)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            // Compute the RGB values
            unsigned char* pixel_address = image_data + y * row_size_bytes + x * 3;
            unsigned char b = *(pixel_address++);
            unsigned char g = *(pixel_address++);
            unsigned char r = *(pixel_address);

            // Compute the grayscale value
            unsigned char gray_value = (r + g + b) / 3;

            // Convert the grayscale value into an ASCII character
            unsigned int ascii_index = gray_value * MAX_ASCII_CHARS / 256;
            ascii_art[y][x] = ascii_chars[ascii_index];
        }
    }

    // Print the ASCII art image
    for (unsigned int y = 0; y < height; y++)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            printf("%c", ascii_art[y][x]);
        }
        printf("\n");
    }

    // Free the memory used by the image data
    free(image_data);

    return 0;
}