//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define COLOR_PALETTE_SIZE 3

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

Color colorPalette[COLOR_PALETTE_SIZE] = {
    {255, 0, 0},   // Red
    {0, 255, 0},   // Green
    {0, 0, 255}    // Blue
};

void setPixel(int x, int y, int colorIndex) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }

    int pixelIndex = y * WIDTH + x;
    unsigned char* pixels = calloc(WIDTH * HEIGHT, sizeof(unsigned char));

    pixels[pixelIndex] = colorPalette[colorIndex].r;
    pixels[pixelIndex + WIDTH] = colorPalette[colorIndex].g;
    pixels[pixelIndex + WIDTH * 2] = colorPalette[colorIndex].b;
}

void printPixelArt(unsigned char* pixels) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int pixelIndex = y * WIDTH + x;
            printf("%d %d %d ", pixels[pixelIndex], pixels[pixelIndex + WIDTH], pixels[pixelIndex + WIDTH * 2]);
        }
        printf("\n");
    }
}

int main() {
    setPixel(2, 2, 0);  // Set left eye to blue
    setPixel(3, 2, 0);
    setPixel(4, 2, 0);

    setPixel(2, 4, 1);  // Set right eye to green
    setPixel(3, 4, 1);
    setPixel(4, 4, 1);

    setPixel(3, 3, 2);  // Set mouth to red
    setPixel(2, 3, 2);
    setPixel(4, 3, 2);

    setPixel(4, 5, 2);  // Set teeth to red
    setPixel(3, 5, 2);
    setPixel(2, 5, 2);

    unsigned char* pixels = calloc(WIDTH * HEIGHT, sizeof(unsigned char));

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (x < 3 || x > 6 || y > 3) {
                pixels[y * WIDTH + x] = 0;
                continue;
            }
            pixels[y * WIDTH + x] = pixels[y * WIDTH + x] | 0x80; // Set alpha channel to opaque
        }
    }

    printPixelArt(pixels);

    free(pixels);
    return 0;
}