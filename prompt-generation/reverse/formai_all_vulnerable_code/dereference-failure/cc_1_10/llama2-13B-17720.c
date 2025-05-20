//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *)malloc(rows * cols * sizeof(int));
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    int i, j, k;
    matrix_t *result = new_matrix(mat1->rows, mat2->cols);
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            for (k = 0; k < mat1->cols; k++) {
                result->data[i * result->cols + j] += mat1->data[i * mat1->cols + k] + mat2->data[k * mat2->cols + j];
            }
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *mat, int scalar) {
    int i, j;
    matrix_t *result = new_matrix(mat->rows, mat->cols);
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            result->data[i * result->cols + j] = scalar * mat->data[i * mat->cols + j];
        }
    }
    return result;
}

int main() {
    matrix_t *mat1, *mat2, *result;
    int choice;

    do {
        printf("Matrix operations menu:\n");
        printf("1. Add two matrices\n");
        printf("2. Multiply a matrix by a scalar\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the first matrix: ");
                scanf("%d %d", &mat1->rows, &mat1->cols);
                mat1 = new_matrix(mat1->rows, mat1->cols);
                for (int i = 0; i < mat1->rows; i++) {
                    for (int j = 0; j < mat1->cols; j++) {
                        scanf("%d", &mat1->data[i * mat1->cols + j]);
                    }
                }
                printf("Enter the second matrix: ");
                scanf("%d %d", &mat2->rows, &mat2->cols);
                mat2 = new_matrix(mat2->rows, mat2->cols);
                for (int i = 0; i < mat2->rows; i++) {
                    for (int j = 0; j < mat2->cols; j++) {
                        scanf("%d", &mat2->data[i * mat2->cols + j]);
                    }
                }
                result = add_matrices(mat1, mat2);
                print_matrix(result);
                break;

            case 2:
                printf("Enter the matrix and the scalar: ");
                scanf("%d %d", &mat1->rows, &mat1->cols);
                mat1 = new_matrix(mat1->rows, mat1->cols);
                for (int i = 0; i < mat1->rows; i++) {
                    for (int j = 0; j < mat1->cols; j++) {
                        scanf("%d", &mat1->data[i * mat1->cols + j]);
                    }
                }
                int scalar = atoi(scanf("%s", &scalar));
                result = scale_matrix(mat1, scalar);
                print_matrix(result);
                break;

            case 3:
                printf("Exiting...");
                return 0;
        }
    } while (1);

    return 0;
}