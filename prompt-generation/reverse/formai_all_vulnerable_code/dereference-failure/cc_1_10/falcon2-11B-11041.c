//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 1000
#define COLS 1000

int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
    return matrix;
}

int** fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = -1;
            }
        }
    }
    return matrix;
}

int** applyRule(int** matrix, int rows, int cols, int i, int j) {
    int count = 0;
    int up = i - 1;
    int down = i + 1;
    int left = j - 1;
    int right = j + 1;
    if (up >= 0 && matrix[up][j] == 1) {
        count++;
    }
    if (down < rows && matrix[down][j] == 1) {
        count++;
    }
    if (left >= 0 && matrix[i][left] == 1) {
        count++;
    }
    if (right < cols && matrix[i][right] == 1) {
        count++;
    }
    if (matrix[i][j] == 1 && (count == 2 || count == 3)) {
        matrix[i][j] = -1;
    } else if (matrix[i][j] == 1 && count == 4) {
        matrix[i][j] = 0;
    } else if (matrix[i][j] == -1) {
        matrix[i][j] = 0;
    }
    return matrix;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int** matrix = createMatrix(ROWS, COLS);
    printf("Initial Matrix:\n");
    printMatrix(matrix, ROWS, COLS);
    fillMatrix(matrix, ROWS, COLS);
    printf("\nAfter Rule 1:\n");
    printMatrix(matrix, ROWS, COLS);
    applyRule(matrix, ROWS, COLS, 0, 0);
    printf("\nAfter Rule 2:\n");
    printMatrix(matrix, ROWS, COLS);
    applyRule(matrix, ROWS, COLS, 0, 0);
    printf("\nAfter Rule 3:\n");
    printMatrix(matrix, ROWS, COLS);
    applyRule(matrix, ROWS, COLS, 0, 0);
    printf("\nAfter Rule 4:\n");
    printMatrix(matrix, ROWS, COLS);
    applyRule(matrix, ROWS, COLS, 0, 0);
    printf("\nAfter Rule 5:\n");
    printMatrix(matrix, ROWS, COLS);
    applyRule(matrix, ROWS, COLS, 0, 0);
    printf("\nAfter Rule 6:\n");
    printMatrix(matrix, ROWS, COLS);
    applyRule(matrix, ROWS, COLS, 0, 0);
    printf("\nAfter Rule 7:\n");
    printMatrix(matrix, ROWS, COLS);
    applyRule(matrix, ROWS, COLS, 0, 0);
    printf("\nAfter Rule 8:\n");
    printMatrix(matrix, ROWS, COLS);
    applyRule(matrix, ROWS, COLS, 0, 0);
    printf("\nAfter Rule 9:\n");
    printMatrix(matrix, ROWS, COLS);
    applyRule(matrix, ROWS, COLS, 0, 0);
    printf("\nAfter Rule 10:\n");
    printMatrix(matrix, ROWS, COLS);
    printf("Done!\n");
    return 0;
}