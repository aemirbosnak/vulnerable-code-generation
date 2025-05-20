//Falcon-180B DATASET v1.0 Category: Educational ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n;
    int **matrix;
    int sum = 0;

    // Get the size of the matrix from the user
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    // Allocate memory for the matrix
    matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Fill the matrix with random numbers
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Print the matrix
    printf("\nThe original matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate the sum of all elements in the matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
    }

    // Print the sum
    printf("\nThe sum of all elements in the matrix is: %d\n", sum);

    // Free the memory allocated for the matrix
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}