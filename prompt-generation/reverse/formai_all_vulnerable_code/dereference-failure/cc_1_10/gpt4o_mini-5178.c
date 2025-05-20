//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_CHARS " .:-=+*%@#"  // Characters used for ASCII representation
#define MAX_WIDTH 100 // Maximum width of the output ASCII art

// Structure to hold the image information
typedef struct {
    unsigned char* data;  // Pointer to pixel data
    int width;            // Image width
    int height;           // Image height
} Image;

// Function to convert an image to grayscale
unsigned char grayscale(unsigned char r, unsigned char g, unsigned char b) {
    return (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b); // Use the luminosity method
}

// Function to load a PPM (P6 format) image
Image loadPPM(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    // Read the PPM header
    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format. Only P6 is supported.\n");
        exit(EXIT_FAILURE);
    }

    int width, height, maxval;
    fscanf(file, "%d %d %d", &width, &height, &maxval);
    fgetc(file); // Skip the newline after the header

    // Dynamic memory allocation for pixel data
    unsigned char* data = (unsigned char*)malloc(width * height * 3);
    fread(data, 1, width * height * 3, file);
    fclose(file);

    Image img = { data, width, height };
    return img;
}

// Function to convert the image to ASCII art
void imageToASCII(const Image* img, int outputWidth) {
    int scale = img->width / outputWidth; // Scaling factor
    int outputHeight = img->height / scale; // Output height
    char asciiChar;

    for (int y = 0; y < outputHeight; y++) {
        for (int x = 0; x < outputWidth; x++) {
            // Calculate the position in the original image honoring the scale
            int pixelIndex = (y * scale * img->width + x * scale) * 3;

            // Fetch RGB values
            unsigned char r = img->data[pixelIndex];
            unsigned char g = img->data[pixelIndex + 1];
            unsigned char b = img->data[pixelIndex + 2];

            // Calculate grayscale value
            unsigned char gray = grayscale(r, g, b);
            int charIndex = gray * (strlen(ASCII_CHARS) - 1) / 255; // Map to ASCII chars

            asciiChar = ASCII_CHARS[charIndex];
            printf("%c", asciiChar); // Output the ASCII character
        }
        printf("\n"); // Move to the next line
    }
}

// Function to free the image data
void freeImage(Image* img) {
    free(img->data);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load the PPM image
    Image img = loadPPM(argv[1]);

    // Convert the image to ASCII art
    imageToASCII(&img, MAX_WIDTH);

    // Free the image memory
    freeImage(&img);

    return EXIT_SUCCESS;
}