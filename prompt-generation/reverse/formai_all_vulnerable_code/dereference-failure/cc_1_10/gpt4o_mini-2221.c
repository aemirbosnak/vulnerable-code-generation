//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define ASCII_WIDTH 70
#define PIXEL_MAX 255
#define CHAR_COUNT 70

// Define a struct for a pixel
typedef struct {
    uint8_t r, g, b; // Red, Green, Blue components
} Pixel;

// Array of ASCII characters to represent pixel intensity
const char ascii_chars[CHAR_COUNT] = "@%#*+=-:. ";

// Function prototypes
void generate_ascii_art(const char *input_image, const char *output_file);
Pixel* load_image(const char *filename, int *width, int *height);
void write_ascii_to_file(const char *filename, const char *ascii_art, int art_width, int art_height);
char map_pixel_to_ascii(Pixel p);
void scale_image(Pixel *image, int original_width, int original_height, int new_width, int new_height, Pixel *scaled_image);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    generate_ascii_art(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

void generate_ascii_art(const char *input_image, const char *output_file) {
    int width, height;
    Pixel *image = load_image(input_image, &width, &height);
    if (image == NULL) {
        fprintf(stderr, "Error loading image: %s\n", input_image);
        return;
    }

    int scaled_height = (ASCII_WIDTH * height) / width;
    Pixel *scaled_image = malloc(ASCII_WIDTH * scaled_height * sizeof(Pixel));
    if (scaled_image == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(image);
        return;
    }

    scale_image(image, width, height, ASCII_WIDTH, scaled_height, scaled_image);

    char *ascii_art = malloc((ASCII_WIDTH + 1) * scaled_height);
    if (ascii_art == NULL) {
        fprintf(stderr, "Memory allocation failed for ASCII art\n");
        free(image);
        free(scaled_image);
        return;
    }

    for (int y = 0; y < scaled_height; y++) {
        for (int x = 0; x < ASCII_WIDTH; x++) {
            ascii_art[y * (ASCII_WIDTH + 1) + x] = map_pixel_to_ascii(scaled_image[y * ASCII_WIDTH + x]);
        }
        ascii_art[y * (ASCII_WIDTH + 1) + ASCII_WIDTH] = '\n'; // New line character
    }

    write_ascii_to_file(output_file, ascii_art, ASCII_WIDTH, scaled_height);

    free(image);
    free(scaled_image);
    free(ascii_art);
}

Pixel* load_image(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open image file");
        return NULL;
    }

    // Assuming an uncompressed BMP image format with 24 bits
    fseek(file, 18, SEEK_SET);
    fread(width, sizeof(int), 1, file);
    fread(height, sizeof(int), 1, file);
    fseek(file, 54, SEEK_SET); // Move to pixel array

    int size = (*width) * (*height);
    Pixel *image = malloc(size * sizeof(Pixel));
    if (!image) {
        perror("Memory allocation for image failed");
        fclose(file);
        return NULL;
    }

    fread(image, sizeof(Pixel), size, file);
    fclose(file);
    return image;
}

void write_ascii_to_file(const char *filename, const char *ascii_art, int art_width, int art_height) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open output file");
        return;
    }

    fwrite(ascii_art, sizeof(char), (art_width + 1) * art_height, file);
    fclose(file);
    printf("ASCII art written to %s\n", filename);
}

char map_pixel_to_ascii(Pixel p) {
    // Calculate brightness
    double brightness = 0.299 * p.r + 0.587 * p.g + 0.114 * p.b;
    int index = (int)(brightness * (CHAR_COUNT - 1) / PIXEL_MAX);
    return ascii_chars[index];
}

void scale_image(Pixel *image, int original_width, int original_height, int new_width, int new_height, Pixel *scaled_image) {
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int src_x = (x * original_width) / new_width;
            int src_y = (y * original_height) / new_height;
            scaled_image[y * new_width + x] = image[src_y * original_width + src_x];
        }
    }
}