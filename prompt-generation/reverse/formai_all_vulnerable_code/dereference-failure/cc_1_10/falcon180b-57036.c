//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256

#define THRESHOLD 0.7
#define MAX_ITER 1000

#define RAND_SEED 42

typedef struct {
    int x, y;
} Point;

typedef struct {
    int x, y, z;
} Vector;

void rand_vector(Vector *v) {
    v->x = rand() % 100 - 50;
    v->y = rand() % 100 - 50;
    v->z = rand() % 100 - 50;
}

double rand_double() {
    return (double)rand() / RAND_MAX;
}

void rand_point(Point *p) {
    p->x = rand() % WIDTH;
    p->y = rand() % HEIGHT;
}

int in_range(int x, int min, int max) {
    return x >= min && x < max;
}

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void mandelbrot(int x, int y, double *result) {
    double real = 0, imag = 0;
    int iter = 0;

    while (iter < MAX_ITER && pow(real, 2) + pow(imag, 2) < 4) {
        double tmp = real * real - imag * imag + x;
        imag = 2 * real * imag + y;
        real = tmp;
        iter++;
    }

    *result = iter / (double)MAX_ITER;
}

int main() {
    srand(RAND_SEED);

    double **watermark = malloc(sizeof(double *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        watermark[i] = malloc(sizeof(double) * WIDTH);
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            mandelbrot(j, i, &watermark[i][j]);
        }
    }

    FILE *fp = fopen("image.pgm", "wb");

    fprintf(fp, "P5\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fprintf(fp, "%d ", (int)(255 * watermark[i][j]));
        }
    }

    fclose(fp);

    return 0;
}