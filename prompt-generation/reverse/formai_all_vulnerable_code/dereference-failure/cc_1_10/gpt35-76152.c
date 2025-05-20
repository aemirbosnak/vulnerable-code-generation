//FormAI DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>

// Let's create a matrix of size n x m
int n = 3;
int m = 3;

// Function to print matrix 
void printMatrix(int arr[][m]) {
    printf("The matrix is: \n");
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply matrix 
void multiplyMatrix(int arr1[][m], int arr2[][m]) {
    int result[n][m];

    // Initializing elements of result matrix
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            result[i][j] = 0;
        }
    }

    // Multiplying matrix and storing in result matrix
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            for (int k=0; k < m; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    // Printing matrix
    printf("The result of matrix multiplication is: \n");
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {

    // Initializing matrices
    int arr1[][3]={{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    int arr2[][3]={{9, 8, 7},{6, 5, 4},{3, 2, 1}};

    // Printing matrices
    printMatrix(arr1);
    printf("\n");
    printMatrix(arr2);
    printf("\n");

    // Multiplying matrices
    multiplyMatrix(arr1, arr2);

    return 0;
}