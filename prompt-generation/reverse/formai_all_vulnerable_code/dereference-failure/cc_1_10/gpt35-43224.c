//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include <stdio.h>
#include <math.h>

#define NODE_NUM 4
#define RESISTOR_NUM 3

void printMatrix(double **A, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double **A = malloc(NODE_NUM * sizeof(double *));
    for(int i = 0; i < NODE_NUM; i++) {
        A[i] = malloc(NODE_NUM * sizeof(double));
    }

    double *b = malloc(NODE_NUM * sizeof(double));

    double resistors[RESISTOR_NUM] = {10.0, 20.0, 30.0};

    A[0][0] = 1.0 / resistors[0];
    A[0][2] = -1.0 / resistors[0];

    A[1][0] = -1.0 / resistors[0];
    A[1][1] = 1.0 / resistors[0] + 1.0 / resistors[1];
    A[1][3] = -1.0 / resistors[1];

    A[2][2] = -1.0 / resistors[2];
    A[2][3] = 1.0 / resistors[2];

    A[3][1] = -1.0 / resistors[1];
    A[3][2] = 1.0 / resistors[1] + 1.0 / resistors[2];

    b[1] = 10.0 / resistors[0];
    b[3] = 10.0 / resistors[2];

    printMatrix(A, NODE_NUM, NODE_NUM);

    // Solve for x using Gaussian elimination
    for(int i = 0; i < NODE_NUM - 1; i++) {
        for(int j = i + 1; j < NODE_NUM; j++) {
            double factor = A[j][i] / A[i][i];
            for(int k = i + 1; k < NODE_NUM; k++) {
                A[j][k] -= factor * A[i][k];
            }
            b[j] -= factor * b[i];
            A[j][i] = 0;
        }
    }

    double x[NODE_NUM];
    for(int i = NODE_NUM - 1; i >= 0; i--) {
        double sum = 0;
        for(int j = i + 1; j < NODE_NUM; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }

    for(int i = 0; i < NODE_NUM; i++) {
        printf("Node %d has voltage %lf\n", i, x[i]);
    }

    for(int i = 0; i < NODE_NUM; i++) {
        free(A[i]);
    }
    free(A);
    free(b);

    return 0;
}