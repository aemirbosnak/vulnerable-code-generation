//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159

int main() {
    int i, j;
    double x, y, temp;
    double **heat_map;

    srand(time(NULL));

    // Initialize heat map
    heat_map = (double **)malloc(100 * sizeof(double *));
    for (i = 0; i < 100; i++) {
        heat_map[i] = (double *)malloc(100 * sizeof(double));
        for (j = 0; j < 100; j++) {
            heat_map[i][j] = rand() % 100;
        }
    }

    // Print initial heat map
    printf("Initial heat map:\n");
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            printf("%d ", heat_map[i][j]);
        }
        printf("\n");
    }

    // Simulate temperature changes
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 100; j++) {
            x = j - 50;
            y = i - 50;
            temp = sin(sqrt(x * x + y * y)) * 50 + 50;
            heat_map[i][j] = temp;
        }
    }

    // Print final heat map
    printf("\nFinal heat map:\n");
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            printf("%d ", heat_map[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < 100; i++) {
        free(heat_map[i]);
    }
    free(heat_map);

    return 0;
}