//MISTRAL-7B DATASET v1.0 Category: Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

Matrix create_matrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (int**)calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix.data[i] = (int*)calloc(cols, sizeof(int));
    }
    return matrix;
}

void destroy_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

void print_matrix(const Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("%3d ", matrix.data[i][j]);
        }
        printf("\n");
    }
}

Matrix multiply_matrices(const Matrix a, const Matrix b) {
    if (a.cols != b.rows) {
        fprintf(stderr, "Matrices can't be multiplied.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = create_matrix(a.rows, b.cols);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }

    return result;
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("Enter rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("Error: Matrix dimensions don't match.\n");
        return EXIT_FAILURE;
    }

    Matrix matrixA = create_matrix(rowsA, colsA);
    Matrix matrixB = create_matrix(rowsB, colsB);

    printf("Enter elements for matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA.data[i][j]);
        }
    }

    printf("Enter elements for matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB.data[i][j]);
        }
    }

    Matrix product = multiply_matrices(matrixA, matrixB);

    printf("Product of matrices A and B:\n");
    print_matrix(product);

    destroy_matrix(matrixA);
    destroy_matrix(matrixB);
    destroy_matrix(product);

    return EXIT_SUCCESS;
}