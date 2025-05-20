//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// Define ASCII characters to represent brightness levels
const char ascii_chars[] = "@%#*+=-:. ";

int getPixelBrightness(uint8_t r, uint8_t g, uint8_t b) {
    // Calculate brightness using a weighted sum
    return (int)(0.299 * r + 0.587 * g + 0.114 * b);
}

char mapToAscii(int brightness) {
    // Map brightness to a character from the ASCII set
    int index = (brightness * (sizeof(ascii_chars) - 1)) / 255; 
    return ascii_chars[index];
}

void convertImageToAscii(const char *input_file, int width, int height) {
    FILE *fp = fopen(input_file, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", input_file);
        exit(1);
    }

    // Allocate memory for storing pixel values
    uint8_t *image_data = (uint8_t *)malloc(width * height * 3);
    if (!image_data) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(fp);
        exit(1);
    }

    // Read the image file's pixel data (assuming RGB format)
    fread(image_data, 3, width * height, fp);
    fclose(fp);

    // Create ASCII art buffer
    char ascii_art[height + 1][width + 1];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the RGB values of the pixel
            int idx = (y * width + x) * 3;
            uint8_t r = image_data[idx];
            uint8_t g = image_data[idx + 1];
            uint8_t b = image_data[idx + 2];

            // Calculate brightness and map to ASCII
            int brightness = getPixelBrightness(r, g, b);
            ascii_art[y][x] = mapToAscii(brightness);
        }
        ascii_art[y][width] = '\0'; // Null-terminate each line
    }
    
    // Print the ASCII art
    for (int y = 0; y < height; y++) {
        printf("%s\n", ascii_art[y]);
    }

    // Free allocated memory
    free(image_data);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <width> <height>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    convertImageToAscii(input_file, width, height);

    return 0;
}