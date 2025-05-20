//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scientific
#include <stdio.h>
#include <math.h>

#define N 3     // Number of nodes

// Function prototypes
double dmin(double a, double b);
void solve(double **A, double *B);

int main()
{
    // Define circuit parameters
    double R1 = 1000.0, R2 = 2000.0, R3 = 3000.0, R4 = 4000.0, R5 = 5000.0;
    double V1 = 10.0, V2 = 20.0;

    // Define node equations
    double **A = (double **) malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        A[i] = (double *) malloc(N * sizeof(double));
    }
    A[0][0] = 1.0/R1 + 1.0/R2;
    A[0][1] = -1.0/R2;
    A[1][0] = -1.0/R2;
    A[1][1] = 1.0/R2 + 1.0/R3 + 1.0/R4;
    A[1][2] = -1.0/R4;
    A[2][1] = -1.0/R4;
    A[2][2] = 1.0/R4 + 1.0/R5;

    // Define source vector
    double *B = (double *) malloc(N * sizeof(double));
    B[0] = V1/R1;
    B[1] = 0.0;
    B[2] = -V2/R5;

    // Solve the system of equations
    solve(A, B);

    // Print results
    printf("Node voltages:\n");
    printf("v1 = %f V\n", B[0]);
    printf("v2 = %f V\n", B[1]);
    printf("v3 = %f V\n", B[2]);

    return 0;
}

// Function to compute minimum of two values
double dmin(double a, double b)
{
    return a < b ? a : b;
}

// Function to solve a system of linear equations of the form A*x = B
void solve(double **A, double *B)
{
    double pivot, factor;
    int i, j, k;

    // Forward elimination
    for (i = 0; i < N - 1; i++) {
        pivot = A[i][i];
        for (j = i + 1; j < N; j++) {
            factor = dmin(1.0, fabs(A[j][i] / pivot));
            for (k = i; k < N; k++) {
                A[j][k] = A[j][k] - factor * A[i][k];
            }
            B[j] = B[j] - factor * B[i];
        }
    }

    // Backward substitution
    for (i = N - 1; i >= 0; i--) {
        B[i] = B[i] / A[i][i];
        for (j = i - 1; j >= 0; j--) {
            B[j] = B[j] - A[j][i] * B[i];
        }
    }
}