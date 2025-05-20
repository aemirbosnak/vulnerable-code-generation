//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

// The character set to represent varying pixel intensities
const char* ascii_chars = "@#%*+=-:. ";  // From dark to light

// Structure to represent a pixel
typedef struct {
    uint8_t r, g, b;
} Pixel;

// Function to calculate brightness of a pixel
double calculate_brightness(Pixel pixel) {
    // The perceived brightness formula for RGB
    return 0.2126 * pixel.r + 0.7152 * pixel.g + 0.0722 * pixel.b;
}

// Function to get ASCII character based on brightness
char get_ascii_char(double brightness) {
    int index = (int)((brightness / 255) * (strlen(ascii_chars) - 1));
    return ascii_chars[index];
}

// Function to convert image to ASCII art
void image_to_ascii(const char* filename, int width, int height) {
    FILE* img_file = fopen(filename, "rb");
    if (!img_file) {
        fprintf(stderr, "Ah, what a mystery! Cannot open the image file: %s\n", filename);
        return;
    }

    // Initialize a pixel array based on the width and height
    Pixel* pixels = (Pixel*)malloc(width * height * sizeof(Pixel));
    
    // Reading pixel data is actually very format-specific.
    // This is a rudimentary implementation. A BMP reader would be more complex but let's keep it simple.
    // We will skip the header for the sake of an example purposes, 
    // assuming a specific BMP format: 24 bits per pixel without compression.

    fseek(img_file, 54, SEEK_SET); // Skip BMP header
    fread(pixels, sizeof(Pixel), width * height, img_file);
    fclose(img_file);

    // Herein lies the art, a transformation from pixels to shadows of characters
    printf("\nThe splendid conversion to ASCII art begins!\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Retrieve the current pixel
            Pixel current_pixel = pixels[y * width + x];
            // Calculate the brightness of the pixel
            double brightness = calculate_brightness(current_pixel);
            // Convert to ASCII character
            char ascii_char = get_ascii_char(brightness);
            // Print the ASCII character
            printf("%c", ascii_char);
        }
        printf("\n");
    }

    // Freeing allocated memory is quite vital, akin to closing the case
    free(pixels);
}

// The grand detective's main function, where all begins
int main(int argc, char** argv) {
    printf("Welcome to the grand case of the ASCII Art Conversion!\n");
    
    if (argc != 4) {
        fprintf(stderr, "To solve this enigma, provide the image file and dimensions: <image_file> <width> <height>\n");
        return 1;
    }

    const char* filename = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    printf("Investigating the image: %s, with dimensions of %dx%d.\n", filename, width, height);
    
    // Proceeding with the conversion mystery
    image_to_ascii(filename, width, height);
    
    printf("The case is solved. The ASCII art is complete!\n");
    return 0;
}