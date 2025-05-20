//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define MAX 100

double matrix_operations(double **a, double **b, double **c, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                double product = 0.0;
                for (int l = 0; l < n; l++) {
                    product += a[i][l] * b[l][k] * c[k][j];
                }
                sum += product;
            }
        }
    }
    return sum;
}

int main() {
    int n = 3;
    double **a = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        a[i] = (double *)malloc(n * sizeof(double));
    }
    double **b = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        b[i] = (double *)malloc(n * sizeof(double));
    }
    double **c = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        c[i] = (double *)malloc(n * sizeof(double));
    }

    a[0][0] = 1.0;
    a[0][1] = 2.0;
    a[0][2] = 3.0;
    a[1][0] = 4.0;
    a[1][1] = 5.0;
    a[1][2] = 6.0;
    a[2][0] = 7.0;
    a[2][1] = 8.0;
    a[2][2] = 9.0;

    b[0][0] = 2.0;
    b[0][1] = 3.0;
    b[0][2] = 4.0;
    b[1][0] = 5.0;
    b[1][1] = 6.0;
    b[1][2] = 7.0;
    b[2][0] = 8.0;
    b[2][1] = 9.0;
    b[2][2] = 10.0;

    c[0][0] = 3.0;
    c[0][1] = 4.0;
    c[0][2] = 5.0;
    c[1][0] = 6.0;
    c[1][1] = 7.0;
    c[1][2] = 8.0;
    c[2][0] = 9.0;
    c[2][1] = 10.0;
    c[2][2] = 11.0;

    double sum = matrix_operations(a, b, c, n);
    printf("%f", sum);

    free(a);
    free(b);
    free(c);

    return 0;
}