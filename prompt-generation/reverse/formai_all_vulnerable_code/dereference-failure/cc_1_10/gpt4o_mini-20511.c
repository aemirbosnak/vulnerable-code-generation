//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ASCII 10
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Mapping intensity to ASCII characters
const char asciiChars[MAX_ASCII] = "@%#*+=-:. ";

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function to load a PGM image
Image* loadPGM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        return NULL;
    }

    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), file)) {
        fprintf(stderr, "Invalid PGM file.\n");
        fclose(file);
        return NULL;
    }

    if (buffer[0] != 'P' || buffer[1] != '5') {
        fprintf(stderr, "Not a valid PGM file.\n");
        fclose(file);
        return NULL;
    }

    // Read image size information
    int width, height, maxval;
    fscanf(file, "%d %d %d", &width, &height, &maxval);
    fgetc(file); // consume newline after maxval

    if (width <= 0 || width > MAX_WIDTH || height <= 0 || height > MAX_HEIGHT || maxval != 255) {
        fprintf(stderr, "Invalid image dimensions or max value.\n");
        fclose(file);
        return NULL;
    }

    // Allocate memory for image data
    unsigned char *data = (unsigned char*)malloc(width * height);
    if (!data) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }

    // Read the pixel data
    fread(data, sizeof(unsigned char), width * height, file);
    fclose(file);

    // Create and return the Image struct
    Image *img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = data;
    return img;
}

// Function to convert image pixels to ASCII art
void convertToASCII(Image *img) {
    if (!img || !img->data) return;

    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            // Get the pixel value
            unsigned char pixel = img->data[y * img->width + x];
            // Map pixel intensity to ASCII character
            char asciiChar = asciiChars[(pixel * (MAX_ASCII - 1)) / 255];
            putchar(asciiChar);
        }
        putchar('\n'); // New line for each row
    }
}

// Function to clean up image memory
void freeImage(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

// Main function to drive the program
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = loadPGM(argv[1]);
    if (!img) {
        return EXIT_FAILURE;
    }

    // Convert loaded image to ASCII art
    convertToASCII(img);

    // Free allocated resources
    freeImage(img);
    return EXIT_SUCCESS;
}