//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// Function to compute the brightness of a pixel
double compute_brightness(uint8_t r, uint8_t g, uint8_t b) {
    return 0.299 * r + 0.587 * g + 0.114 * b;
}

// Scale for ASCII characters based on brightness
const char *ascii_scale = "@%#*+=-:. ";

// Function to convert image to ASCII art
void image_to_ascii(const char *filename, int width, int height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    // Skip BMP header (assuming 24-bit uncompressed BMP)
    fseek(file, 18, SEEK_SET);
    int img_width, img_height;
    fread(&img_width, sizeof(int), 1, file);
    fread(&img_height, sizeof(int), 1, file);
    fseek(file, 54, SEEK_SET); // Start of pixel data

    if (img_width != width || img_height != height) {
        fprintf(stderr, "Image dimensions do not match\n");
        fclose(file);
        return;
    }

    // Buffer for pixel data
    uint8_t *data = malloc(width * height * 3);
    fread(data, 3, width * height, file);
    fclose(file);

    // Generate ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int idx = (y * width + x) * 3;
            uint8_t r = data[idx + 2];
            uint8_t g = data[idx + 1];
            uint8_t b = data[idx + 0];
            double brightness = compute_brightness(r, g, b);

            // Map brightness to ASCII character
            int scaled_index = (int)(brightness / 255 * (strlen(ascii_scale) - 1));
            putchar(ascii_scale[scaled_index]);
        }
        putchar('\n');
    }

    free(data);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image_file> <width> <height>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *image_file = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    image_to_ascii(image_file, width, height);

    return EXIT_SUCCESS;
}