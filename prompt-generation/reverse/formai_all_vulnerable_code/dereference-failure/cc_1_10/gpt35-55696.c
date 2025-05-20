//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>

// Function to print matrix in a funny way
void matrix_printer(int rows, int cols, int matrix[rows][cols]) {
    printf("\nMatrix:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j] + 7);
        }
        printf("\n");
    }
}

int main() {
    // Creating a matrix and filling it with random numbers
    int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

    printf("Welcome to the Matrix Operations program!\n");

    // Calling the matrix printer function to print the original matrix
    matrix_printer(3, 3, matrix);

    // Performing matrix addition with a scalar
    int scalar = 5;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            matrix[i][j] += scalar;
        }
    }

    printf("\nMatrix after adding %d:\n", scalar);
    matrix_printer(3, 3, matrix);

    // Performing matrix multiplication
    int matrix2[3][2] = {{2,3}, {4,5}, {6,7}};
    int result[3][2] = {{0,0}, {0,0}, {0,0}};

    printf("\nLet's do some matrix multiplication!\n");
    printf("Multiplying matrix:\n");
    matrix_printer(3, 2, matrix2);
    printf("with matrix:\n");
    matrix_printer(3, 3, matrix);

    for(int i=0; i<3; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) {
                result[i][j] += matrix[i][k] * matrix2[k][j];
            }
        }
    }

    printf("\nResulting matrix:\n");
    matrix_printer(3, 2, result);

    printf("\nThanks for using the Matrix Operations program! Don't let the matrix swallow you!\n");

    return 0;
}