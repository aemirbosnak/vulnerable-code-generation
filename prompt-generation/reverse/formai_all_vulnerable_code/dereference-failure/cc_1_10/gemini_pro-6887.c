//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 60

// Convert an RGB pixel to a grayscale value
unsigned char grayscale(unsigned char r, unsigned char g, unsigned char b) {
    return (r * 0.3 + g * 0.59 + b * 0.11);
}

// Convert a grayscale value to an ASCII character
char ascii(unsigned char gray) {
    char chars[] = " .:-=+*#%@";
    return chars[gray / (255 / (sizeof(chars) - 1))];
}

int main(int argc, char *argv[]) {
    // Check if a filename was provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the image file
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    // Read the image header
    unsigned int width, height;
    fread(&width, sizeof(width), 1, file);
    fread(&height, sizeof(height), 1, file);

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height * 3);
    if (data == NULL) {
        perror("malloc");
        return 1;
    }

    // Read the image data
    fread(data, width * height * 3, 1, file);

    // Close the image file
    fclose(file);

    // Convert the image to ASCII art
    unsigned char *gray = malloc(width * height);
    if (gray == NULL) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < width * height; i++) {
        gray[i] = grayscale(data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
    }

    // Print the ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", ascii(gray[y * width + x]));
        }
        printf("\n");
    }

    // Free the memory
    free(data);
    free(gray);

    return 0;
}