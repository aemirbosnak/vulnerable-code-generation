//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

void create_matrix(Matrix *matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (double *)malloc(cols * sizeof(double));
    }
}

void destroy_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
}

void print_matrix(const Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%lf ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices(const Matrix *A, const Matrix *B, Matrix *C) {
    if (A->cols!= B->rows) {
        printf("Error: Incompatible matrix dimensions\n");
        exit(1);
    }

    C->rows = A->rows;
    C->cols = B->cols;

    for (int i = 0; i < C->rows; i++) {
        for (int j = 0; j < C->cols; j++) {
            double sum = 0;
            for (int k = 0; k < A->cols; k++) {
                sum += A->data[i][k] * B->data[k][j];
            }
            C->data[i][j] = sum;
        }
    }
}

int main() {
    Matrix A, B, C;
    int rows_A, cols_A, rows_B, cols_B;

    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rows_A, &cols_A);

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rows_B, &cols_B);

    if (cols_A!= rows_B) {
        printf("Error: Incompatible matrix dimensions\n");
        exit(1);
    }

    create_matrix(&A, rows_A, cols_A);
    create_matrix(&B, rows_B, cols_B);

    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < cols_A; j++) {
            scanf("%lf", &A.data[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < rows_B; i++) {
        for (int j = 0; j < cols_B; j++) {
            scanf("%lf", &B.data[i][j]);
        }
    }

    multiply_matrices(&A, &B, &C);

    printf("Product of matrices A and B:\n");
    print_matrix(&C);

    destroy_matrix(&A);
    destroy_matrix(&B);
    destroy_matrix(&C);

    return 0;
}