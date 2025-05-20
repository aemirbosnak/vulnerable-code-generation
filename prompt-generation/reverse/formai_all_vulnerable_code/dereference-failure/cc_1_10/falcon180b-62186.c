//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLOR 256

typedef struct {
    int x, y;
    int r, g, b;
} pixel;

pixel *pixels;
int num_pixels;

void init_pixels() {
    srand(time(NULL));
    pixels = (pixel *)malloc(WIDTH * HEIGHT * sizeof(pixel));
    num_pixels = 0;
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        int r = rand() % MAX_COLOR;
        int g = rand() % MAX_COLOR;
        int b = rand() % MAX_COLOR;
        pixels[i] = (pixel){x, y, r, g, b};
        num_pixels++;
    }
}

void generate_pixels() {
    for (int i = 0; i < num_pixels; i++) {
        int x = pixels[i].x;
        int y = pixels[i].y;
        int r = pixels[i].r;
        int g = pixels[i].g;
        int b = pixels[i].b;
        for (int j = 0; j < 10; j++) {
            int nx = x + j * cos(atan2(y - HEIGHT / 2, x - WIDTH / 2));
            int ny = y + j * sin(atan2(y - HEIGHT / 2, x - WIDTH / 2));
            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                int index = ny * WIDTH + nx;
                if (pixels[index].r == 0 && pixels[index].g == 0 && pixels[index].b == 0) {
                    pixels[index].r = r;
                    pixels[index].g = g;
                    pixels[index].b = b;
                    num_pixels++;
                }
            }
        }
    }
}

void draw_pixels() {
    for (int i = 0; i < num_pixels; i++) {
        int x = pixels[i].x;
        int y = pixels[i].y;
        int r = pixels[i].r;
        int g = pixels[i].g;
        int b = pixels[i].b;
        printf("%d %d %d\n", r, g, b);
    }
}

int main() {
    init_pixels();
    generate_pixels();
    draw_pixels();
    return 0;
}