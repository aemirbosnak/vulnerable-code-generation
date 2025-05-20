//FormAI DATASET v1.0 Category: Fractal Generation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WIDTH 80
#define HEIGHT 24
#define MAX_ITER 10000

/*
Calculates the color value of a pixel based on the number of iterations needed
to determine if it is inside or outside the fractal set
*/
int calculate_pixel_value(double x, double y) {
    double real = x;
    double img = y;
    int iter = 0;

    while (iter < MAX_ITER) {
        double temp_real = real * real - img * img + x;
        double temp_img = 2 * real * img + y;
        real = temp_real;
        img = temp_img;
        if (sqrt(real * real + img * img) > 2) {
            break;
        }
        iter++;
    }

    int color_val = (int) ((double) iter/MAX_ITER * 255);
    return color_val;
}

/* 
Prints the fractal set to the console using ASCII art 
*/
void print_fractal(int **fractal) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (fractal[i][j] == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    int **fractal = (int **) calloc(HEIGHT, sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        fractal[i] = (int *) calloc(WIDTH, sizeof(int));
    }

    double x_range = 3;
    double y_range = 2;
    double pixel_width = x_range/WIDTH;
    double pixel_height = y_range/HEIGHT;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            double x = j * pixel_width - x_range/2;
            double y = i * pixel_height - y_range/2;
            fractal[i][j] = calculate_pixel_value(x, y);
        }
    }

    print_fractal(fractal);

    for (int i = 0; i < HEIGHT; i++) {
        free(fractal[i]);
    }
    free(fractal);
    return 0;
}