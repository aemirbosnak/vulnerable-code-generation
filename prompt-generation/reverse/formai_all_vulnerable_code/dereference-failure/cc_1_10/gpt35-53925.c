//FormAI DATASET v1.0 Category: Matrix operations ; Style: automated
#include<stdio.h>
#include<stdlib.h>

// Function to print the given matrix
void printMatrix(int **a, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int **a, int **b, int **sum, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract two matrices
void subMatrix(int **a, int **b, int **result, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int **a, int **b, int **result, int rows1, int cols1, int rows2, int cols2) {
    if(cols1 != rows2) {
        printf("Cannot multiply the matrices\n");
        return;
    }
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<cols2; j++) {
            result[i][j] = 0;
            for(int k=0; k<cols1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    if(rows1 != rows2 || cols1 != cols2) {
        printf("Cannot add or subtract matrices of different sizes\n");
        return 0;
    }
    int **a = (int **)malloc(rows1 * sizeof(int *));
    int **b = (int **)malloc(rows2 * sizeof(int *));
    int **sum = (int **)malloc(rows1 * sizeof(int *));
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for(int i=0; i<rows1; i++) {
        a[i] = (int *)malloc(cols1 * sizeof(int));
        sum[i] = (int *)malloc(cols1 * sizeof(int));
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }
    for(int i=0; i<rows2; i++) {
        b[i] = (int *)malloc(cols2 * sizeof(int));
    }
    printf("Enter the elements of the first matrix:\n");
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<cols1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for(int i=0; i<rows2; i++) {
        for(int j=0; j<cols2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    printf("The first matrix is:\n");
    printMatrix(a, rows1, cols1);
    printf("The second matrix is:\n");
    printMatrix(b, rows2, cols2);
    printf("The sum of the two matrices is:\n");
    addMatrix(a, b, sum, rows1, cols1);
    printMatrix(sum, rows1, cols1);
    printf("The difference between the two matrices is:\n");
    subMatrix(a, b, result, rows1, cols1);
    printMatrix(result, rows1, cols1);
    printf("The product of the two matrices is:\n");
    multiplyMatrix(a, b, result, rows1, cols1, rows2, cols2);
    printMatrix(result, rows1, cols2);
    for(int i=0; i<rows1; i++) {
        free(a[i]);
        free(sum[i]);
        free(result[i]);
    }
    for(int i=0; i<rows2; i++) {
        free(b[i]);
    }
    free(a);
    free(b);
    free(sum);
    free(result);
    return 0;
}