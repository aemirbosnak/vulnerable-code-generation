//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

int mandelbrot(int x, int y)
{
    int iterations = 0;
    double real = 0, imag = 0;
    double xmin, xmax, ymin, ymax;

    xmin = (double)x / WIDTH * 3 - 2;
    xmax = (double)x / WIDTH * 3 + 2;
    ymin = (double)y / HEIGHT * 2 - 1;
    ymax = (double)y / HEIGHT * 2 + 1;

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        real = xmin + (xmax - xmin) * i / MAX_ITERATIONS;
        imag = ymin + (ymax - ymin) * i / MAX_ITERATIONS;

        if (real * real + imag * imag > 4) {
            break;
        }
    }

    return iterations;
}

void render(int* buffer)
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int iterations = mandelbrot(x, y);
            int color = iterations % 8 * 32;

            buffer[y * WIDTH + x] = color;
        }
    }
}

int main()
{
    int* buffer = malloc(WIDTH * HEIGHT * sizeof(int));

    render(buffer);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", buffer[y * WIDTH + x]);
        }
        printf("\n");
    }

    free(buffer);

    return 0;
}