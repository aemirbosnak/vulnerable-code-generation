//FormAI DATASET v1.0 Category: Fractal Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the next complex point
double complex_func(double a, double b, double x, double y) {
    double new_x = a * x - b * y;
    double new_y = b * x + a * y;
    return sqrt(new_x * new_x + new_y * new_y);
}

// Function to iterate through the points and print the fractal
void iterate_points(double zoom, double x_translate, double y_translate, int max_iterations, int width, int height) {
    char* image = malloc(sizeof(char) * width * height); // allocate memory for image
    
    double x, y, x_new, y_new, a, b;
    int current_iteration;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            x = (double)i / zoom - x_translate;
            y = (double)j / zoom - y_translate;
            x_new = x;
            y_new = y;
            current_iteration = 0;
            while (current_iteration < max_iterations) {
                a = 2.0 * x_new - 1.0;
                b = 2.0 * y_new;
                x_new = complex_func(a, b, x_new, y_new) + x;
                y_new = complex_func(a, b, y_new, x_new) + y;
                if (x_new * x_new + y_new * y_new > 4.0) {
                    break;
                }
                current_iteration++;
            }
            if (current_iteration == max_iterations) {
                image[i * height + j] = ' '; // set space for "in" points
            }
            else {
                image[i * height + j] = '*'; // set star for "out" points
            }
        }
    }

    // print image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", image[j * height + i]);
        }
        printf("\n");
    }
    free(image); // free memory
}

int main() {
    double zoom = 300.0;
    double x_translate = 1.0;
    double y_translate = 0.0;
    int max_iterations = 100;
    int width = 100;
    int height = 40;
    iterate_points(zoom, x_translate, y_translate, max_iterations, width, height);
    return 0;
}