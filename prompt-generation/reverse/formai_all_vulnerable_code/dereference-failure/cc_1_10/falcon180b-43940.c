//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 1000

// Define the complex number structure
typedef struct {
    double real;
    double imag;
} Complex;

// Function to calculate the Mandelbrot set
void *mandelbrot(void *arg) {
    int x = *(int *) arg;
    int y = *(int *) (arg + sizeof(int));
    double x_min = -2.0;
    double x_max = 1.0;
    double y_min = -1.5;
    double y_max = 1.5;
    double x_step = (x_max - x_min) / WIDTH;
    double y_step = (y_max - y_min) / HEIGHT;

    for (int i = 0; i < HEIGHT; i++) {
        double y_value = y_min + (double) i * y_step;
        for (int j = 0; j < WIDTH; j++) {
            double x_value = x_min + (double) j * x_step;
            Complex z = {0, 0};
            Complex c = {x_value, y_value};

            int iterations = 0;

            while (iterations < MAX_ITERATIONS && z.real * z.real + z.imag * z.imag <= 4.0) {
                z.real = z.real * z.real - z.imag * z.imag + c.real;
                z.imag = 2.0 * z.real * z.imag + c.imag;
                iterations++;
            }

            if (iterations == MAX_ITERATIONS) {
                printf("(%d, %d): %d\n", x, y, iterations);
            }
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[WIDTH * HEIGHT];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pthread_create(&threads[i * WIDTH + j], NULL, mandelbrot, (void *) &j);
            pthread_create(&threads[i * WIDTH + j], NULL, mandelbrot, (void *) &i);
        }
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}