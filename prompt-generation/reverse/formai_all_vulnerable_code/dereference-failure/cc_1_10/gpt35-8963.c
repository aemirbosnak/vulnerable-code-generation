//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This program converts an image file into ASCII art. Each pixel in the image is replaced with a corresponding ASCII character.

The program reads images in the PPM format (P3). The PPM header is read (which contains the width, height, and max color value of the image), and then the pixel values are read in and converted to ASCII characters.

Each pixel is represented by three values (R, G, B), which are converted to a grayscale value (0-255) and then mapped to an ASCII character (using a predefined character set).

The resulting ASCII art is printed to stdout.
*/

// Character set - define the characters to use for mapping grayscale values to ASCII characters
char charset[] = " .:-=+*#%@";

// Function declarations
int read_ppm_header(FILE* fp, int* width, int* height, int* max_val);
void print_ascii_art(char* ascii_art[], int width, int height);
char grayscale_to_char(int grayscale);

int main(int argc, char* argv[]) {
    // Ensure correct usage
    if (argc != 2) {
        printf("Usage: %s [input_file.ppm]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open input file
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read PPM header
    int width, height, max_val;
    if (!read_ppm_header(fp, &width, &height, &max_val)) {
        printf("Error: Invalid PPM format\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for pixel data and ASCII art
    int num_pixels = width * height;
    unsigned char* pixels = malloc(num_pixels * 3);
    char** ascii_art = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        ascii_art[i] = malloc(width + 1);
        ascii_art[i][width] = '\0';
    }

    // Read pixel data and convert to grayscale and ASCII art
    for (int i = 0; i < num_pixels; i++) {
        fscanf(fp, "%hhu %hhu %hhu", &pixels[i*3], &pixels[i*3 + 1], &pixels[i*3 + 2]); // Read RGB values
        int grayscale = (pixels[i*3] + pixels[i*3 + 1] + pixels[i*3 + 2]) / 3; // Calculate grayscale value (average of R, G, B values)
        ascii_art[i / width][i % width] = grayscale_to_char(grayscale); // Map grayscale value to ASCII character
    }

    // Print ASCII art to stdout
    print_ascii_art(ascii_art, width, height);

    // Clean up
    fclose(fp);
    free(pixels);
    for (int i = 0; i < height; i++) {
        free(ascii_art[i]);
    }
    free(ascii_art);

    return 0;
}

// Reads the PPM header (which contains the width, height, and max color value of the image) from the given file pointer.
// Return 1 on success, 0 on failure.
int read_ppm_header(FILE* fp, int* width, int* height, int* max_val) {
    char magic_num[3];
    if (fscanf(fp, "%2s", magic_num) != 1 || strcmp(magic_num, "P3") != 0) {
        return 0; // Invalid magic number (must be P3)
    }
    if (fscanf(fp, "%d %d %d", width, height, max_val) != 3) {
        return 0; // Invalid header format
    }
    return 1;
}

// Prints the given ASCII art to stdout with a nice border.
void print_ascii_art(char* ascii_art[], int width, int height) {
    printf("+");
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("+\n");
    for (int i = 0; i < height; i++) {
        printf("|%s|\n", ascii_art[i]);
    }
    printf("+");
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("+\n");
}

// Maps the given grayscale value to an ASCII character using the predefined character set.
char grayscale_to_char(int grayscale) {
    int num_chars = strlen(charset);
    int index = (grayscale * (num_chars - 1)) / 255;
    return charset[index];
}