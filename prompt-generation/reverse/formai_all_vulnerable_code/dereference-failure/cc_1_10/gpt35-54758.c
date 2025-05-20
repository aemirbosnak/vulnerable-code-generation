//FormAI DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// define a matrix struct
typedef struct {
    double **data; // 2D array of doubles
    int rows; // number of rows
    int cols; // number of columns
} matrix;

// function to initialize a matrix
void init_matrix(matrix *m, int rows, int cols) {
    m -> rows = rows;
    m -> cols = cols;
    // dynamically allocate memory for the 2D array
    m -> data = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        m -> data[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            // initialize all values to 0.0
            m -> data[i][j] = 0.0;
        }
    }
}

// function to print a matrix
void print_matrix(matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%f ", m.data[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
matrix add_matrices(matrix m1, matrix m2) {
    // check if matrices have the same dimensions
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        printf("Error: matrices have different dimensions.\n");
        exit(1);
    }

    matrix result;
    init_matrix(&result, m1.rows, m1.cols);

    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            // add the corresponding values in each matrix
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }

    return result;
}

// function to multiply two matrices
matrix multiply_matrices(matrix m1, matrix m2) {
    // check if the number of columns in first matrix is equal to the number of rows in second matrix
    if (m1.cols != m2.rows) {
        printf("Error: matrices cannot be multiplied.\n");
        exit(1);
    }

    matrix result;
    init_matrix(&result, m1.rows, m2.cols);

    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < m1.cols; k++) {
                // multiply and add corresponding values in each matrix
                sum += m1.data[i][k] * m2.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}

int main() {
    // initialize two matrices
    matrix m1, m2;
    init_matrix(&m1, 2, 3);
    init_matrix(&m2, 3, 2);

    // set values for the first matrix
    m1.data[0][0] = 1.0;
    m1.data[0][1] = 2.0;
    m1.data[0][2] = 3.0;
    m1.data[1][0] = 4.0;
    m1.data[1][1] = 5.0;
    m1.data[1][2] = 6.0;

    // set values for the second matrix
    m2.data[0][0] = 1.0;
    m2.data[0][1] = 4.0;
    m2.data[1][0] = 2.0;
    m2.data[1][1] = 5.0;
    m2.data[2][0] = 3.0;
    m2.data[2][1] = 6.0;

    // print the matrices
    printf("Matrix 1:\n");
    print_matrix(m1);
    printf("\n");
    printf("Matrix 2:\n");
    print_matrix(m2);
    printf("\n");

    // perform matrix addition and print the result
    printf("Sum of matrices:\n");
    matrix sum = add_matrices(m1, m2);
    print_matrix(sum);
    printf("\n");

    // perform matrix multiplication and print the result
    printf("Product of matrices:\n");
    matrix product = multiply_matrices(m1, m2);
    print_matrix(product);
    printf("\n");

    // free dynamically allocated memory
    for (int i = 0; i < m1.rows; i++) {
        free(m1.data[i]);
    }
    free(m1.data);
    for (int i = 0; i < m2.rows; i++) {
        free(m2.data[i]);
    }
    free(m2.data);
    for (int i = 0; i < sum.rows; i++) {
        free(sum.data[i]);
    }
    free(sum.data);
    for (int i = 0; i < product.rows; i++) {
        free(product.data[i]);
    }
    free(product.data);

    return 0;
}