//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Adjust these constants to change the output's size and quality
#define ASCII_WIDTH 100
#define ASCII_HEIGHT 40
#define ASCII_CHARS " .:-+=*%@#"

typedef struct {
    unsigned char r, g, b;
} Pixel;

// Function to get the brightness of a pixel
float getPixelBrightness(Pixel pixel) {
    return (0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b) / 255.0;
}

// Function to convert brightness to ASCII character
char brightnessToASCII(float brightness) {
    int index = (int)(brightness * (strlen(ASCII_CHARS) - 1));
    return ASCII_CHARS[index];
}

// Load a PPM image and convert to ASCII
void imageToASCII(const char* filename) {
    // Open PPM file
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    // Read PPM header
    char format[3];
    int width, height, maxVal;
    fscanf(file, "%s %d %d %d", format, &width, &height, &maxVal);
    fgetc(file); // Consume the newline after maxVal

    // Create an image buffer
    Pixel *image = (Pixel *) malloc(width * height * sizeof(Pixel));
    fread(image, sizeof(Pixel), width * height, file);
    fclose(file);

    // Scale down image to fit ASCII dimensions
    int scaledWidth = ASCII_WIDTH;
    int scaledHeight = ASCII_HEIGHT;
    float x_ratio = (float)width / scaledWidth;
    float y_ratio = (float)height / scaledHeight;

    // Output ASCII art
    for (int y = 0; y < scaledHeight; y++) {
        for (int x = 0; x < scaledWidth; x++) {
            int srcX = (int)(x * x_ratio);
            int srcY = (int)(y * y_ratio);
            Pixel pixel = image[srcY * width + srcX];
            float brightness = getPixelBrightness(pixel);
            char ascii = brightnessToASCII(brightness);
            putchar(ascii);
        }
        putchar('\n');
    }

    // Free the image buffer
    free(image);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return 1;
    }
    
    // Convert the image to ASCII art
    imageToASCII(argv[1]);
    
    return 0;
}