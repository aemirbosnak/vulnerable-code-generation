//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600
#define PIXEL_SIZE 4
#define MAX_COLOR 255

// Function to generate a random color
int getRandomColor() {
    int r = rand() % MAX_COLOR;
    int g = rand() % MAX_COLOR;
    int b = rand() % MAX_COLOR;
    return rand() % 2 == 0? (r << 16) + (g << 8) + b : (b << 16) + (g << 8) + r;
}

// Function to draw a pixel
void drawPixel(int x, int y, int color) {
    int index = (y * WIDTH + x) * PIXEL_SIZE;
    unsigned char *pixel = (unsigned char *)malloc(PIXEL_SIZE);
    for (int i = 0; i < PIXEL_SIZE; i++) {
        pixel[i] = color >> (8 * i) & 0xFF;
    }
    fwrite(pixel, PIXEL_SIZE, 1, stdout);
    free(pixel);
}

// Function to generate a random shape
void generateShape(int x, int y, int size, int color) {
    int halfSize = size / 2;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i >= halfSize && i < size - halfSize && j >= halfSize && j < size - halfSize) {
                drawPixel(x + i, y + j, color);
            }
        }
    }
}

// Function to generate a random pixel art image
void generateImage() {
    srand(time(NULL));
    int bgColor = getRandomColor();
    int fgColor = getRandomColor();

    // Fill background with random color
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            drawPixel(x, y, bgColor);
        }
    }

    // Generate random shapes with random colors
    for (int i = 0; i < 100; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        int size = rand() % 50 + 10;
        int color = getRandomColor();
        generateShape(x, y, size, color);
    }
}

int main() {
    generateImage();
    return 0;
}