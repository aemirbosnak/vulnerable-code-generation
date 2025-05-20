//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 21

void fibonacci_2d(int **arr, int row, int col);
void print_2d_arr(int **arr, int row, int col);

int main() {
    int i, j;
    int **fib_arr;

    fib_arr = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++) {
        fib_arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    printf("Enter the number of rows: ");
    scanf("%d", &i);

    if (i > MAX_SIZE || i < 0) {
        printf("Invalid input! Exiting...\n");
        exit(1);
    }

    fibonacci_2d(fib_arr, i, MAX_SIZE);
    print_2d_arr(fib_arr, i, MAX_SIZE);

    for (i = 0; i < MAX_SIZE * i; i++) {
        free(fib_arr[i]);
    }
    free(fib_arr);

    return 0;
}

void fibonacci_2d(int **arr, int row, int col) {
    int i, j, temp;

    // Base case: 1x1 matrix
    if (row <= 1) {
        arr[0][0] = 1;
        return;
    }

    // Fill the first row and column
    for (i = 0; i < row; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }

    // Recursive call for the sub-matrix
    fibonacci_2d(arr, row - 1, col);

    // Fill the rest of the matrix using the previously calculated values
    for (i = 1; i < row; i++) {
        for (j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
}

void print_2d_arr(int **arr, int row, int col) {
    int i, j;

    printf("\nFibonacci Matrix:\n");

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}