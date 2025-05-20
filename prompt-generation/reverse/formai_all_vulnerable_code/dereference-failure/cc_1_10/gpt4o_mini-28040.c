//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_ITER 1000

void draw_mandelbrot() {
    int x, y, iter;
    double real, imag, c_real, c_imag;
    char *screen = (char *)malloc(WIDTH * HEIGHT);
  
    // Initialize the screen array
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        screen[i] = ' ';
    }

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            c_real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            c_imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            real = imag = 0.0;
            iter = 0;

            // Apply Mandelbrot iteration
            while (real * real + imag * imag < 4 && iter < MAX_ITER) {
                double temp_real = real * real - imag * imag + c_real;
                imag = 2 * real * imag + c_imag;
                real = temp_real;
                iter++;
            }

            // Draw the character based on number of iterations
            if (iter < MAX_ITER) {
                screen[y * WIDTH + x] = (iter % 26) + 'A';  // Simple character mapping
            } else {
                screen[y * WIDTH + x] = '.';
            }
        }
    }

    // Display the fractal to the console
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            putchar(screen[y * WIDTH + x]);
        }
        putchar('\n');
    }

    free(screen);
}

int main() {
    printf("Generating Mandelbrot Fractal...\n");
    draw_mandelbrot();
    printf("Completed!\n");
    return 0;
}