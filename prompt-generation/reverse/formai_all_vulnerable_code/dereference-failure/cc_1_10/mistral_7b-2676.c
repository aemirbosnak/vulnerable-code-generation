//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

typedef struct {
    int value;
    int row;
    int col;
} RecursiveData;

void recursive_factorial(int **array, int row, int col, int depth, RecursiveData *data) {
    if (depth > ROWS * COLS) {
        printf("Factorial calculated: %d\n", data->value);
        return;
    }

    int index = row * COLS + col;
    if (array[row][col] < 0) {
        printf("Error: Array element at (%d, %d) is negative.\n", row, col);
        exit(EXIT_FAILURE);
    }

    data->value *= array[row][col];
    data->row = row;
    data->col = col;

    if (col > 0)
        recursive_factorial(array, row, col - 1, depth + 1, data);

    if (row < ROWS) {
        recursive_factorial(array, row + 1, 0, depth + 1, data);
    }
}

int main() {
    int **array = (int **)malloc(ROWS * sizeof(int *));

    for (int i = 0; i < ROWS; i++) {
        array[i] = (int *)calloc(COLS, sizeof(int));

        for (int j = 0; j < COLS; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    RecursiveData data = {0};
    recursive_factorial(array, 0, 0, 0, &data);

    for (int i = 0; i < ROWS; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}