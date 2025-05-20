//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9
#define MAX_TRIES 1000

int **create_matrix(int size) {
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void print_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int **matrix, int row, int col, int num) {
    for (int i = 0; i < row; i++) {
        if (matrix[i][col] == num) {
            return 0;
        }
    }
    for (int i = 0; i < col; i++) {
        if (matrix[row][i] == num) {
            return 0;
        }
    }
    int sub_row = (row / 3) * 3;
    int sub_col = (col / 3) * 3;
    for (int i = sub_row; i < sub_row + 3; i++) {
        for (int j = sub_col; j < sub_col + 3; j++) {
            if (matrix[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku(int **matrix, int size) {
    int tries = 0;
    while (tries < MAX_TRIES) {
        int row = rand() % size;
        int col = rand() % size;
        if (matrix[row][col] == 0) {
            for (int num = 1; num <= size; num++) {
                if (is_valid(matrix, row, col, num)) {
                    matrix[row][col] = num;
                    if (solve_sudoku(matrix, size)) {
                        return 1;
                    } else {
                        matrix[row][col] = 0;
                    }
                }
            }
            return 0;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int size = MAX_SIZE;
    int **matrix = create_matrix(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
    solve_sudoku(matrix, size);
    print_matrix(matrix, size);
    return 0;
}