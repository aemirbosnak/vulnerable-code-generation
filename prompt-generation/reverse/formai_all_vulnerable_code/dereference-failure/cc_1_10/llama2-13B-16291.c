//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

// Matrix operations
void matrix_add(float (*a)[MATRIX_COLS], float (*b)[MATRIX_COLS], float (*c)[MATRIX_COLS]);
void matrix_subtract(float (*a)[MATRIX_COLS], float (*b)[MATRIX_COLS], float (*c)[MATRIX_COLS]);
void matrix_multiply(float (*a)[MATRIX_COLS], float (*b)[MATRIX_COLS], float (*c)[MATRIX_COLS]);
void matrix_transpose(float (*a)[MATRIX_COLS], float (*b)[MATRIX_COLS]);

// Utility functions
void print_matrix(float (*a)[MATRIX_COLS]);
void free_matrix(float (*a)[MATRIX_COLS]);

int main() {
    // Create matrices
    float (*a)[MATRIX_COLS] = malloc(MATRIX_ROWS * MATRIX_COLS * sizeof(float));
    float (*b)[MATRIX_COLS] = malloc(MATRIX_ROWS * MATRIX_COLS * sizeof(float));
    float (*c)[MATRIX_COLS] = malloc(MATRIX_ROWS * MATRIX_COLS * sizeof(float));

    // Initialize matrices
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a[i][j] = i * j;
            b[i][j] = i + j;
            c[i][j] = 0;
        }
    }

    // Perform matrix operations
    matrix_add(a, b, c);
    matrix_subtract(a, b, c);
    matrix_multiply(a, b, c);
    matrix_transpose(a, b);

    // Print matrices
    print_matrix(a);
    print_matrix(b);
    print_matrix(c);

    // Free matrices
    free_matrix(a);
    free_matrix(b);
    free_matrix(c);

    return 0;
}

// Matrix addition
void matrix_add(float (*a)[MATRIX_COLS], float (*b)[MATRIX_COLS], float (*c)[MATRIX_COLS]) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Matrix subtraction
void matrix_subtract(float (*a)[MATRIX_COLS], float (*b)[MATRIX_COLS], float (*c)[MATRIX_COLS]) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Matrix multiplication
void matrix_multiply(float (*a)[MATRIX_COLS], float (*b)[MATRIX_COLS], float (*c)[MATRIX_COLS]) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            for (int k = 0; k < MATRIX_COLS; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Matrix transpose
void matrix_transpose(float (*a)[MATRIX_COLS], float (*b)[MATRIX_COLS]) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            b[j][i] = a[i][j];
        }
    }
}

// Utility functions
void print_matrix(float (*a)[MATRIX_COLS]) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(float (*a)[MATRIX_COLS]) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        free(a[i]);
    }
    free(a);
}