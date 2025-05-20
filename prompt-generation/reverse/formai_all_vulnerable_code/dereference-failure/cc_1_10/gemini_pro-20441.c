//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ASCII art characters
static const char *ascii_chars = "@#%*-+=:.;,_)(/`~";

// Get the average brightness of a pixel
static double get_brightness(unsigned char r, unsigned char g, unsigned char b) {
    return (r + g + b) / 3.0;
}

// Convert a pixel to an ASCII character
static char pixel_to_ascii(double brightness) {
    int index = (int) round(brightness / 255.0 * (strlen(ascii_chars) - 1));
    return ascii_chars[index];
}

// Convert an image to ASCII art
static char *image_to_ascii(const char *filename) {
    // Open the image file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening image file");
        return NULL;
    }

    // Read the image header
    unsigned char header[14];
    if (fread(header, sizeof(header), 1, fp) != 1) {
        perror("Error reading image header");
        fclose(fp);
        return NULL;
    }

    // Check if the image is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: not a BMP file\n");
        fclose(fp);
        return NULL;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the image data
    unsigned char *data = (unsigned char *) malloc(width * height * 3);
    if (fread(data, width * height * 3, 1, fp) != 1) {
        perror("Error reading image data");
        fclose(fp);
        return NULL;
    }

    // Close the image file
    fclose(fp);

    // Convert the image to ASCII art
    char *ascii_art = (char *) malloc(width * height + 1);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char r = data[(i * width + j) * 3 + 2];
            unsigned char g = data[(i * width + j) * 3 + 1];
            unsigned char b = data[(i * width + j) * 3 + 0];
            ascii_art[i * width + j] = pixel_to_ascii(get_brightness(r, g, b));
        }
    }

    // Add a newline character to the end of the ASCII art
    ascii_art[width * height] = '\0';

    // Return the ASCII art
    return ascii_art;
}

// Print the ASCII art to the console
static void print_ascii_art(const char *ascii_art) {
    printf("%s", ascii_art);
}

// Free the memory allocated for the ASCII art
static void free_ascii_art(char *ascii_art) {
    free(ascii_art);
}

int main(int argc, char *argv[]) {
    // Check if the user specified an image file
    if (argc < 2) {
        fprintf(stderr, "Error: no image file specified\n");
        return 1;
    }

    // Convert the image to ASCII art
    char *ascii_art = image_to_ascii(argv[1]);
    if (ascii_art == NULL) {
        return 1;
    }

    // Print the ASCII art to the console
    print_ascii_art(ascii_art);

    // Free the memory allocated for the ASCII art
    free_ascii_art(ascii_art);

    return 0;
}