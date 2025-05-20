//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLORS 256
#define PIXEL_SIZE 4
#define MAX_ITERATIONS 1000

typedef struct {
    int x, y;
    int color;
} Pixel;

Pixel *generate_mandelbrot(int width, int height, int max_iterations) {
    Pixel *pixels = malloc(sizeof(Pixel) * width * height);
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int x = (j * WIDTH) / width - WIDTH / 2;
            int y = (i * HEIGHT) / height - HEIGHT / 2;
            int iterations = 0;
            while (iterations < max_iterations && x * x + y * y <= 4) {
                iterations++;
                double new_x = x * x - y * y + ((double)rand() / RAND_MAX) * 0.01;
                double new_y = 2 * x * y + ((double)rand() / RAND_MAX) * 0.01;
                x = new_x;
                y = new_y;
            }
            pixels[i * width + j].color = iterations % MAX_COLORS;
        }
    }
    return pixels;
}

void print_pixels(Pixel *pixels, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%02x", pixels[i * width + j].color);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Pixel *pixels = generate_mandelbrot(WIDTH, HEIGHT, MAX_ITERATIONS);
    print_pixels(pixels, WIDTH, HEIGHT);
    free(pixels);
    return 0;
}