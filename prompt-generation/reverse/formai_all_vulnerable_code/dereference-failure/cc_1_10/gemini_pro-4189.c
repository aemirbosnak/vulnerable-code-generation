//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9
#define BOX_SIZE 3

typedef bool (*SudokuSolver)(int **board, int row, int col);

static bool is_valid(int **board, int row, int col, int candidate) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == candidate || board[i][col] == candidate) {
            return false;
        }
    }

    int box_row = row / BOX_SIZE * BOX_SIZE;
    int box_col = col / BOX_SIZE * BOX_SIZE;
    for (int i = box_row; i < box_row + BOX_SIZE; i++) {
        for (int j = box_col; j < box_col + BOX_SIZE; j++) {
            if (board[i][j] == candidate) {
                return false;
            }
        }
    }

    return true;
}

static bool solve_sudoku(int **board, int row, int col) {
    if (row == SIZE) {
        return true;
    }

    if (board[row][col] != 0) {
        return solve_sudoku(board, (col == SIZE - 1) ? row + 1 : row, (col == SIZE - 1) ? 0 : col + 1);
    }

    for (int candidate = 1; candidate <= SIZE; candidate++) {
        if (is_valid(board, row, col, candidate)) {
            board[row][col] = candidate;
            if (solve_sudoku(board, (col == SIZE - 1) ? row + 1 : row, (col == SIZE - 1) ? 0 : col + 1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int **board = malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        board[i] = malloc(SIZE * sizeof(int));
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    if (solve_sudoku(board, 0, 0)) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }

    for (int i = 0; i < SIZE; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}