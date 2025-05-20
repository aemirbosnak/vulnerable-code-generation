//FormAI DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **createMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

int **readMatrix(int rows, int cols) {
    int **matrix = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

int **addMatrix(int **a, int **b, int rows, int cols) {
    int **result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

int **subtractMatrix(int **a, int **b, int rows, int cols) {
    int **result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

int **multiplyMatrix(int **a, int **b, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        return NULL;
    }
    int **result = createMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    int **a = NULL, **b = NULL, **result = NULL;

    printf("Enter the values of matrix 1:\n");
    a = readMatrix(rows1, cols1);

    printf("Enter the values of matrix 2:\n");
    b = readMatrix(rows2, cols2);

    printf("\nMatrix 1:\n");
    printMatrix(a, rows1, cols1);

    printf("\nMatrix 2:\n");
    printMatrix(b, rows2, cols2);

    result = addMatrix(a, b, rows1, cols1);
    if (result != NULL) {
        printf("\nMatrix 1 + Matrix 2:\n");
        printMatrix(result, rows1, cols1);
        freeMatrix(result, rows1);
        result = NULL;
    } else {
        printf("\nMatrix addition not possible\n");
    }

    result = subtractMatrix(a, b, rows1, cols1);
    if (result != NULL) {
        printf("\nMatrix 1 - Matrix 2:\n");
        printMatrix(result, rows1, cols1);
        freeMatrix(result, rows1);
        result = NULL;
    } else {
        printf("\nMatrix subtraction not possible\n");
    }

    result = multiplyMatrix(a, b, rows1, cols1, rows2, cols2);
    if (result != NULL) {
        printf("\nMatrix 1 * Matrix 2:\n");
        printMatrix(result, rows1, cols2);
        freeMatrix(result, rows1);
        result = NULL;
    } else {
        printf("\nMatrix multiplication not possible\n");
    }

    freeMatrix(a, rows1);
    freeMatrix(b, rows2);

    return 0;
}