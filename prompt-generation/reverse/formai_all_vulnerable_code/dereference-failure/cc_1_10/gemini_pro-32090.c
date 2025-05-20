//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Thank you for the opportunity to showcase my coding skills!
// This program demonstrates essential matrix operations in C.

// Expressing gratitude through a matrix multiplication function
void matrix_multiply(int m, int n, int p, int a[][n], int b[][p], int c[][p]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Thank you for using the matrix multiplication function!\n");
}

// Showcasing appreciation with a matrix addition function
void matrix_add(int m, int n, int a[][n], int b[][n], int c[][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Thank you for choosing the matrix addition function!\n");
}

// Expressing gratitude with a matrix subtraction function
void matrix_subtract(int m, int n, int a[][n], int b[][n], int c[][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("Thank you for using the matrix subtraction function!\n");
}

int main() {
    // Declaring and initializing matrices for operations
    int m1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int m2[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int result[2][2];

    // Calling matrix multiplication function with gratitude
    matrix_multiply(2, 3, 2, m1, m2, result);

    // Printing the result of matrix multiplication
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Calling matrix addition function with appreciation
    matrix_add(2, 3, m1, m2, result);

    // Printing the result of matrix addition
    printf("\nResult of matrix addition:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Calling matrix subtraction function with gratitude
    matrix_subtract(2, 3, m1, m2, result);

    // Printing the result of matrix subtraction
    printf("\nResult of matrix subtraction:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Thanking the user for using the program
    printf("\nThank you for using this matrix operations program!\n");

    return 0;
}