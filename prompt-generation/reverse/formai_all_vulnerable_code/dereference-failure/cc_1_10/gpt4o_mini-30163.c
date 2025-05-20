//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

typedef struct {
    unsigned char r, g, b;
} Color;

Color getColor(int iterations) {
    Color color = {0, 0, 0};

    if (iterations == MAX_ITER) {
        return color;  // Black for points in the set
    }

    // Color gradient based on iteration count
    color.r = (int)(255 * iterations / MAX_ITER);
    color.g = (int)(255 * (1 - (double)iterations / MAX_ITER));
    color.b = (int)(255 * (double)(iterations % 256) / 256);
    
    return color;
}

void generateMandelbrot(FILE *image) {
    fprintf(image, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double zx = 0.0;
            double zy = 0.0;
            double cX = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double cY = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            int iterations = 0;

            while (zx * zx + zy * zy < 4 && iterations < MAX_ITER) {
                double tmp = zx * zx - zy * zy + cX;
                zy = 2.0 * zx * zy + cY;
                zx = tmp;
                iterations++;
            }

            Color color = getColor(iterations);
            fprintf(image, "%d %d %d ", color.r, color.g, color.b);
        }
    }
}

void generateJulia(FILE *image, double cX, double cY) {
    fprintf(image, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double zx = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double zy = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            int iterations = 0;

            while (zx * zx + zy * zy < 4 && iterations < MAX_ITER) {
                double tmp = zx * zx - zy * zy + cX;
                zy = 2.0 * zx * zy + cY;
                zx = tmp;
                iterations++;
            }

            Color color = getColor(iterations);
            fprintf(image, "%d %d %d ", color.r, color.g, color.b);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *image;
    if (argc < 3) {
        fprintf(stderr, "Usage: %s [mandelbrot|julia] <cX> <cY>\n", argv[0]);
        return 1;
    } else if (strcmp(argv[1], "mandelbrot") == 0) {
        image = fopen("mandelbrot.ppm", "w");
        if (!image) {
            perror("Failed to open file");
            return 1;
        }
        generateMandelbrot(image);
    } else if (strcmp(argv[1], "julia") == 0) {
        if (argc != 4) {
            fprintf(stderr, "For Julia set, provide two additional arguments for cX and cY.\n");
            return 1;
        }
        double cX = atof(argv[2]);
        double cY = atof(argv[3]);
        image = fopen("julia.ppm", "w");
        if (!image) {
            perror("Failed to open file");
            return 1;
        }
        generateJulia(image, cX, cY);
    } else {
        fprintf(stderr, "Unknown fractal type: %s\n", argv[1]);
        return 1;
    }

    fclose(image);
    printf("Fractal image generated successfully!\n");
    return 0;
}