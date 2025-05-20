//FormAI DATASET v1.0 Category: Fractal Generation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define SIZE 400
#define MAX_ITER 1000

typedef struct {
    double x;
    double y;
} complex;

int mandelbrot(complex c) {
    complex z = {0, 0};
    int i;

    for (i = 0; i < MAX_ITER; i++) {
        double x = z.x * z.x - z.y * z.y + c.x;
        double y = 2 * z.x * z.y + c.y;
        z.x = x;
        z.y = y;

        if (z.x * z.x + z.y * z.y > 4) {
            return i;
        }
    }

    return -1;
}

void display(int *array) {
    int i, j;

    for (i = SIZE; i > 0; i--) {
        for (j = 0; j < SIZE; j++) {
            if (array[i * SIZE + j] >= 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    complex center = {0.0, 0.0};
    double zoom = 1.0;
    int *array = malloc(SIZE * SIZE * sizeof(int));

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            double x = (j - SIZE / 2.0) * 4 / (zoom * SIZE) + center.x;
            double y = (i - SIZE / 2.0) * 4 / (zoom * SIZE) + center.y;
            complex c = {x, y};
            array[i * SIZE + j] = mandelbrot(c);
        }
    }

    display(array);

    free(array);

    return 0;
}