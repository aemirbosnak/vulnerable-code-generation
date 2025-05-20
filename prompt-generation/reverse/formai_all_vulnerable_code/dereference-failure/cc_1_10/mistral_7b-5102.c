//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

void input_matrix(double **matrix, int size) {
    for (int i = 0; i < size; i++) {
        matrix[i] = (double *)calloc(size, sizeof(double));
        for (int j = 0; j < size; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void print_matrix(double **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void gauss_seidel(double **matrix, double *b, double *x, int size) {
    double error = 1e10;
    int iter = 0;
    double temp[MAX_SIZE];

    while (error > 1e-6 && iter < 1000) {
        for (int i = 0; i < size; i++) {
            temp[i] = x[i];
            x[i] = (b[i] - (matrix[i][i] * x[i]));
            for (int j = 0; j < size; j++) {
                if (j != i) {
                    x[i] -= (matrix[i][j] * x[j]);
                }
            }
            x[i] /= (matrix[i][i]);
        }

        error = 0;
        for (int i = 0; i < size; i++) {
            error += pow(fabs(x[i] - temp[i]), 2);
        }
        error = sqrt(error);
        iter++;
    }

    if (iter >= 1000) {
        printf("Iteration limit reached.\n");
    }
}

int main() {
    int size;
    double **matrix, *b, *x;

    printf("Enter the size of the matrix: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Matrix size too large.\n");
        return -1;
    }

    matrix = (double **)calloc(size, sizeof(double *));
    b = (double *)calloc(size, sizeof(double));
    x = (double *)calloc(size, sizeof(double));

    input_matrix(matrix, size);
    print_matrix(matrix, size);

    printf("Enter the right-hand side vector:\n");
    input_matrix(b, size);

    gauss_seidel(matrix, b, x, size);

    printf("Solution vector:\n");
    print_matrix(x, size);

    free(matrix);
    free(b);
    free(x);

    return 0;
}