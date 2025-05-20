//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: irregular
// This is not a real image editor, it's just a weird thing I made
// Because why not, amirite? 😜

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <float.h>

#define WIDTH  1024
#define HEIGHT 1024
#define BITS   32
#define BG_COLOR 0x000000ff
#define FG_COLOR 0xffffffff

typedef struct {
    int x, y;
    unsigned char color;
} Pixel;

typedef struct {
    Pixel pixels[WIDTH * HEIGHT];
} Image;

Image* load_image(const char* filename) {
    Image* image = malloc(sizeof(Image));
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open %s\n", filename);
        return image;
    }
    fread(image->pixels, sizeof(Pixel), WIDTH * HEIGHT, file);
    fclose(file);
    return image;
}

void draw_line(Image* image, int x1, int y1, int x2, int y2) {
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            Pixel* pixel = &image->pixels[y * WIDTH + x];
            pixel->color = (x == x1 && y == y1) ? FG_COLOR : BG_COLOR;
        }
    }
}

void draw_rectangle(Image* image, int x, int y, int width, int height) {
    for (int x1 = x; x1 <= x + width; x1++) {
        for (int y1 = y; y1 <= y + height; y1++) {
            Pixel* pixel = &image->pixels[y1 * WIDTH + x1];
            pixel->color = (x1 == x && y1 == y) ? FG_COLOR : BG_COLOR;
        }
    }
}

void save_image(Image* image, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to open %s\n", filename);
        return;
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Pixel* pixel = &image->pixels[y * WIDTH + x];
            fputc(pixel->color & 0xff, file);
            fputc((pixel->color >> 8) & 0xff, file);
            fputc((pixel->color >> 16) & 0xff, file);
            fputc((pixel->color >> 24) & 0xff, file);
        }
    }
    fclose(file);
}

int main() {
    srand(time(NULL));
    Image* image = load_image("example.bmp");
    draw_line(image, 100, 100, 200, 300);
    draw_rectangle(image, 500, 500, 200, 100);
    save_image(image, "output.bmp");
    free(image);
    return 0;
}