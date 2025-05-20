//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the matrices
#define MAX_SIZE 100

// Define the data type of the matrix elements
typedef int matrix_element_type;

// Define the structure of a matrix
typedef struct matrix {
    int num_rows;
    int num_cols;
    matrix_element_type **data;
} matrix;

// Create a new matrix
matrix *create_matrix(int num_rows, int num_cols) {
    // Allocate memory for the matrix structure
    matrix *m = malloc(sizeof(matrix));
    if (m == NULL) {
        return NULL;
    }

    // Set the number of rows and columns in the matrix
    m->num_rows = num_rows;
    m->num_cols = num_cols;

    // Allocate memory for the matrix data
    m->data = malloc(num_rows * sizeof(matrix_element_type *));
    if (m->data == NULL) {
        free(m);
        return NULL;
    }

    for (int i = 0; i < num_rows; i++) {
        m->data[i] = malloc(num_cols * sizeof(matrix_element_type));
        if (m->data[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(m->data[j]);
            }
            free(m->data);
            free(m);
            return NULL;
        }
    }

    // Return the matrix
    return m;
}

// Free the memory allocated for a matrix
void free_matrix(matrix *m) {
    // Free the memory allocated for the matrix data
    for (int i = 0; i < m->num_rows; i++) {
        free(m->data[i]);
    }
    free(m->data);

    // Free the memory allocated for the matrix structure
    free(m);
}

// Print a matrix
void print_matrix(matrix *m) {
    // Print the matrix data
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

// Add two matrices
matrix *add_matrices(matrix *m1, matrix *m2) {
    // Create a new matrix to store the result
    matrix *result = create_matrix(m1->num_rows, m1->num_cols);
    if (result == NULL) {
        return NULL;
    }

    // Add the elements of the two matrices
    for (int i = 0; i < m1->num_rows; i++) {
        for (int j = 0; j < m1->num_cols; j++) {
            result->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }

    // Return the result matrix
    return result;
}

// Subtract two matrices
matrix *subtract_matrices(matrix *m1, matrix *m2) {
    // Create a new matrix to store the result
    matrix *result = create_matrix(m1->num_rows, m1->num_cols);
    if (result == NULL) {
        return NULL;
    }

    // Subtract the elements of the two matrices
    for (int i = 0; i < m1->num_rows; i++) {
        for (int j = 0; j < m1->num_cols; j++) {
            result->data[i][j] = m1->data[i][j] - m2->data[i][j];
        }
    }

    // Return the result matrix
    return result;
}

// Multiply two matrices
matrix *multiply_matrices(matrix *m1, matrix *m2) {
    // Create a new matrix to store the result
    matrix *result = create_matrix(m1->num_rows, m2->num_cols);
    if (result == NULL) {
        return NULL;
    }

    // Multiply the elements of the two matrices
    for (int i = 0; i < m1->num_rows; i++) {
        for (int j = 0; j < m2->num_cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < m1->num_cols; k++) {
                result->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }

    // Return the result matrix
    return result;
}

// Transpose a matrix
matrix *transpose_matrix(matrix *m) {
    // Create a new matrix to store the result
    matrix *result = create_matrix(m->num_cols, m->num_rows);
    if (result == NULL) {
        return NULL;
    }

    // Transpose the elements of the matrix
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            result->data[j][i] = m->data[i][j];
        }
    }

    // Return the result matrix
    return result;
}

// Perform matrix operations
int main() {
    // Create two matrices
    matrix *m1 = create_matrix(3, 3);
    matrix *m2 = create_matrix(3, 3);

    // Populate the matrices with some data
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m1->data[i][j] = i + j;
            m2->data[i][j] = i * j;
        }
    }

    // Print the original matrices
    printf("Matrix 1:\n");
    print_matrix(m1);
    printf("\nMatrix 2:\n");
    print_matrix(m2);

    // Add the two matrices
    matrix *add_result = add_matrices(m1, m2);
    printf("\nSum of the two matrices:\n");
    print_matrix(add_result);

    // Subtract the two matrices
    matrix *subtract_result = subtract_matrices(m1, m2);
    printf("\nDifference of the two matrices:\n");
    print_matrix(subtract_result);

    // Multiply the two matrices
    matrix *multiply_result = multiply_matrices(m1, m2);
    printf("\nProduct of the two matrices:\n");
    print_matrix(multiply_result);

    // Transpose the first matrix
    matrix *transpose_result = transpose_matrix(m1);
    printf("\nTranspose of the first matrix:\n");
    print_matrix(transpose_result);

    // Free the memory allocated for the matrices
    free_matrix(m1);
    free_matrix(m2);
    free_matrix(add_result);
    free_matrix(subtract_result);
    free_matrix(multiply_result);
    free_matrix(transpose_result);

    return 0;
}