//Falcon-180B DATASET v1.0 Category: Data mining ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_ROWS 1000
#define MAX_NUM_COLS 1000
#define NUM_ROWS 100
#define NUM_COLS 100

int main() {
    int **matrix;
    int i, j, n, m, sum = 0;
    double avg;
    srand(time(0));

    // Initialize matrix with random values
    matrix = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (i = 0; i < NUM_ROWS; i++) {
        matrix[i] = (int *)malloc(NUM_COLS * sizeof(int));
        for (j = 0; j < NUM_COLS; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Print matrix
    printf("Matrix:\n");
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate sum of all elements in matrix
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            sum += matrix[i][j];
        }
    }

    // Calculate average of all elements in matrix
    avg = (double)sum / (NUM_ROWS * NUM_COLS);
    printf("\nAverage: %.2f\n", avg);

    // Free memory
    for (i = 0; i < NUM_ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}