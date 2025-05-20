//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define ASCII_WIDTH 70
#define ASCII_HEIGHT 40
#define GRAY_SCALE_CHARACTERS "@%#*+=-:. "

typedef struct {
    uint8_t r, g, b;
} RGB;

typedef struct {
    RGB* pixels;
    int width, height;
} Image;

void freeImage(Image* img) {
    free(img->pixels);
    img->pixels = NULL;
    img->width = 0;
    img->height = 0;
}

Image* loadImage(const char* filename) {
    // Load a PPM (P6) image from a file for simplicity.
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return NULL;
    }

    char header[3];
    fscanf(file, "%2s", header);
    
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Error: Unsupported image format. Use P6 (PPM).\n");
        fclose(file);
        return NULL;
    }

    int width, height, maxval;
    fscanf(file, "%d %d %d", &width, &height, &maxval);
    fgetc(file); // Consume the newline after maxval.

    Image* img = (Image*)malloc(sizeof(Image));
    img->pixels = (RGB*)malloc(sizeof(RGB) * width * height);
    img->width = width;
    img->height = height;

    fread(img->pixels, sizeof(RGB), width * height, file);
    fclose(file);
    
    return img;
}

int getGrayScaleValue(RGB pixel) {
    // Convert RGB to grayscale using the luminosity method.
    return (int)(0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b);
}

char mapGrayscaleToChar(int gray) {
    int index = (gray * (strlen(GRAY_SCALE_CHARACTERS) - 1)) / 255;
    return GRAY_SCALE_CHARACTERS[index];
}

void generateASCIIArt(Image* img) {
    for (int y = 0; y < img->height; y += img->height / ASCII_HEIGHT) {
        for (int x = 0; x < img->width; x += img->width / ASCII_WIDTH) {
            int pixelIndex = (y * img->width) + x;
            RGB pixel = img->pixels[pixelIndex];
            int grayValue = getGrayScaleValue(pixel);
            char asciiChar = mapGrayscaleToChar(grayValue);
            putchar(asciiChar);
        }
        putchar('\n');
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image* image = loadImage(argv[1]);
    if (!image) {
        return EXIT_FAILURE;
    }

    generateASCIIArt(image);
    freeImage(image);
    free(image);

    return EXIT_SUCCESS;
}