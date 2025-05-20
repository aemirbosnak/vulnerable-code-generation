//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define ASCII_CHARS "@%#*+=-:. "
#define MAX_COLOR_VALUE 255

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

void getBrightness(Pixel pixel, int* brightness) {
    *brightness = (int)(0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b);
}

char getAsciiChar(int brightness) {
    int index = (brightness * (strlen(ASCII_CHARS) - 1)) / MAX_COLOR_VALUE;
    return ASCII_CHARS[index];
}

Pixel* loadImage(const char* filename, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    // Read the image header
    fseek(fp, 18, SEEK_SET);
    fread(width, sizeof(int), 1, fp);
    fread(height, sizeof(int), 1, fp);
    fseek(fp, 54, SEEK_SET); // Skip to the pixel data

    Pixel* image = (Pixel*)malloc((*width) * (*height) * sizeof(Pixel));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    fread(image, sizeof(Pixel), (*width) * (*height), fp);
    fclose(fp);
    return image;
}

void convertToAscii(Pixel* image, int width, int height) {
    int brightness;
    char asciiArt[height][width + 1];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            getBrightness(image[y * width + x], &brightness);
            asciiArt[y][x] = getAsciiChar(brightness);
        }
        asciiArt[y][width] = '\0'; // Null-terminate string
    }

    // Print ASCII art
    for (int y = 0; y < height; y++) {
        printf("%s\n", asciiArt[y]);
    }
}

void freeImage(Pixel* image) {
    free(image);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    int width, height;
    Pixel* image = loadImage(argv[1], &width, &height);

    printf("Loaded image %s with width %d and height %d\n", argv[1], width, height);
    printf("Converting image to ASCII art!\n");

    convertToAscii(image, width, height);
    
    printf("ASCII art conversion done! Brace yourself for the visual shock!\n");
    
    freeImage(image);
    return 0;
}