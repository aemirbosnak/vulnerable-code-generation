//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 5
#define COL_SIZE 10

typedef struct {
    int rows;
    int cols;
    int **matrix;
} CMatrix;

CMatrix *create_matrix(int rows, int cols) {
    CMatrix *matrix = (CMatrix *)malloc(sizeof(CMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix->matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

void print_matrix(CMatrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(CMatrix *matrix) {
    int rows = matrix->rows;
    int cols = matrix->cols;
    int *temp;
    int i, j, k;
    
    // Create a temporary matrix to store the transposed matrix
    CMatrix *temp_matrix = create_matrix(cols, rows);
    
    // Fill the temporary matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            temp = matrix->matrix[i][j];
            temp_matrix->matrix[j][i] = temp[0];
        }
    }
    
    // Free the original matrix
    free(matrix->matrix[0]);
    free(matrix->matrix);
    
    // Swap the matrices
    matrix->matrix = temp_matrix->matrix;
    matrix->rows = temp_matrix->rows;
    matrix->cols = temp_matrix->cols;
    
    // Free the temporary matrix
    free(temp_matrix->matrix[0]);
    free(temp_matrix);
}

void scale_matrix(CMatrix *matrix, int factor) {
    int rows = matrix->rows;
    int cols = matrix->cols;
    int *temp;
    int i, j;
    
    // Create a temporary matrix to store the scaled matrix
    CMatrix *temp_matrix = create_matrix(rows, cols);
    
    // Fill the temporary matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            temp = matrix->matrix[i][j];
            temp_matrix->matrix[i][j] = factor * temp[0];
        }
    }
    
    // Free the original matrix
    free(matrix->matrix[0]);
    free(matrix->matrix);
    
    // Swap the matrices
    matrix->matrix = temp_matrix->matrix;
    matrix->rows = temp_matrix->rows;
    matrix->cols = temp_matrix->cols;
    
    // Free the temporary matrix
    free(temp_matrix->matrix[0]);
    free(temp_matrix);
}

int main() {
    CMatrix *matrix = create_matrix(5, 10);
    print_matrix(matrix);
    
    // Transpose the matrix
    transpose_matrix(matrix);
    print_matrix(matrix);
    
    // Scale the matrix by a factor of 2
    scale_matrix(matrix, 2);
    print_matrix(matrix);
    
    return 0;
}