//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int rows, cols;
    int **matrix;
    int i, j;

    // Get matrix dimensions from user
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for matrix
    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize matrix with random values
    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Print matrix in a decentralized style
    printf("\n");
    for (i = 0; i < rows; i++) {
        printf(" %d ", matrix[i][0]);
    }
    printf("\n");
    for (i = 0; i < cols; i++) {
        printf("%d ", matrix[0][i]);
    }
    printf("\n");
    for (i = 1; i < rows; i++) {
        for (j = 1; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory allocated for matrix
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}