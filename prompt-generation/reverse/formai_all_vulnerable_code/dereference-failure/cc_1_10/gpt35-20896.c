//FormAI DATASET v1.0 Category: Fractal Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_ITER 50

// Function to calculate the Mandelbrot Set
int calculateMandelbrot(double x, double y) {
    double real = x;
    double imag = y;
    double newReal = 0, newImag = 0;
    int n;
    for (n = 0; n < MAX_ITER; ++n) {
        double tempReal = newReal * newReal - newImag * newImag + real;
        double tempImag = 2 * newReal * newImag + imag;
        newReal = tempReal;
        newImag = tempImag;
        if ((newReal * newReal + newImag * newImag) > 4) {
            break;
        }
    }
    return n;
}

// Function to generate the fractal
void generateFractal(int** fractal) {
    double dx = 3.0 / WIDTH;
    double dy = 2.0 / HEIGHT;
    double x, y;
    for (int i = 0; i < HEIGHT; ++i) {
        y = -1 + i * dy;
        for (int j = 0; j < WIDTH; ++j) {
            x = -2 + j * dx;
            fractal[i][j] = calculateMandelbrot(x, y);
        }
    }
}

// Function to print the fractal
void printFractal(int** fractal) {
    int max = 0;
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (fractal[i][j] > max) {
                max = fractal[i][j];
            }
        }
    }
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            int c = (int)(((double)fractal[i][j] / (double)max) * 9.0);
            printf("%c", " .:|&%@#*"[c]);
        }
        printf("\n");
    }
}

int main() {
    int** fractal = (int**) malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; ++i) {
        fractal[i] = (int*) malloc(WIDTH * sizeof(int));
    }
    generateFractal(fractal);
    printFractal(fractal);
    for (int i = 0; i < HEIGHT; ++i) {
        free(fractal[i]);
    }
    free(fractal);
    return 0;
}