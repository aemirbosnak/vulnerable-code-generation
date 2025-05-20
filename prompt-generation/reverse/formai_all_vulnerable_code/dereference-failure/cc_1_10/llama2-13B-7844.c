//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW_SIZE 10
#define COLUMN_SIZE 5

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a matrix
matrix_t* create_matrix(int rows, int cols) {
    matrix_t* mat = (matrix_t*)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int**)calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int*)calloc(cols, sizeof(int));
    }
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t* add_matrices(matrix_t* mat1, matrix_t* mat2) {
    matrix_t* result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = mat1->data[i][j] + mat2->data[i][j];
            result->data[i][j] = sum % 2 == 0 ? sum : sum + 1;
        }
    }
    return result;
}

int main() {
    srand(time(NULL));

    // Create two matrices
    matrix_t* mat1 = create_matrix(ROW_SIZE, COLUMN_SIZE);
    matrix_t* mat2 = create_matrix(ROW_SIZE, COLUMN_SIZE);

    // Fill the matrices with random numbers
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            mat1->data[i][j] = rand() % 10;
            mat2->data[i][j] = rand() % 10;
        }
    }

    // Add the matrices
    matrix_t* result = add_matrices(mat1, mat2);

    // Print the result
    print_matrix(result);

    return 0;
}