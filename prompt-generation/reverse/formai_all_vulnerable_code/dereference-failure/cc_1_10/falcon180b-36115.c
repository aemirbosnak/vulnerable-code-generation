//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLORS 256
#define MAX_PIXELS (WIDTH * HEIGHT)

typedef struct {
    int x, y;
    unsigned char r, g, b;
} Pixel;

Pixel *pixels = NULL;
int num_pixels = 0;

void init_pixels() {
    pixels = malloc(MAX_PIXELS * sizeof(Pixel));
    if (pixels == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for pixels.\n");
        exit(1);
    }
    num_pixels = 0;
}

void add_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (num_pixels >= MAX_PIXELS) {
        fprintf(stderr, "Error: Maximum number of pixels reached.\n");
        exit(1);
    }
    pixels[num_pixels].x = x;
    pixels[num_pixels].y = y;
    pixels[num_pixels].r = r;
    pixels[num_pixels].g = g;
    pixels[num_pixels].b = b;
    num_pixels++;
}

void generate_pixels() {
    srand(time(NULL));
    for (int i = 0; i < num_pixels; i++) {
        int x = pixels[i].x;
        int y = pixels[i].y;
        unsigned char r = rand() % 256;
        unsigned char g = rand() % 256;
        unsigned char b = rand() % 256;
        add_pixel(x, y, r, g, b);
    }
}

void save_pixels_to_file(const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open file for writing.\n");
        exit(1);
    }
    fwrite(pixels, sizeof(Pixel), num_pixels, fp);
    fclose(fp);
}

int main() {
    init_pixels();
    generate_pixels();
    save_pixels_to_file("pixels.bin");
    return 0;
}