//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define the size of the matrix
#define ROWS 3
#define COLS 4

// Define the data type of the matrix elements
typedef float mat_t;

// Define a structure to hold the matrix
typedef struct {
    mat_t data[ROWS][COLS];
} mat_t_t;

// Function to initialize the matrix with zeros
void init_matrix(mat_t_t *mat) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            mat->data[i][j] = 0.0;
        }
    }
}

// Function to display the matrix
void print_matrix(mat_t_t *mat) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%.2f ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrix(mat_t_t *a, mat_t_t *b, mat_t_t *result) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrix(mat_t_t *a, mat_t_t *b, mat_t_t *result) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            mat_t sum = 0.0;
            for (int k = 0; k < COLS; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
}

int main() {
    // Initialize the matrices
    mat_t_t mat1, mat2, mat3;
    init_matrix(&mat1);
    init_matrix(&mat2);
    init_matrix(&mat3);

    // Add the matrices
    add_matrix(&mat1, &mat2, &mat3);

    // Multiply the matrices
    multiply_matrix(&mat1, &mat2, &mat3);

    // Print the result matrix
    printf("Resultant matrix:\n");
    print_matrix(&mat3);

    return 0;
}