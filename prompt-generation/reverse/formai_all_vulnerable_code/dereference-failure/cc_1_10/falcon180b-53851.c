//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 50
#define MAX_COLS 50

int main() {
    int rows, cols;
    int i, j;
    int **matrix;
    int sum = 0;
    int max_val = 0;
    int min_val = 9999;

    srand(time(NULL));
    rows = rand() % MAX_ROWS + 1;
    cols = rand() % MAX_COLS + 1;

    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
            sum += matrix[i][j];
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
            }
            if (matrix[i][j] < min_val) {
                min_val = matrix[i][j];
            }
        }
    }

    printf("Random Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSum: %d\n", sum);
    printf("Max Value: %d\n", max_val);
    printf("Min Value: %d\n", min_val);

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}