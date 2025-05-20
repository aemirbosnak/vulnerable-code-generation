//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000
#define ZOOM 1.5
#define OFFSET_X -400
#define OFFSET_Y -300
#define COLOR_MAP_SIZE 256

int color_map[COLOR_MAP_SIZE];

void init_color_map() {
    for (int i = 0; i < COLOR_MAP_SIZE; i++) {
        double r = (double)i / (double)COLOR_MAP_SIZE;
        double g = 0.0;
        double b = 0.0;
        if (r < 0.33) {
            g = 4.0 * r;
            b = 0.0;
        } else if (r < 0.66) {
            g = 1.0;
            b = 4.0 * (r - 0.33);
        } else {
            g = 0.0;
            b = 1.0;
        }
        color_map[i] = (int)((double)i / (double)COLOR_MAP_SIZE * 255.0);
    }
}

int mandelbrot(double x, double y) {
    int iterations = 0;
    double real = 0.0;
    double imag = 0.0;
    while (iterations < MAX_ITERATIONS && real * real + imag * imag < 4.0) {
        double real_new = real * real - imag * imag + x;
        imag = 2.0 * real * imag + y;
        real = real_new;
        iterations++;
    }
    return iterations % COLOR_MAP_SIZE;
}

void render(int* buffer, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double real = (double)x / (double)width * 3.5 - 2.5;
            double imag = (double)y / (double)height * 2.0 - 1.0;
            int color = mandelbrot(real, imag);
            buffer[y * width + x] = color_map[color];
        }
    }
}

int main() {
    srand(time(0));
    init_color_map();

    int* buffer = malloc(WIDTH * HEIGHT * sizeof(int));

    for (double zoom = ZOOM; zoom >= 1.0 / ZOOM; zoom -= 1.0 / ZOOM) {
        double offset_x = OFFSET_X / zoom;
        double offset_y = OFFSET_Y / zoom;

        render(buffer, WIDTH, HEIGHT);

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                int value = buffer[(int)(y * zoom + offset_y) * WIDTH + (int)(x * zoom + offset_x)];
                printf("%d ", value);
            }
            printf("\n");
        }
        printf("\n");
    }

    free(buffer);
    return 0;
}