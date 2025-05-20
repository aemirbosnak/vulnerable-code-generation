//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_PIXEL_SIZE 4 // RGBA

// This function reads the image file and returns the pixel values array
uint8_t* read_image(const char* filename, uint32_t* width, uint32_t* height) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: failed to open file %s\n", filename);
        return NULL;
    }

    // Read file header (14 bytes)
    uint8_t file_header[14];
    fread(file_header, 1, 14, fp);

    // Check if file is valid BMP type
    if (file_header[0] != 'B' || file_header[1] != 'M') {
        fprintf(stderr, "Error: invalid file format %s\n", filename);
        fclose(fp);
        return NULL;
    }

    // Read image header (40 bytes)
    uint8_t info_header[40];
    fread(info_header, 1, 40, fp);

    // Get image dimensions
    *width = *(uint32_t*)&info_header[4];
    *height = *(uint32_t*)&info_header[8];

    // Get number of bits per pixel (must be 32 bits)
    uint16_t bits_per_pixel = *(uint16_t*)&info_header[14];
    if (bits_per_pixel != 32) {
        fprintf(stderr, "Error: invalid bits per pixel %s\n", filename);
        fclose(fp);
        return NULL;
    }

    // Ignore image compression
    uint32_t compression = *(uint32_t*)&info_header[16];
    if (compression != 0) {
        fprintf(stderr, "Error: invalid compression %s\n", filename);
        fclose(fp);
        return NULL;
    }

    // Allocate memory for image pixels
    uint32_t pixels_size = *width * *height * MAX_PIXEL_SIZE;
    uint8_t* pixels = (uint8_t*)malloc(pixels_size);
    if (!pixels) {
        fprintf(stderr, "Error: failed to allocate memory\n");
        fclose(fp);
        return NULL;
    }

    // Read image pixels
    fseek(fp, *(uint32_t*)&file_header[10], SEEK_SET);
    fread(pixels, 1, pixels_size, fp);

    fclose(fp);
    return pixels;
}

// This function generates the ASCII art from the pixel values array
char* generate_ascii_art(uint8_t* pixels, uint32_t width, uint32_t height, uint8_t threshold) {
    const char ascii_chars[] = " .,-+*?$@#%&";
    const uint32_t ascii_chars_length = sizeof(ascii_chars) - 1;

    // Allocate memory for ASCII art buffer
    uint32_t ascii_art_size = width * height + height + 1;
    char* ascii_art = (char*)malloc(ascii_art_size);
    if (!ascii_art) {
        fprintf(stderr, "Error: failed to allocate memory\n");
        return NULL;
    }

    // Generate ASCII art
    uint32_t pixel_index = 0;
    uint32_t ascii_index = 0;

    for (uint32_t y = 0; y < height; y++) {
        for (uint32_t x = 0; x < width; x++) {
            uint8_t r = pixels[pixel_index++];
            uint8_t g = pixels[pixel_index++];
            uint8_t b = pixels[pixel_index++];
            uint8_t a = pixels[pixel_index++];

            // Convert pixel to grayscale
            uint8_t grayscale = 0.2126 * r + 0.7152 * g + 0.0722 * b;

            // Map grayscale value to corresponding ASCII character
            int32_t ascii_char_index = (ascii_chars_length - 1) * grayscale / 255.0;
            char ascii_char = ascii_chars[ascii_char_index];

            // Add ASCII character to buffer
            ascii_art[ascii_index++] = ascii_char;
        }

        // Add new line to buffer
        ascii_art[ascii_index++] = '\n';
    }

    // Add null terminator to buffer
    ascii_art[ascii_index] = '\0';

    return ascii_art;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: no input file\n");
        return EXIT_FAILURE;
    }

    uint32_t width, height;
    uint8_t* pixels = read_image(argv[1], &width, &height);
    if (!pixels) {
        return EXIT_FAILURE;
    }

    char* ascii_art = generate_ascii_art(pixels, width, height, 128);

    printf("%s\n", ascii_art);

    free(pixels);
    free(ascii_art);

    return EXIT_SUCCESS;
}