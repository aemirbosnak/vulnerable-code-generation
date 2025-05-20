//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the matrix dimensions
#define ROWS 5
#define COLS 7

// Define the matrix elements
float matrix[ROWS][COLS] = {
    {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0},
    {8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0},
    {15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0},
    {22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0},
    {29.0, 30.0, 31.0, 32.0, 33.0, 34.0, 35.0}
};

// Define the matrix operations
void matrix_add(float a[ROWS][COLS], float b[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            a[i][j] += b[i][j];
        }
    }
}

void matrix_multiply(float a[ROWS][COLS], float b[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            float sum = 0.0;
            for (int k = 0; k < COLS; k++) {
                sum += a[i][k] * b[k][j];
            }
            a[i][j] = sum;
        }
    }
}

void matrix_print(float a[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize the matrices
    float a[ROWS][COLS] = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0}};
    float b[ROWS][COLS] = {{8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0}};

    // Perform matrix addition
    matrix_add(a, b);

    // Print the result
    matrix_print(a);

    // Perform matrix multiplication
    matrix_multiply(a, b);

    // Print the result
    matrix_print(a);

    return 0;
}