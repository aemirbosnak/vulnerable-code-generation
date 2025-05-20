//FormAI DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITERATIONS 500
#define ESCAPE_RADIUS 2

typedef struct {
    int x, y;
} Vector2;

int mandelbrot_escape_time(double x, double y) {
    double real = 0;
    double imag = 0;
    int i;

    for (i = 0; i < MAX_ITERATIONS; i++) {
        double temp = real * real - imag * imag + x;
        imag = 2 * real * imag + y;
        real = temp;

        if (real * real + imag * imag > ESCAPE_RADIUS * ESCAPE_RADIUS) {
            return i;
        }
    }

    return -1;
}

double map(double value, double low1, double high1, double low2, double high2) {
    return low2 + (value - low1) * (high2 - low2) / (high1 - low1);
}

Vector2 map_screen_to_coordinate_space(int x, int y) {
    double xPos = map(x, 0, WIDTH, -2, 1);
    double yPos = map(y, 0, HEIGHT, -1, 1);

    Vector2 result = { xPos, yPos };
    return result;
}

void render_fractal(int* output) {
    int x, y;

    #pragma omp parallel for private(x, y) shared(output)
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            Vector2 point = map_screen_to_coordinate_space(x, y);
            int escape_time = mandelbrot_escape_time(point.x, point.y);

            if (escape_time == -1) {
                output[y * WIDTH + x] = 0;
            } else {
                double value = map(escape_time, 0, MAX_ITERATIONS, 0, 1);
                output[y * WIDTH + x] = (int)(value * 255 + 0.5);
            }
        }
    }
}

int main() {
    int* output = (int*)malloc(WIDTH * HEIGHT * sizeof(int));

    render_fractal(output);

    FILE* file = fopen("output.ppm", "w");

    fprintf(file, "P3 %d %d 255", WIDTH, HEIGHT);
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int color = output[y * WIDTH + x];
            fprintf(file, "%d %d %d ", color, color, color);
        }
        fprintf(file, "\n");
    }

    printf("Render complete. Output written to output.ppm\n");

    fclose(file);
    free(output);
    return 0;
}