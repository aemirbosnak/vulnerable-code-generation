//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int rows, int cols) {
    printf("[");
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        if (i == rows-1) {
            printf("]");
        }
        printf("\n ");
    }
}

int** create_matrix(int rows, int cols) {
    int **matrix = malloc(rows * sizeof(int *));
    for (int i=0; i<rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        for (int j=0; j<cols; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void add_matrix(int **matrix1, int **matrix2, int rows, int cols) {
    int **result_matrix = create_matrix(rows, cols);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("The sum of the two matrices is: \n");
    print_matrix(result_matrix, rows, cols);
}

void multiply_matrix(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
    int **result_matrix = create_matrix(rows1, cols2);
    for (int i=0; i<rows1; i++) {
        for (int j=0; j<cols2; j++) {
            for (int k=0; k<cols1; k++) {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("The product of the two matrices is: \n");
    print_matrix(result_matrix, rows1, cols2);
}

void transpose_matrix(int **matrix, int rows, int cols) {
    int **result_matrix = create_matrix(cols, rows);
    for (int i=0; i<cols; i++) {
        for (int j=0; j<rows; j++) {
            result_matrix[i][j] = matrix[j][i];
        }
    }
    printf("The transpose of the matrix is: \n");
    print_matrix(result_matrix, cols, rows);
}

int main() {
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    if (cols1 != rows2) {
        printf("Error! The number of columns of the first matrix should be equal to the number of rows of the second matrix. Exiting...");
        return 0;
    }
    int **matrix1 = create_matrix(rows1, cols1);
    int **matrix2 = create_matrix(rows2, cols2);
    printf("Enter elements of first matrix: \n");
    for (int i=0; i<rows1; i++) {
        for (int j=0; j<cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter elements of second matrix: \n");
    for (int i=0; i<rows2; i++) {
        for (int j=0; j<cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("The first matrix is: \n");
    print_matrix(matrix1, rows1, cols1);
    printf("The second matrix is: \n");
    print_matrix(matrix2, rows2, cols2);
    add_matrix(matrix1, matrix2, rows1, cols1);
    multiply_matrix(matrix1, matrix2, rows1, cols1, rows2, cols2);
    transpose_matrix(matrix1, rows1, cols1);
    transpose_matrix(matrix2, rows2, cols2);
    return 0;
}