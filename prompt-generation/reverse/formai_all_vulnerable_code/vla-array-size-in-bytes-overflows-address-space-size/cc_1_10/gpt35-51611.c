//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Change these values to adjust the size of the ASCII "pixels"
#define WIDTH_SCALE 2
#define HEIGHT_SCALE 4

// Function declaration
void convert_image_to_ascii(char* image_path);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ./ascii_converter <image_path>\n");
        exit(EXIT_FAILURE);
    }
    char image_path[strlen(argv[1])];
    strcpy(image_path, argv[1]);
    convert_image_to_ascii(image_path);
    return 0;
}

void convert_image_to_ascii(char* image_path) {
    FILE* image_file = fopen(image_path, "rb");
    if (!image_file) {
        printf("Error opening image file.\n");
        exit(EXIT_FAILURE);
    }
    // Read image header information
    char header[54];
    fread(header, sizeof(char), 54, image_file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = 0;
    while ((width * 3 + padding) % 4 != 0) {
        padding++;
    }
    // Allocate memory for image pixel data
    int pixel_bytes_size = width * height * 3;
    char* pixel_data = (char*) malloc(pixel_bytes_size);
    fread(pixel_data, sizeof(char), pixel_bytes_size, image_file);

    // Convert each pixel to ASCII character
    char ascii_pixels[height * WIDTH_SCALE][width * HEIGHT_SCALE];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Calculate RGB values of pixel
            int b = pixel_data[i * width * 3 + j * 3];
            int g = pixel_data[i * width * 3 + j * 3 + 1];
            int r = pixel_data[i * width * 3 + j * 3 + 2];
            // Calculate brightness of pixel
            int brightness = (0.2126 * r) + (0.7152 * g) + (0.0722 * b);
            // Map brightness value to ASCII character
            int index = (brightness / (255/(WIDTH_SCALE * HEIGHT_SCALE))) - 1;
            if (index < 0) {
                index = 0;
            }
            if (index >= WIDTH_SCALE * HEIGHT_SCALE) {
                index = WIDTH_SCALE * HEIGHT_SCALE - 1;
            }
            char pixel_char = "@%#*+=-:. "[index];
            // Add ASCII character to pixel array
            for (int k = 0; k < WIDTH_SCALE; k++) {
                for (int l = 0; l < HEIGHT_SCALE; l++) {
                    ascii_pixels[i * WIDTH_SCALE + k][j * HEIGHT_SCALE + l] = pixel_char;
                }
            }
        }
    }

    // Print ASCII image to console
    for (int i = 0; i < height * WIDTH_SCALE; i++) {
        for (int j = 0; j < width * HEIGHT_SCALE; j++) {
            putchar(ascii_pixels[i][j]);
        }
        putchar('\n');
    }

    // Clean up memory and close file
    free(pixel_data);
    fclose(image_file);
}