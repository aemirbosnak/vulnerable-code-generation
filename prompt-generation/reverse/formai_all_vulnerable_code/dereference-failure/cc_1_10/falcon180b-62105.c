//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define PIXELS WIDTH*HEIGHT

int main() {
    int *pixels = (int*)malloc(WIDTH * HEIGHT * sizeof(int));
    int x, y, i;

    // Clear the canvas with white pixels
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            i = x + y*WIDTH;
            pixels[i] = 0xFFFFFF;
        }
    }

    // Draw a circle
    int centerX = WIDTH / 2;
    int centerY = HEIGHT / 2;
    int radius = 200;
    for (y = -radius; y <= radius; y++) {
        int dy = y - centerY;
        int r = sqrt(pow(radius, 2) - pow(dy, 2));
        for (x = -r; x <= r; x++) {
            int dx = x - centerX;
            if (dx*dx + dy*dy <= radius*radius) {
                int i = x + y*WIDTH;
                pixels[i] = 0x000000;
            }
        }
    }

    // Save the pixel data to a file
    FILE *fp = fopen("circle.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }

    fwrite(pixels, sizeof(int), PIXELS, fp);
    fclose(fp);

    free(pixels);

    return 0;
}