//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 10000
#define NUM_COLS 10000

// function to calculate the average of a matrix
double matrix_avg(double **matrix, int rows, int cols) {
    double sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return sum / (rows * cols);
}

// function to generate a random matrix
void generate_matrix(double **matrix, int rows, int cols) {
    srand(time(NULL)); // set seed for random number generation
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX; // generate random number between 0 and 1
        }
    }
}

int main() {
    // allocate memory for matrix
    double **matrix = (double **)malloc(NUM_ROWS * sizeof(double *));
    for (int i = 0; i < NUM_ROWS; i++) {
        matrix[i] = (double *)malloc(NUM_COLS * sizeof(double));
    }

    // generate random matrix
    generate_matrix(matrix, NUM_ROWS, NUM_COLS);

    // calculate average of matrix
    double avg = matrix_avg(matrix, NUM_ROWS, NUM_COLS);

    // print results
    printf("Average of matrix: %f\n", avg);

    // free memory
    for (int i = 0; i < NUM_ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}