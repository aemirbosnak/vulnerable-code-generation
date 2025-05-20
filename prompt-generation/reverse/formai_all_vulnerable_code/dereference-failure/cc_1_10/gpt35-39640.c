//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define ITERATIONS 500
#define SCALE_FACTOR 0.4
#define MAX_COLORS 256

typedef struct {
    float x;
    float y;
} ComplexNumber;

int getColor(float);

int main() {
    int i, j, k, colorIndex;
    float scale, x, y, Zr, Zi, Cr, Ci, Tr, Ti, radius, iterations;

    // Allocate memory for image array
    unsigned char *image = (unsigned char *) malloc(WIDTH * HEIGHT);

    // Initialize scale and coordinates
    scale = 1.5;
    x = -0.5;
    y = 0.0;

    // Generate Mandelbrot set
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            Zr = 0.0;
            Zi = 0.0;
            Cr = (i - WIDTH/2.0) * scale/WIDTH + x;
            Ci = (j - HEIGHT/2.0) * scale/HEIGHT + y;
            iterations = 0.0;
            radius = 0.0;

            while (radius < 4.0 && iterations < ITERATIONS) {
                Tr = Zr*Zr - Zi*Zi + Cr;
                Ti = 2*Zr*Zi + Ci;
                Zr = Tr;
                Zi = Ti;
                radius = Zr*Zr + Zi*Zi;
                iterations++;
            }

            // Get color based on iterations 
            colorIndex = getColor(iterations);
            image[j*WIDTH + i] = colorIndex;
        }
    }

    // Write image to file
    FILE *fp = fopen("fractal.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLORS - 1);
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Free memory
    free(image);

    return 0;
}

int getColor(float iterations) {
    int colorIndex = (int) floorf(sqrtf(iterations/MAX_COLORS) * MAX_COLORS);
    
    if (colorIndex < 0 || colorIndex > MAX_COLORS) {
        colorIndex = 0;
    }
    
    return colorIndex;
}