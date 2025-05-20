//FormAI DATASET v1.0 Category: Fractal Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Function to generate fractal */
void generateFractal(int **fractal, int x1, int y1, int x2, int y2, int depth);

/* Main function to test fractal generation */
int main() {
    /* Initialize random seed */
    srand(time(NULL));

    /* Set fractal size */
    int size = 21;

    /* Allocate memory for fractal */
    int **fractal = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        fractal[i] = (int *) malloc(size * sizeof(int));
    }

    /* Generate fractal */
    generateFractal(fractal, 0, 0, size - 1, size - 1, 2);

    /* Print fractal */
    printf("Fractal:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", fractal[i][j]);
        }
        printf("\n");
    }

    /* Free memory */
    for (int i = 0; i < size; i++) {
        free(fractal[i]);
    }
    free(fractal);

    /* Exit program */
    return 0;
}

/* Function to generate fractal */
void generateFractal(int **fractal, int x1, int y1, int x2, int y2, int depth) {
    /* Base case */
    if (depth == 0) {
        int r = rand() % 256;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                fractal[i][j] = r;
            }
        }
        return;
    }

    /* Recursive case */
    int cx = (x1 + x2) / 2;
    int cy = (y1 + y2) / 2;

    generateFractal(fractal, x1, y1, cx, cy, depth - 1);
    generateFractal(fractal, cx + 1, y1, x2, cy, depth - 1);
    generateFractal(fractal, x1, cy + 1, cx, y2, depth - 1);
    generateFractal(fractal, cx + 1, cy + 1, x2, y2, depth - 1);

    /* Interpolate values */
    for (int i = x1 + 1; i < cx; i++) {
        for (int j = y1 + 1; j < cy; j++) {
            int s = fractal[x1][y1] + fractal[x1][y2] + fractal[x2][y1] + fractal[x2][y2];
            int t = fractal[x1][j] + fractal[x2][j] + fractal[i][y1] + fractal[i][y2];
            int u = fractal[x1][j] + fractal[x2][j] + fractal[i][y1] + fractal[i][y2];
            fractal[i][j] = (s + 2 * t + 4 * u) / 14 + rand() % 14 - 7;
        }
    }
}