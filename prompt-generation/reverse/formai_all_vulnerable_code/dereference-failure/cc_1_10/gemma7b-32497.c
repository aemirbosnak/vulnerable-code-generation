//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fractal(int x, int y, int zoom, int max_iter, int **img) {
    int i, j;
    for (i = x - zoom; i <= x + zoom; i++) {
        for (j = y - zoom; j <= y + zoom; j++) {
            int iter = 0;
            for (int r = 0; r < max_iter; r++) {
                double x1 = (double)i / zoom * 2 - 1.0;
                double x2 = (double)j / zoom * 2 - 1.0;
                double z = x1 * x1 + x2 * x2;
                if (z > 4) {
                    iter = r;
                    break;
                }
                x1 = x2 * x2 - x1 * x1;
                x2 = 2.0 * x1 * x2;
            }
            img[i][j] = iter;
        }
    }
}

int main() {
    int max_iter = 255;
    int zoom = 16;
    int x_max = 1024;
    int y_max = 1024;
    int **img = (int**)malloc(x_max * sizeof(int *));
    for (int i = 0; i < x_max; i++) {
        img[i] = (int *)malloc(y_max * sizeof(int));
    }

    fractal(x_max / 2, y_max / 2, zoom, max_iter, img);

    // Display the fractal
    for (int i = 0; i < x_max; i++) {
        for (int j = 0; j < y_max; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < x_max; i++) {
        free(img[i]);
    }
    free(img);

    return 0;
}