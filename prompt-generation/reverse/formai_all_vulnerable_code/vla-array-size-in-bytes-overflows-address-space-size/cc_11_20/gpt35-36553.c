//FormAI DATASET v1.0 Category: Matrix operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int a[n][m], b[n][m], sum[n][m], diff[n][m], prod[n][m];

    // seed the random number generator
    srand(time(NULL));

    // populate the matrices with random numbers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 21 - 10;
            b[i][j] = rand() % 21 - 10;
        }
    }

    // print matrix a
    printf("\nMatrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // print matrix b
    printf("\nMatrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    // add the matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // print the sum
    printf("\nMatrix A + Matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    // subtract the matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            diff[i][j] = a[i][j] - b[i][j];
        }
    }

    // print the difference
    printf("\nMatrix A - Matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    // multiply the matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                prod[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // print the product
    printf("\nMatrix A * Matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", prod[i][j]);
        }
        printf("\n");
    }

    return 0;
}