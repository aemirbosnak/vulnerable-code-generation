//FormAI DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

/* Function to print a matrix */
void print_matrix(int **matrix, int rows, int cols) {
    int i, j;

    printf("Matrix:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Function to calculate the transpose of a matrix */
int **transpose_matrix(int **matrix, int rows, int cols) {
    int i, j;
    int **transposed_matrix = (int **)malloc(cols * sizeof(int *));
    
    for (i = 0; i < cols; i++) {
        transposed_matrix[i] = (int *)malloc(rows * sizeof(int));
    }

    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            transposed_matrix[i][j] = matrix[j][i];
        }
    }

    return transposed_matrix;
}

/* Function to calculate the sum of two matrices */
int **sum_matrices(int **matrix1, int **matrix2, int rows, int cols) {
    int i, j;
    int **sum_matrix = (int **)malloc(rows * sizeof(int *));
    
    for (i = 0; i < rows; i++) {
        sum_matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return sum_matrix;
}

/* Function to free memory allocated to a matrix */
void free_matrix(int **matrix, int rows) {
    int i;

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int **matrix1;
    int **matrix2;
    int **transpose;
    int **sum;
    int rows, cols;
    int i, j;

    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);

    /* Allocate memory for matrix1 */
    matrix1 = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
    }

    /* Read values for matrix1 */
    printf("Enter the values for matrix1:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    /* Allocate memory for matrix2 */
    matrix2 = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix2[i] = (int *)malloc(cols * sizeof(int));
    }

    /* Read values for matrix2 */
    printf("Enter the values for matrix2:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    /* Print matrix1 and matrix2 */
    printf("\n");
    print_matrix(matrix1, rows, cols);
    print_matrix(matrix2, rows, cols);

    /* Calculate and print the transpose of matrix1 */
    transpose = transpose_matrix(matrix1, rows, cols);
    print_matrix(transpose, cols, rows);
    
    /* Calculate and print the sum of matrix1 and matrix2 */
    sum = sum_matrices(matrix1, matrix2, rows, cols);
    print_matrix(sum, rows, cols);

    /* Free memory */
    free_matrix(matrix1, rows);
    free_matrix(matrix2, rows);
    free_matrix(transpose, cols);
    free_matrix(sum, rows);

    return 0;
}