//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WIDTH 160
#define HEIGHT 120
#define ASCII_CHARS "@%#*+=-:. "

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int get_char_index(uint8_t pixel) {
    return (pixel * (strlen(ASCII_CHARS) - 1)) / 255; // Map pixel to ASCII index
}

void convert_image_to_ascii(const char *filename) {
    FILE *image_file = fopen(filename, "rb");
    if (!image_file)
        error("Failed to open image file");

    // Skipping the header for simplicity, assumes P6 PPM file format (no compression)
    fseek(image_file, 15, SEEK_SET); // Skip PPM header
    uint8_t *image_data = (uint8_t *)malloc(WIDTH * HEIGHT * 3);
    fread(image_data, sizeof(uint8_t), WIDTH * HEIGHT * 3, image_file);
    fclose(image_file);

    char ascii_art[HEIGHT][WIDTH + 1]; // Store ASCII art output
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int pixel_index = (y * WIDTH + x) * 3; // RGB pixel location
            uint8_t gray_value = (image_data[pixel_index] + image_data[pixel_index + 1] + image_data[pixel_index + 2]) / 3; // Convert to grayscale
            ascii_art[y][x] = ASCII_CHARS[get_char_index(gray_value)];
        }
        ascii_art[y][WIDTH] = '\0'; // Null-terminate each string
    }
    
    free(image_data);
    
    // Output ASCII art to console
    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", ascii_art[y]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    convert_image_to_ascii(argv[1]);
    return EXIT_SUCCESS;
}