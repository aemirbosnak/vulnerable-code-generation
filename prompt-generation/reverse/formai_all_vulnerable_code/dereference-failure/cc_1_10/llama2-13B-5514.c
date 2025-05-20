//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

// Function to create a matrix with a specified size
Matrix* create_matrix(int rows, int cols) {
    Matrix* mat = (Matrix*) malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int*) malloc(sizeof(int) * rows * cols);
    return mat;
}

// Function to perform matrix multiplication
Matrix* multiply(Matrix* a, Matrix* b) {
    Matrix* c = create_matrix(a->rows, b->cols);
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            int sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->rows + j];
            }
            c->data[i * c->rows + j] = sum;
        }
    }
    return c;
}

// Function to perform matrix addition
Matrix* add(Matrix* a, Matrix* b) {
    Matrix* c = create_matrix(a->rows, b->cols);
    int i, j;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            c->data[i * c->rows + j] = a->data[i * a->rows + j] + b->data[i * b->rows + j];
        }
    }
    return c;
}

int main() {
    Matrix* a = create_matrix(3, 2);
    Matrix* b = create_matrix(2, 3);
    Matrix* c = multiply(a, b);
    Matrix* d = add(a, b);

    // Print the matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", a->data[i * 3 + j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", b->data[i * 2 + j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", c->data[i * 3 + j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", d->data[i * 3 + j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}