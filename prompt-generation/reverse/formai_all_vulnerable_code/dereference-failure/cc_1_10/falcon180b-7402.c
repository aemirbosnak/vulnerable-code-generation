//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i, j;
    int rows, cols;
    int **matrix;

    srand(time(NULL));
    rows = rand() % 10 + 1;
    cols = rand() % 10 + 1;

    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("Generated Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int sum = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }

    printf("\nSum of all elements in the matrix: %d\n", sum);

    free(matrix[0]);
    for (i = 1; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}