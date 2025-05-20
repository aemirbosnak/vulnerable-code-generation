//FormAI DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

void matrix_addition(int m, int n, int a[m][n], int b[m][n], int result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void matrix_subtraction(int m, int n, int a[m][n], int b[m][n], int result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void matrix_multiplication(int m1, int n1, int m2, int n2, int a[m1][n1], int b[m2][n2], int result[m1][n2]) {
    if (n1 != m2) {
        printf("Error: Invalid matrix dimensions\n");
        return;
    }

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void matrix_transpose(int m, int n, int a[m][n], int result[n][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = a[i][j];
        }
    }
}

void matrix_print(int m, int n, int a[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m1 = 2; 
    int n1 = 3;
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

    int m2 = 3;
    int n2 = 2;
    int b[3][2] = {{7, 8}, {9, 10}, {11, 12}};

    int result[m1][n2];

    printf("Matrix A:\n");
    matrix_print(m1, n1, a);

    printf("Matrix B:\n");
    matrix_print(m2, n2, b);

    matrix_multiplication(m1, n1, m2, n2, a, b, result);

    printf("A x B:\n");
    matrix_print(m1, n2, result);

    int c[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int d[2][3] = {{7, 8, 9}, {10, 11, 12}};
    int sum[2][3];

    printf("Matrix C:\n");
    matrix_print(m1, n1, c);

    printf("Matrix D:\n");
    matrix_print(m1, n1, d);

    matrix_addition(m1, n1, c, d, sum);

    printf("C + D:\n");
    matrix_print(m1, n1, sum);

    int e[2][2] = {{1, 2}, {3, 4}};
    int e_t[2][2];

    printf("Matrix E:\n");
    matrix_print(2, 2, e);

    matrix_transpose(2, 2, e, e_t);

    printf("Transpose of E:\n");
    matrix_print(2, 2, e_t);

    return 0;
}