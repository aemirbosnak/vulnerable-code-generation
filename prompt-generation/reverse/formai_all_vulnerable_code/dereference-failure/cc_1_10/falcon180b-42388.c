//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

typedef struct Point {
    double x;
    double y;
} Point;

void fractal(int x, int y, double **matrix) {
    double real = 0.0;
    double imag = 0.0;
    int i;

    for (i = 0; i < MAX_ITER; i++) {
        real = real * real - imag * imag + x;
        imag = 2.0 * real * imag + y;

        if (real * real + imag * imag > 4.0) {
            matrix[i][y] = 0.0;
            return;
        }
    }

    matrix[i][y] = 1.0;
}

void generateFractal(double **matrix) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fractal(j, i, matrix);
        }
    }
}

void savePPM(double **matrix, char *filename) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "wb");

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_ITER);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fprintf(fp, "%d ", matrix[i][j] * 255);
        }
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    double **matrix = (double **)malloc(HEIGHT * sizeof(double *));
    int i;

    for (i = 0; i < HEIGHT; i++) {
        matrix[i] = (double *)malloc(WIDTH * sizeof(double));
    }

    generateFractal(matrix);
    savePPM(matrix, "fractal.ppm");

    for (i = 0; i < HEIGHT; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}