//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: all-encompassing
#include <stdio.h>

#define ROWS 3
#define COLS 4

// Function to add two matrices
void add_matrices(int a[ROWS][COLS], int b[ROWS][COLS], int c[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract_matrices(int a[ROWS][COLS], int b[ROWS][COLS], int c[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int a[ROWS][COLS], int b[ROWS][COLS], int c[ROWS][COLS]) {
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            c[i][j] = 0;
            for (k = 0; k < COLS; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transpose_matrix(int a[ROWS][COLS], int b[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            b[j][i] = a[i][j];
        }
    }
}

// Function to print a matrix
void print_matrix(int a[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};
    int b[ROWS][COLS] = {{7, 8, 9}, {10, 11, 12}};
    int c[ROWS][COLS];

    // Add matrices a and b
    add_matrices(a, b, c);
    printf("Sum of matrices a and b:\n");
    print_matrix(c);

    // Subtract matrices a and b
    subtract_matrices(a, b, c);
    printf("\nDifference of matrices a and b:\n");
    print_matrix(c);

    // Multiply matrices a and b
    multiply_matrices(a, b, c);
    printf("\nProduct of matrices a and b:\n");
    print_matrix(c);

    // Transpose matrix a
    transpose_matrix(a, c);
    printf("\nTranspose of matrix a:\n");
    print_matrix(c);

    return 0;
}