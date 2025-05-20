//FormAI DATASET v1.0 Category: Fractal Generation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct {
    double x;
    double y;
} Point;

int main () {
    int iterations = 1 << 16;
    int colors = 256;
    Point c = {0.4567, 0.1234};
    double r = 1.5;
    int i, j, k;

    int *palette = (int *) malloc(colors * sizeof(int));
    for (i = 0; i < colors; i++) {
        palette[i] = i * 0xCCCCCC / (colors - 1);
    }

    int **fractal = (int **) malloc(WIDTH * sizeof(int *));
    for (i = 0; i < WIDTH; i++) {
        fractal[i] = (int *) malloc(HEIGHT * sizeof(int));
    }

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            double x = (double) i / WIDTH * 3 - 2;
            double y = (double) j / HEIGHT * 3 - 1.5;
            Point z = {x, y};
            int count = 0;
            for (k = 0; k < iterations; k++) {
                double xn = z.x * z.x - z.y * z.y + c.x;
                double yn = 2 * z.x * z.y + c.y;
                double d = sqrt(xn * xn + yn * yn);
                if (d > r) {
                    break;
                }
                z.x = xn;
                z.y = yn;
                count++;
            }
            fractal[i][j] = palette[count * colors / iterations];
        }
    }

    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int color = fractal[j][i];
            char rgb[3] = {color >> 16 & 0xFF, color >> 8 & 0xFF, color & 0xFF};
            fwrite(rgb, 1, 3, fp);
        }
    }
    fclose(fp);

    for (i = 0; i < WIDTH; i++) {
        free(fractal[i]);
    }
    free(fractal);
    free(palette);

    return 0;
}