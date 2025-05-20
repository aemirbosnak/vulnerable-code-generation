//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLORS 256
#define MAX_PIXELS WIDTH * HEIGHT

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

Pixel *generate_pixels(int num_pixels) {
    Pixel *pixels = malloc(num_pixels * sizeof(Pixel));

    srand(time(0));
    for (int i = 0; i < num_pixels; i++) {
        pixels[i].x = rand() % WIDTH;
        pixels[i].y = rand() % HEIGHT;
        pixels[i].r = rand() % 256;
        pixels[i].g = rand() % 256;
        pixels[i].b = rand() % 256;
    }

    return pixels;
}

void draw_pixel(Pixel pixel, int width, int height, FILE *fp) {
    int x = pixel.x * width / WIDTH;
    int y = pixel.y * height / HEIGHT;

    fprintf(fp, "setPixel(%d, %d, \"#%02X%02X%02X\");\n", x, y, pixel.r, pixel.g, pixel.b);
}

void draw_pixels(Pixel *pixels, int num_pixels, int width, int height, FILE *fp) {
    for (int i = 0; i < num_pixels; i++) {
        draw_pixel(pixels[i], width, height, fp);
    }
}

int main() {
    Pixel *pixels = generate_pixels(MAX_PIXELS);
    FILE *fp = fopen("output.js", "w");

    fprintf(fp, "var canvas = document.getElementById(\"canvas\");\n");
    fprintf(fp, "var ctx = canvas.getContext(\"2d\");\n");

    for (int i = 0; i < MAX_PIXELS; i++) {
        draw_pixel(pixels[i], WIDTH, HEIGHT, fp);
    }

    fclose(fp);
    free(pixels);

    return 0;
}