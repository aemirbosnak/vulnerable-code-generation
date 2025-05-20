//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 80
#define MAX_HEIGHT 80

// Define the maximum length of the output ASCII art
#define MAX_ASCII_LEN 8000

// Define the char set used to convert pixels to ASCII characters
const char charSet[] = "@#&$%*o!;:~\",^`'.. ";

int main(int argc, char **argv) {
    // Check if the input file was provided
    if (argc < 2) {
        printf("Usage: ./converter <image-file>\n");
        return 1;
    }

    // Open the input file
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    // Allocate memory for the pixel data
    char *pixels = (char*)malloc(MAX_WIDTH * MAX_HEIGHT);

    // Read the header of the BMP file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Parse the width and height of the image from the header
    unsigned int width = *(int*)(header + 18);
    unsigned int height = *(int*)(header + 22);

    // Calculate the padding for each row of pixels
    unsigned int padding = (4 - (width * 3) % 4) % 4;

    // Ensure the dimensions of the image are within limits
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image dimensions are too large\n");
        return 1;
    }

    // Read the pixel data from the file
    int idx = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char blue, green, red;
            fread(&blue, sizeof(char), 1, file);
            fread(&green, sizeof(char), 1, file);
            fread(&red, sizeof(char), 1, file);
            pixels[idx++] = (char)((float)(blue + green + red) * 0.333f);
        }
        // Skip any padding bytes at the end of the row
        fseek(file, padding, SEEK_CUR);
    }

    // Close the input file
    fclose(file);

    // Allocate memory for the ASCII art
    char *ascii = (char*)malloc(MAX_ASCII_LEN);

    // Convert the pixel data to ASCII characters
    int offset = 0;
    for (int i = 0; i < height; i += 2) {
        for (int j = 0; j < width; j += 2) {
            char pixel1 = pixels[i * width + j];
            char pixel2 = pixels[(i + 1) * width + j];
            char pixel3 = pixels[(i + 1) * width + j + 1];
            char pixel4 = pixels[i * width + j + 1];
            char avg = (char)((float)(pixel1 + pixel2 + pixel3 + pixel4) * 0.25f);
            int index = (int)((float)avg / 255.0f * (float)(strlen(charSet) - 1));
            ascii[offset++] = charSet[index];
        }
        ascii[offset++] = '\n';
    }

    // Print the ASCII art to the console
    printf("%s\n", ascii);

    // Free the memory
    free(pixels);
    free(ascii);

    return 0;
}