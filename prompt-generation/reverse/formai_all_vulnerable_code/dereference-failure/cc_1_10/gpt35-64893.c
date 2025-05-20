//FormAI DATASET v1.0 Category: Fractal Generation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define WIDTH 80
#define HEIGHT 25

void Mandelbrot(char *image, float xmin, float xmax, float ymin, float ymax, int max_iterations)
{
    int i, j, iterations;
    float x, y, x0, y0, xtemp, ytemp, Cx, Cy, pixel_width, pixel_height;

    pixel_width = (xmax - xmin) / (float)WIDTH;
    pixel_height = (ymax - ymin) / (float)HEIGHT;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            x = xmin + ((float)j * pixel_width);
            y = ymax - ((float)i * pixel_height);
            x0 = x;
            y0 = y;
            Cx = x;
            Cy = y;

            iterations = 0;

            while ((x * x + y * y <= 4) && iterations < max_iterations) {
                xtemp = x * x - y * y + Cx;
                ytemp = 2 * x * y + Cy;
                x = xtemp;
                y = ytemp;
                iterations++;
            }

            if (iterations == max_iterations) {
                image[WIDTH * i + j] = ' ';
            } else if (iterations > max_iterations / 2) {
                image[WIDTH * i + j] = '.';
            } else if (iterations > max_iterations / 4) {
                image[WIDTH * i + j] = '=';
            } else if (iterations > max_iterations / 8) {
                image[WIDTH * i + j] = '+';
            } else if (iterations > max_iterations / 16) {
                image[WIDTH * i + j] = '*';
            } else if (iterations > max_iterations / 32) {
                image[WIDTH * i + j] = 'x';
            } else {
                image[WIDTH * i + j] = '#';
            }
        }
    }

    image[WIDTH * HEIGHT] = '\0';
}

int main(void)
{
    int max_iterations = 1000;
    char *image = calloc(WIDTH * HEIGHT + 1, sizeof(char));

    Mandelbrot(image, -2.2f, 1.0f, -1.0f, 1.0f, max_iterations);

    printf("%s\n", image);

    free(image);

    return 0;
}