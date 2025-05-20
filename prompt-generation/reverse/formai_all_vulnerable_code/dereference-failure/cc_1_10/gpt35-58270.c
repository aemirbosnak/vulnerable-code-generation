//FormAI DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random values
void randomize(int n, int m, int arr[n][m]) {
    int i, j;
    srand(time(NULL));
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            arr[i][j] = rand() % 100; // Random values from 0 to 99
        }
    }
}

void printMatrix(int n, int m, int arr[n][m]) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void matrixMultiplication(int n, int m1, int m2, int arr1[n][m1], int arr2[m1][m2], int res[n][m2]) {
    int i, j, k;
    for(i=0; i<n; i++) {
        for(j=0; j<m2; j++) {
            res[i][j] = 0;
            for(k=0; k<m1; k++) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int main() {
    int n=3, m1=2, m2=3;
    int arr1[n][m1], arr2[m1][m2], res[n][m2];

    // Randomize values in array1 and array2
    randomize(n, m1, arr1);
    printf("Matrix 1:\n");
    printMatrix(n, m1, arr1);

    randomize(m1, m2, arr2);
    printf("\nMatrix 2:\n");
    printMatrix(m1, m2, arr2);

    // Matrix multiplication
    matrixMultiplication(n, m1, m2, arr1, arr2, res);

    printf("\nResultant Matrix:\n");
    printMatrix(n, m2, res);

    return 0;
}