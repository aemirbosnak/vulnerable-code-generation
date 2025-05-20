//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 1000000
#define COLS 1000
#define MAX_VALUE 1000

int main() {
    int **matrix = (int**)malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * COLS);
    }

    // Initialize matrix with random values
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % MAX_VALUE;
        }
    }

    // Find column-wise maximum values
    int *max_values = (int*)malloc(sizeof(int) * COLS);
    for (int j = 0; j < COLS; j++) {
        int max_val = -1;
        for (int i = 0; i < ROWS; i++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
            }
        }
        max_values[j] = max_val;
    }

    // Print column-wise maximum values
    printf("Column-wise maximum values:\n");
    for (int j = 0; j < COLS; j++) {
        printf("%d ", max_values[j]);
    }
    printf("\n");

    // Free memory
    for (int i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(max_values);

    return 0;
}