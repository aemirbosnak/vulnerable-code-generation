//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_PIXELS (WIDTH * HEIGHT)

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

Pixel* generatePixels(int numPixels) {
    Pixel* pixels = malloc(sizeof(Pixel) * numPixels);
    srand(time(NULL));

    for (int i = 0; i < numPixels; i++) {
        pixels[i].x = rand() % WIDTH;
        pixels[i].y = rand() % HEIGHT;
        pixels[i].r = rand() % 256;
        pixels[i].g = rand() % 256;
        pixels[i].b = rand() % 256;
    }

    return pixels;
}

void drawPixel(Pixel pixel, int* buffer) {
    int index = (pixel.y * WIDTH) + pixel.x;
    if (index >= 0 && index < MAX_PIXELS) {
        buffer[index] = 0x00FFFFFF | (pixel.r << 16) | (pixel.g << 8) | pixel.b;
    }
}

void drawPixels(Pixel* pixels, int numPixels, int* buffer) {
    for (int i = 0; i < numPixels; i++) {
        drawPixel(pixels[i], buffer);
    }
}

int main() {
    Pixel* pixels = generatePixels(MAX_PIXELS);
    int buffer[MAX_PIXELS];

    for (int i = 0; i < MAX_PIXELS; i++) {
        buffer[i] = 0xFF000000;
    }

    drawPixels(pixels, MAX_PIXELS, buffer);

    FILE* fp = fopen("output.bmp", "wb");
    if (!fp) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    fwrite(buffer, sizeof(int), MAX_PIXELS, fp);

    fclose(fp);

    return 0;
}