//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 1000
#define MAX_PIXELS (MAX_SIZE * MAX_SIZE)

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width, height;
} Image;

void init_image(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->pixels = (Pixel *)malloc(MAX_PIXELS * sizeof(Pixel));
}

void set_pixel(Image *img, int x, int y, int r, int g, int b) {
    int index = y * img->width + x;
    if (index >= 0 && index < MAX_PIXELS) {
        img->pixels[index].x = x;
        img->pixels[index].y = y;
        img->pixels[index].r = r;
        img->pixels[index].g = g;
        img->pixels[index].b = b;
    }
}

void draw_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int index = y * img->width + x;
            if (index >= 0 && index < MAX_PIXELS) {
                Pixel *p = &img->pixels[index];
                printf("%d,%d,%d\n", p->x, p->y, p->r);
            }
        }
    }
}

int main() {
    Image img;
    init_image(&img, 50, 50);
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            set_pixel(&img, j, i, rand() % 256, rand() % 256, rand() % 256);
        }
    }
    draw_image(&img);
    return 0;
}