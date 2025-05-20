//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    double x, y;
} complex_t;

typedef struct {
    complex_t c;
    int iterations;
} fractal_data_t;

void draw_fractal(fractal_data_t *data, int *pixels) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            double x = (double)i / (WIDTH - 1) * 3 - 1.5;
            double y = (double)j / (HEIGHT - 1) * 2 - 1;
            complex_t z = {x, y};

            int iterations = 0;
            while (iterations < data->iterations && z.x * z.x + z.y * z.y <= 4) {
                complex_t z_temp = {z.x * z.x - z.y * z.y + data->c.x, 2 * z.x * z.y + data->c.y};
                z = z_temp;
                iterations++;
            }

            pixels[i + j * WIDTH] = iterations * 255 / data->iterations;
        }
    }
}

int main() {
    fractal_data_t data = {{0.0, 0.0}, 255};
    int *pixels = malloc(WIDTH * HEIGHT * sizeof(int));

    draw_fractal(&data, pixels);

    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        fprintf(fp, "%d %d %d ", pixels[i], pixels[i], pixels[i]);
    }
    fclose(fp);

    free(pixels);

    return 0;
}