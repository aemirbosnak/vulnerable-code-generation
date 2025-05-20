//FormAI DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// function to print matrix
void printMatrix(int **matrix, int rows, int cols) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to add two matrices
void addMatrix(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// function to subtract two matrices
void subtractMatrix(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// function to multiply two matrices
void multiplyMatrix(int **matrix1, int **matrix2, int **result, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: Invalid matrix dimensions for multiplication\n");
        return;
    }
    for (int i=0; i<rows1; i++) {
        for (int j=0; j<cols2; j++) {
            for (int k=0; k<cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);
    
    // allocate memory for matrices
    int **matrix1 = (int **) malloc(rows * sizeof(int *));
    int **matrix2 = (int **) malloc(rows * sizeof(int *));
    int **result = (int **) malloc(rows * sizeof(int *));
    for (int i=0; i<rows; i++) {
        matrix1[i] = (int *) malloc(cols * sizeof(int));
        matrix2[i] = (int *) malloc(cols * sizeof(int));
        result[i] = (int *) calloc(cols, sizeof(int));
    }
    
    printf("Enter elements of the first matrix:\n");
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    printf("Enter elements of the second matrix:\n");
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    printf("Matrix 1:\n");
    printMatrix(matrix1, rows, cols);
    printf("Matrix 2:\n");
    printMatrix(matrix2, rows, cols);
    
    printf("Adding matrix 1 and matrix 2:\n");
    addMatrix(matrix1, matrix2, result, rows, cols);
    printMatrix(result, rows, cols);
    
    printf("Subtracting matrix 1 from matrix 2:\n");
    subtractMatrix(matrix1, matrix2, result, rows, cols);
    printMatrix(result, rows, cols);
    
    int rows2, cols2;
    printf("Enter the number of rows in the second matrix: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns in the second matrix: ");
    scanf("%d", &cols2);
    
    // allocate memory for second matrix
    int **matrix3 = (int **) malloc(rows2 * sizeof(int *));
    for (int i=0; i<rows2; i++) {
        matrix3[i] = (int *) malloc(cols2 * sizeof(int));
    }
    
    printf("Enter elements of the second matrix:\n");
    for (int i=0; i<rows2; i++) {
        for (int j=0; j<cols2; j++) {
            scanf("%d", &matrix3[i][j]);
        }
    }
    
    printf("Multiplying matrix 1 and matrix 3:\n");
    multiplyMatrix(matrix1, matrix3, result, rows, cols, rows2, cols2);
    printMatrix(result, rows, cols2);
    
    // free memory
    for (int i=0; i<rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    for (int i=0; i<rows2; i++) {
        free(matrix3[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);
    free(matrix3);
    
    return 0;
}