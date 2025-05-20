//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel_t;

// Function to convert RGB values to grayscale
uint8_t RGBToGrayscale(uint8_t red, uint8_t green, uint8_t blue);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error: No image file specified\n");
        return 1;
    }
    char* filename = argv[1];
    FILE* f = fopen(filename, "rb");
    if (!f) {
        printf("Error: Unable to open image file\n");
        return 1;
    }
    char magic[3];
    fscanf(f, "%2s", magic);
    if (strcmp(magic, "P6") != 0) {
        printf("Error: Invalid file format\n");
        return 1;
    }
    fseek(f, 1, SEEK_CUR);
    int width, height, depth;
    fscanf(f, "%d %d\n%d\n", &width, &height, &depth);
    if (depth != 255) {
        printf("Error: Invalid color depth\n");
        return 1;
    }
    pixel_t* pixels = (pixel_t*)malloc(width * height * sizeof(pixel_t));
    fread(pixels, sizeof(pixel_t), width * height, f);
    fclose(f);
    uint8_t* grayscale = (uint8_t*)malloc(width * height * sizeof(uint8_t));
    // Convert RGB image to grayscale
    for (int i = 0; i < width * height; i++) {
        grayscale[i] = RGBToGrayscale(pixels[i].red, pixels[i].green, pixels[i].blue);
    }
    // Convert grayscale pixels to ASCII characters
    char* ascii = (char*)malloc(width * height * sizeof(char));
    for (int i = 0; i < width * height; i++) {
        if (grayscale[i] < 25) {
            ascii[i] = '#';
        } else if (grayscale[i] < 50) {
            ascii[i] = '&';
        } else if (grayscale[i] < 75) {
            ascii[i] = '*';
        } else if (grayscale[i] < 100) {
            ascii[i] = 'o';
        } else if (grayscale[i] < 125) {
            ascii[i] = ':';
        } else if (grayscale[i] < 150) {
            ascii[i] = '-';
        } else if (grayscale[i] < 175) {
            ascii[i] = '.';
        } else if (grayscale[i] < 200) {
            ascii[i] = ' ';
        } else {
            ascii[i] = ' ';
        }
    }
    // Print ASCII art to console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii[i * width + j]);
        }
        printf("\n");
    }
    free(pixels);
    free(grayscale);
    free(ascii);
    return 0;
}

uint8_t RGBToGrayscale(uint8_t red, uint8_t green, uint8_t blue) {
    return 0.299 * red + 0.587 * green + 0.114 * blue;
}