//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Read image from file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    // Get image dimensions
    unsigned int width, height;
    fread(&width, sizeof(unsigned int), 1, image_file);
    fread(&height, sizeof(unsigned int), 1, image_file);

    // Create ASCII art buffer
    char *ascii_art = malloc(width * height * sizeof(char));
    if (ascii_art == NULL) {
        perror("Error allocating ASCII art buffer");
        fclose(image_file);
        return EXIT_FAILURE;
    }

    // Convert image to ASCII art
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            // Read pixel color
            unsigned char r, g, b;
            fread(&r, sizeof(unsigned char), 1, image_file);
            fread(&g, sizeof(unsigned char), 1, image_file);
            fread(&b, sizeof(unsigned char), 1, image_file);

            // Calculate ASCII character based on pixel brightness
            double brightness = (0.2126 * r) + (0.7152 * g) + (0.0722 * b);
            char character = (char)round(brightness / 255 * 255);

            // Write ASCII character to buffer
            ascii_art[y * width + x] = character;
        }
    }

    // Close image file
    fclose(image_file);

    // Print ASCII art to console
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            printf("%c", ascii_art[y * width + x]);
        }
        printf("\n");
    }

    // Free ASCII art buffer
    free(ascii_art);

    return EXIT_SUCCESS;
}