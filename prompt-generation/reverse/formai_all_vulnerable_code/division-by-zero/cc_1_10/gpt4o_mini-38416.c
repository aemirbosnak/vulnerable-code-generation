//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ASCII_CHARS "@%#*+=-:. " // You can customize this string
#define MAX_WIDTH 100            // Max width of ASCII output

// Function to get the grayscale value of a pixel
uint8_t get_grayscale_value(uint8_t r, uint8_t g, uint8_t b) {
    return (uint8_t)(0.299 * r + 0.587 * g + 0.114 * b);
}

// Function to map grayscale value to ASCII
char map_grayscale_to_ascii(uint8_t grayscale) {
    int index = (grayscale * (strlen(ASCII_CHARS) - 1)) / 255;
    return ASCII_CHARS[index];
}

// Function to load a PPM image
uint8_t* load_ppm(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    // Read PPM header
    char header[3];
    fscanf(file, "%2s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported file format.\n");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", width, height);
    int max_color_val;
    fscanf(file, "%d", &max_color_val);
    fgetc(file); // Consume the newline character

    // Allocate memory for pixel data
    uint8_t* pixels = (uint8_t*)malloc((*width) * (*height) * 3);
    fread(pixels, 3, (*width) * (*height), file);
    fclose(file);

    return pixels;
}

// Function to convert image to ASCII art
void convert_to_ascii(uint8_t* pixels, int width, int height) {
    int new_width = MAX_WIDTH;
    int new_height = (height * MAX_WIDTH) / width;
    char ascii_art[new_height][new_width + 1];

    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            // Original pixel corresponding to the ASCII art
            int orig_x = x * width / new_width;
            int orig_y = y * height / new_height;

            int pixel_index = (orig_y * width + orig_x) * 3;
            uint8_t r = pixels[pixel_index];
            uint8_t g = pixels[pixel_index + 1];
            uint8_t b = pixels[pixel_index + 2];
            uint8_t gray = get_grayscale_value(r, g, b);

            ascii_art[y][x] = map_grayscale_to_ascii(gray);
        }
        ascii_art[y][new_width] = '\0'; // Null-terminate the string
    }

    // Print the ASCII art
    for (int i = 0; i < new_height; i++) {
        printf("%s\n", ascii_art[i]);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_ppm_image>\n", argv[0]);
        return 1;
    }

    int width, height;
    uint8_t* pixels = load_ppm(argv[1], &width, &height);
    if (!pixels) {
        return 1; // Loading failed
    }

    convert_to_ascii(pixels, width, height);
    
    free(pixels); // Clean up the allocated memory
    return 0;
}