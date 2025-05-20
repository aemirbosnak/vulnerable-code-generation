//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The mapping of ASCII chars to pixel values
const char *ascii = " .:-=+*#%@";

// Helper function to convert RGB values to grayscale
unsigned char rgb2gray(unsigned char r, unsigned char g, unsigned char b) {
    return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

int main(int argc, char* argv[]) {
    // Check if the user provided an image file path
    if (argc < 2) {
        printf("Usage: %s [path/to/image_file]\n", argv[0]);
        return 1;
    }

    // Open the image file
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: can't open file %s\n", argv[1]);
        return 1;
    }

    // Read the image header (we only need the width and height)
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for the pixel data
    int size = width * height * 3;
    unsigned char* data = (unsigned char*) malloc(size);
    fread(data, sizeof(unsigned char), size, fp);
    fclose(fp);

    // Translate pixel data into ASCII art
    char ascii_art[height][width+1];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Convert RGB values to grayscale and map to an ASCII char
            unsigned char gray = rgb2gray(data[(i*width+j)*3],
                                          data[(i*width+j)*3+1],
                                          data[(i*width+j)*3+2]);
            int index = (int)(((float)gray/255.0f)*((float)strlen(ascii)-1));
            ascii_art[i][j] = ascii[index];
        }
        ascii_art[i][width] = '\0';
    }

    // Print the ASCII art to console
    for (int i = 0; i < height; i++) {
        printf("%s\n", ascii_art[i]);
    }

    // Cleanup
    free(data);

    return 0;
}