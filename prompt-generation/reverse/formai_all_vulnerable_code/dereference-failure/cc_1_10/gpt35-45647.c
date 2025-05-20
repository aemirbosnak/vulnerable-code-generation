//FormAI DATASET v1.0 Category: Fractal Generation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 800
#define ITERATIONS 50000
#define SCALE 0.4

double rand_double() {
    return (double) rand() / (double) RAND_MAX;
}

int main() {
    srand(time(NULL));
    int i, j, k;
    double x = 0, y = 0, x1, y1;

    unsigned char** canvas = malloc(HEIGHT * sizeof(unsigned char*));
    for (i = 0; i < HEIGHT; i++) {
        canvas[i] = malloc(WIDTH * sizeof(unsigned char));
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            canvas[i][j] = 0;
        }
    }

    for (k = 0; k < ITERATIONS; k++) {
        double r = rand_double();
        if (r <= 0.01) { // 1% chance
            x1 = 0;
            y1 = 0.16 * y;
        } else if (r <= 0.86) { // 85%
            x1 = 0.85 * x + 0.04 * y;
            y1 = -0.04 * x + 0.85 * y + 1.6;
        } else if (r <= 0.93) { // 7%
            x1 = 0.2 * x - 0.26 * y;
            y1 = 0.23 * x + 0.22 * y + 1.6;
        } else { // 7%
            x1 = -0.15 * x + 0.28 * y;
            y1 = 0.26 * x + 0.24 * y + 0.44;
        }

        x = x1;
        y = y1;

        int ix = (int) (WIDTH / 2 + SCALE * x * WIDTH);
        int iy = (int) (HEIGHT - SCALE * y * HEIGHT);
        if (ix >= 0 && ix < WIDTH && iy >= 0 && iy < HEIGHT) {
            canvas[iy][ix] += 1;
        }
    }

    FILE* file = fopen("myfractal.ppm", "w");
    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", WIDTH, HEIGHT);
    fprintf(file, "255\n");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fprintf(file, "%d ", canvas[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    for (i = 0; i < HEIGHT; i++) {
        free(canvas[i]);
    }
    free(canvas);

    return 0;
}