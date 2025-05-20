//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ASCII_ART_WIDTH 80
#define ASCII_ART_HEIGHT 40

// Convert an image to ASCII art using the luminance of each pixel
char *image_to_ascii_art(const unsigned char *image_data, int image_width, int image_height) {
    char *ascii_art = malloc(ASCII_ART_WIDTH * ASCII_ART_HEIGHT + 1);
    if (ascii_art == NULL) {
        return NULL;
    }

    for (int y = 0; y < ASCII_ART_HEIGHT; y++) {
        for (int x = 0; x < ASCII_ART_WIDTH; x++) {
            // Calculate the luminance of the pixel
            int luminance = (image_data[(y * image_width + x) * 3] + image_data[(y * image_width + x) * 3 + 1] + image_data[(y * image_width + x) * 3 + 2]) / 3;

            // Convert the luminance to an ASCII character
            char ascii_character;
            if (luminance < 32) {
                ascii_character = '#';
            } else if (luminance < 64) {
                ascii_character = '@';
            } else if (luminance < 96) {
                ascii_character = '%';
            } else if (luminance < 128) {
                ascii_character = '*';
            } else if (luminance < 160) {
                ascii_character = '+';
            } else if (luminance < 192) {
                ascii_character = '=';
            } else if (luminance < 224) {
                ascii_character = '-';
            } else {
                ascii_character = ' ';
            }

            // Add the ASCII character to the ASCII art
            ascii_art[y * ASCII_ART_WIDTH + x] = ascii_character;
        }
    }

    ascii_art[ASCII_ART_WIDTH * ASCII_ART_HEIGHT] = '\0';

    return ascii_art;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    // Read the image file
    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error: unable to open image file '%s'\n", argv[1]);
        return 1;
    }

    // Get the image dimensions
    int image_width, image_height;
    fscanf(image_file, "P3 %d %d 255\n", &image_width, &image_height);

    // Allocate memory for the image data
    unsigned char *image_data = malloc(image_width * image_height * 3);
    if (image_data == NULL) {
        fprintf(stderr, "Error: unable to allocate memory for image data\n");
        fclose(image_file);
        return 1;
    }

    // Read the image data
    fread(image_data, image_width * image_height * 3, 1, image_file);

    // Convert the image to ASCII art
    char *ascii_art = image_to_ascii_art(image_data, image_width, image_height);
    if (ascii_art == NULL) {
        fprintf(stderr, "Error: unable to convert image to ASCII art\n");
        fclose(image_file);
        free(image_data);
        return 1;
    }

    // Print the ASCII art to the console
    printf("%s", ascii_art);

    // Free the memory
    free(ascii_art);
    free(image_data);
    fclose(image_file);

    return 0;
}