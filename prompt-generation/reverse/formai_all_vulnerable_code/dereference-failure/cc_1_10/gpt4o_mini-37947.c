//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS " .:-=+*%@#"
#define ASCII_CHARS_LEN 10

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel pixels[MAX_HEIGHT][MAX_WIDTH];
} Image;

Image* loadImage(const char* filename);
void convertToAsciiArt(Image* img, int newWidth, const char* outputFilename);
char pixelToAscii(Pixel pixel);
void freeImage(Image* img);

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii> <new_width>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* inputImage = argv[1];
    const char* outputAscii = argv[2];
    int newWidth = atoi(argv[3]);

    if (newWidth <= 0 || newWidth > MAX_WIDTH) {
        fprintf(stderr, "Width must be between 1 and %d\n", MAX_WIDTH);
        return EXIT_FAILURE;
    }

    Image* img = loadImage(inputImage);
    if (!img) {
        fprintf(stderr, "Failed to load image\n");
        return EXIT_FAILURE;
    }

    convertToAsciiArt(img, newWidth, outputAscii);

    freeImage(img);
    return EXIT_SUCCESS;
}

Image* loadImage(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    Image* img = malloc(sizeof(Image));
    if (!img) {
        fclose(file);
        return NULL;
    }

    // For simplicity, we will read a fixed-size image of MAX_WIDTH x MAX_HEIGHT
    img->width = MAX_WIDTH;
    img->height = MAX_HEIGHT;

    // Load the pixel data (dummy implementation)
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            img->pixels[y][x].r = rand() % 256;
            img->pixels[y][x].g = rand() % 256;
            img->pixels[y][x].b = rand() % 256;
        }
    }

    fclose(file);
    return img;
}

char pixelToAscii(Pixel pixel) {
    // Convert pixel color to grayscale
    int grayscale = (pixel.r + pixel.g + pixel.b) / 3;
    int index = (grayscale * (ASCII_CHARS_LEN - 1)) / 255; // Map grayscale to ASCII character
    return ASCII_CHARS[index];
}

void convertToAsciiArt(Image* img, int newWidth, const char* outputFilename) {
    FILE* file = fopen(outputFilename, "w");
    if (!file) {
        fprintf(stderr, "Failed to open output file\n");
        return;
    }

    // Compute the aspect ratio
    double aspectRatio = (double)img->width / img->height;
    int newHeight = (int)(newWidth / aspectRatio);

    for (int y = 0; y < newHeight; y++) {
        for (int x = 0; x < newWidth; x++) {
            int srcX = (int)((double)x * img->width / newWidth);
            int srcY = (int)((double)y * img->height / newHeight);
            
            Pixel currentPixel = img->pixels[srcY][srcX];
            char asciiChar = pixelToAscii(currentPixel);
            fputc(asciiChar, file);
        }
        fputc('\n', file);
    }

    fclose(file);
}

void freeImage(Image* img) {
    free(img);
}