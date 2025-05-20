//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ROWS 50
#define COLS 80
#define ZOOM 2
#define WIDTH 1600
#define HEIGHT 1200
#define MAX_ITER 1000
#define THRESHOLD 4

int mandelbrot(int x, int y)
{
    int i, zx = x, zy = y, n = 0;
    double real = x / (WIDTH / COLS) * 3.5 - 2.5, imag = y / (HEIGHT / ROWS) * 2 - 1;

    for (i = 0; i < MAX_ITER && n < THRESHOLD; i++) {
        double zr = real * real - imag * imag + zx;
        imag = 2 * real * imag + zy;
        real = zr;
        zx = real;
        zy = imag;
        n++;
    }

    return n % 8;
}

void generate_mandelbrot(int **data)
{
    int x, y;
    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            data[y][x] = mandelbrot(x, y);
        }
    }
}

void print_mandelbrot(int **data)
{
    int x, y;
    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            printf("%c", data[y][x] + '0');
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int **data = malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        data[i] = malloc(COLS * sizeof(int));
    }
    generate_mandelbrot(data);
    print_mandelbrot(data);
    for (int i = 0; i < ROWS; i++) {
        free(data[i]);
    }
    free(data);
    return 0;
}