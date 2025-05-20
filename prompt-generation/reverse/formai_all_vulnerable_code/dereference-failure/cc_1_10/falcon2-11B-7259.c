//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // Maximum number of iterations
    int max_iter = 1000;

    // Complex plane range
    double x_min = -2.0;
    double x_max = 1.0;
    double y_min = -1.0;
    double y_max = 1.0;

    // Complex plane dimensions
    int x_size = (x_max - x_min) * 2;
    int y_size = (y_max - y_min) * 2;

    // Create a 2D array to store the pixel values
    double **image = (double **)malloc(x_size * sizeof(double *));
    for (int i = 0; i < x_size; i++) {
        image[i] = (double *)malloc(y_size * sizeof(double));
        for (int j = 0; j < y_size; j++) {
            image[i][j] = 0.0;
        }
    }

    // Compute the pixel values
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            double c = x_min + x * (x_max - x_min) / x_size;
            double s = y_min + y * (y_max - y_min) / y_size;
            double z = 0.0;
            int iter = 0;
            while (z * z + c * z < 4 && iter < max_iter) {
                z = z * z + c;
                iter++;
            }
            image[x][y] = iter;
        }
    }

    // Print the image
    for (int y = 0; y < y_size; y++) {
        for (int x = 0; x < x_size; x++) {
            printf("%d\t", image[x][y]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < x_size; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}