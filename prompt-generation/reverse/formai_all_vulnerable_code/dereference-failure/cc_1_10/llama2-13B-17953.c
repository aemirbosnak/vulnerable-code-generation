//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a new matrix
Matrix* new_matrix(int rows, int cols) {
    Matrix* mat = (Matrix*) malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int*) malloc(cols * sizeof(int));
    }
    return mat;
}

// Function to perform matrix multiplication
Matrix* multiply(Matrix* a, Matrix* b) {
    if (a->rows != b->cols) {
        printf("Matrix dimensions must be compatible for multiplication\n");
        return NULL;
    }
    int rows = a->rows;
    int cols = b->cols;
    Matrix* c = new_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            c->data[i][j] = sum;
        }
    }
    return c;
}

// Function to perform matrix addition
Matrix* add(Matrix* a, Matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Matrix dimensions must be compatible for addition\n");
        return NULL;
    }
    Matrix* c = new_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return c;
}

// Function to print a matrix
void print_matrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Matrix* a = new_matrix(3, 2);
    Matrix* b = new_matrix(2, 3);
    Matrix* c = multiply(a, b);
    print_matrix(c);
    Matrix* d = add(a, b);
    print_matrix(d);
    return 0;
}