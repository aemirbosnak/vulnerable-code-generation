//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Matrix operations are like pizza deliveries - they can get a little messy

// Function to multiply two matrices
void matrix_mult(int **a, int **b, int **c) {
    int i, j, k;

    // Make sure the matrices are the right size
    if (a[0][0] != b[0][0] || a[1][0] != b[1][0]) {
        printf("Matrix sizes don't match! Maybe you should try a different pizza topping?\n");
        return;
    }

    // Loop through the matrices, multiplying as we go
    for (i = 0; i < a[0][0]; i++) {
        for (j = 0; j < a[1][0]; j++) {
            int sum = 0;

            for (k = 0; k < b[0][0]; k++) {
                sum += a[i][k] * b[k][j];
            }

            c[i][j] = sum;
        }
    }
}

// Function to add two matrices
void matrix_add(int **a, int **b, int **c) {
    int i, j, k;

    // Make sure the matrices are the right size
    if (a[0][0] != b[0][0] || a[1][0] != b[1][0]) {
        printf("Matrix sizes don't match! Maybe you should try a different pizza topping?\n");
        return;
    }

    // Loop through the matrices, adding as we go
    for (i = 0; i < a[0][0]; i++) {
        for (j = 0; j < a[1][0]; j++) {
            int sum = 0;

            for (k = 0; k < b[0][0]; k++) {
                sum += a[i][k] + b[k][j];
            }

            c[i][j] = sum;
        }
    }
}

int main() {
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b[2][3] = {{7, 8, 9}, {10, 11, 12}};
    int c[2][3];

    // Multiply the matrices
    matrix_mult(a, b, c);

    // Add the matrices
    matrix_add(a, b, c);

    // Print the results
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}