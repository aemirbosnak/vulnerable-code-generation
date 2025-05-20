//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void displayMatrix(int **arr, int rows, int cols) {
    printf("Your wacky matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int **createMatrix(int rows, int cols) {
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the wacky matrix\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    return arr;
}

int **addMatrices(int **arr1, int **arr2, int rows, int cols) {
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    return result;
}

int **multiplyMatrices(int **arr1, int **arr2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Multiplication not possible with these wacky matrices :(\n");
        return NULL;
    }

    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *)calloc(cols2, sizeof(int));
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return result;
}

int main() {
    int rows, cols;
    printf("Enter the number of rows in your wacky matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in your wacky matrix: ");
    scanf("%d", &cols);

    int **arr1 = createMatrix(rows, cols);
    displayMatrix(arr1, rows, cols);

    printf("Enter the second wacky matrix with the same dimensions as the first:\n");
    int **arr2 = createMatrix(rows, cols);
    displayMatrix(arr2, rows, cols);

    int **addResult = addMatrices(arr1, arr2, rows, cols);
    if (addResult != NULL) {
        printf("The sum of your wacky matrices:\n");
        displayMatrix(addResult, rows, cols);
    }

    int rows2, cols2;
    printf("Enter the number of rows in your second wacky matrix: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns in your second wacky matrix: ");
    scanf("%d", &cols2);

    int **multResult = multiplyMatrices(arr1, arr2, rows, cols, rows2, cols2);
    if (multResult != NULL) {
        printf("The product of your wacky matrices:\n");
        displayMatrix(multResult, rows, cols2);
    }

    return 0;
}