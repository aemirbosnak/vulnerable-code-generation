//FormAI DATASET v1.0 Category: Fractal Generation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MAX_ITERATIONS 1000

void generateFractal(int n, double cx, double cy, double zoom, unsigned char *img) {
    double x, y, temp;
    int i, j, k;

    for (i = 0; i < WINDOW_HEIGHT; i++) {
        for (j = 0; j < WINDOW_WIDTH; j++) {
            x = ((double)j - (double)WINDOW_WIDTH / 2.0) * 4.0 / (double)WINDOW_HEIGHT / zoom + cx;
            y = ((double)i - (double)WINDOW_HEIGHT / 2.0) * 4.0 / (double)WINDOW_HEIGHT / zoom + cy;

            k = 0;
            while (k < n) {
                temp = x * x - y * y + (double)rand() / (double)RAND_MAX - 0.5;
                y = 2.0 * x * y + (double)rand() / (double)RAND_MAX - 0.5;
                x = temp;
                if (x * x + y * y > 4.0)
                    break;
                k++;
            }

            img[(i * WINDOW_WIDTH + j) * 3] = k % MAX_ITERATIONS;
            img[(i * WINDOW_WIDTH + j) * 3 + 1] = k % MAX_ITERATIONS;
            img[(i * WINDOW_WIDTH + j) * 3 + 2] = k % MAX_ITERATIONS;
        }
    }
}

int main() {
    srand(time(NULL));

    unsigned char *img = (unsigned char*)malloc(WINDOW_WIDTH * WINDOW_HEIGHT * 3);

    generateFractal(500, -0.7435669, 0.1314023, 1.0, img);

    FILE *file;
    file = fopen("fractal.ppm", "wb");
    fprintf(file, "P6\n%d %d\n255\n", WINDOW_WIDTH, WINDOW_HEIGHT);
    fwrite(img, sizeof(unsigned char), WINDOW_WIDTH * WINDOW_HEIGHT * 3, file);
    fclose(file);

    free(img);
    return 0;
}