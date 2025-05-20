//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define the ASCII characters used for shades
const char* asciiChars = "@%#*+=-:. "; // From darkest to lightest

// Function to convert pixel to ASCII based on its brightness
char pixelToAscii(int r, int g, int b) {
    // Calculate brightness
    float brightness = (r * 0.299 + g * 0.587 + b * 0.114);
    int index = (int)(brightness / 255.0 * (strlen(asciiChars) - 1));
    return asciiChars[index];
}

// Function to read the PPM image format
unsigned char* readPPM(const char* filename, int* width, int* height) {
    FILE* f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }

    // Read PPM header
    char buffer[16];
    fgets(buffer, sizeof(buffer), f);
    if (strcmp(buffer, "P6\n") != 0) {
        fprintf(stderr, "Not a PPM file\n");
        fclose(f);
        return NULL;
    }

    // Read width and height
    fscanf(f, "%d %d", width, height);
    int maxVal;
    fscanf(f, "%d", &maxVal);
    fgetc(f); // consume newline character

    // Allocate memory for image data
    unsigned char* data = (unsigned char*)malloc(*width * *height * 3);
    fread(data, 3, *width * *height, f);
    fclose(f);
    return data;
}

// Function to convert the image to ASCII art
void convertToAsciiArt(unsigned char* imageData, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            int r = imageData[index];
            int g = imageData[index + 1];
            int b = imageData[index + 2];
            char asciiChar = pixelToAscii(r, g, b);
            putchar(asciiChar);
        }
        putchar('\n'); // Move to next line after each row
    }
}

// Function to free the image data
void freeImageData(unsigned char* data) {
    if (data) {
        free(data);
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    unsigned char* imageData = readPPM(argv[1], &width, &height);
    if (!imageData) {
        return EXIT_FAILURE;
    }

    printf("Generating ASCII art for image: %s (Width: %d, Height: %d)\n", argv[1], width, height);
    convertToAsciiArt(imageData, width, height);
    
    freeImageData(imageData);
    return EXIT_SUCCESS;
}