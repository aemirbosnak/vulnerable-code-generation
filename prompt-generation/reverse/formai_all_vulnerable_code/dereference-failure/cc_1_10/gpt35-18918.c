//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: imaginative
#include <stdio.h>

// A performance-critical component that performs matrix multiplication
int matrix_multiplication(int **matrix_a, int **matrix_b, int **output_matrix, int size)
{
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            output_matrix[i][j] = 0;
            for(int k=0; k<size; k++) {
                output_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    return 0;
}

int main() 
{
    int size = 1000;
    int **matrix_a, **matrix_b, **output_matrix;
    matrix_a = (int **)malloc(size * sizeof(int*)); // allocating memory
    matrix_b = (int **)malloc(size * sizeof(int*));
    output_matrix = (int **)malloc(size * sizeof(int*));
    for(int i=0; i<size; i++) {
        matrix_a[i] = (int *)malloc(size * sizeof(int)); // allocating memory
        matrix_b[i] = (int *)malloc(size * sizeof(int));
        output_matrix[i] = (int *)malloc(size * sizeof(int));
    }

    // Populating matrix_a and matrix_b with random values
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            matrix_a[i][j] = rand() % 10;
            matrix_b[i][j] = rand() % 10;
        }
    }

    matrix_multiplication(matrix_a, matrix_b, output_matrix, size);

    // Printing output_matrix
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%d ", output_matrix[i][j]);
        }
        printf("\n");
    }

    // Freeing memory
    for(int i=0; i<size; i++) {
        free(matrix_a[i]);
        free(matrix_b[i]);
        free(output_matrix[i]);
    }
    free(matrix_a);
    free(matrix_b);
    free(output_matrix);

    return 0;
}