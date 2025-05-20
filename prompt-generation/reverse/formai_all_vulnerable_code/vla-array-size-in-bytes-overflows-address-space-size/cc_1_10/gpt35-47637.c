//FormAI DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter the number of rows in matrix: ");
    scanf("%d", &rows);

    printf("Enter the number of columns in matrix: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    int i, j;

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix entered by user:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Addition of two matrices
    int matrix2[rows][cols];
    printf("Enter the elements of another matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
            matrix[i][j] += matrix2[i][j];
        }
    }

    printf("Matrix after addition:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose of the matrix
    int transpose[cols][rows];
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    printf("Transpose of matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Determinant of the matrix
    int det = determinant(matrix, rows);
    printf("Determinant of the matrix: %d\n", det);

    return 0;
}

int determinant(int matrix[][100], int size) {
    int submatrix[100][100];
    int det = 0, sign = 1;

    if (size == 1) {
        return matrix[0][0];
    } else {
        for (int x = 0; x < size; x++) {
            int subi = 0;
            for (int i = 1; i < size; i++) {
                int subj = 0;
                for (int j = 0; j < size; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += sign * matrix[0][x] * determinant(submatrix, size - 1);
            sign = -sign;
        }
    }

    return det;
}