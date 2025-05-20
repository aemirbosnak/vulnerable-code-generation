//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

#define RED 0
#define GREEN 1
#define BLUE 2

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

Pixel *pixels;
int num_pixels;

void init() {
    srand(time(NULL));
    pixels = malloc(WIDTH * HEIGHT * sizeof(Pixel));
    num_pixels = 0;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            pixels[num_pixels].x = i;
            pixels[num_pixels].y = j;
            pixels[num_pixels].r = r;
            pixels[num_pixels].g = g;
            pixels[num_pixels].b = b;
            num_pixels++;
        }
    }
}

void draw() {
    for (int i = 0; i < num_pixels; i++) {
        Pixel pixel = pixels[i];
        int x = pixel.x;
        int y = pixel.y;
        int r = pixel.r;
        int g = pixel.g;
        int b = pixel.b;
        printf("setrgbcolor(%d,%d,%d)\n", r, g, b);
        printf("drawrectangle(%d,%d,%d,%d)\n", x - 1, y - 1, x + 1, y + 1);
    }
}

int main() {
    init();
    draw();
    return 0;
}