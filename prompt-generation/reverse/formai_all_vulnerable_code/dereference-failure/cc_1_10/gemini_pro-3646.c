//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

typedef struct {
    int value;
    bool fixed;
} Cell;

typedef struct {
    Cell **cells;
    int **candidates;
} Board;

Board *create_board() {
    Board *board = malloc(sizeof(Board));
    board->cells = malloc(N * sizeof(Cell *));
    board->candidates = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        board->cells[i] = malloc(N * sizeof(Cell));
        board->candidates[i] = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            board->cells[i][j].value = 0;
            board->cells[i][j].fixed = false;
            board->candidates[i][j] = 0;
        }
    }
    return board;
}

void free_board(Board *board) {
    for (int i = 0; i < N; i++) {
        free(board->cells[i]);
        free(board->candidates[i]);
    }
    free(board->cells);
    free(board->candidates);
    free(board);
}

void print_board(Board *board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board->cells[i][j].value);
        }
        printf("\n");
    }
}

bool is_valid_move(Board *board, int row, int col, int value) {
    // Check if the value is already present in the row
    for (int i = 0; i < N; i++) {
        if (board->cells[row][i].value == value) {
            return false;
        }
    }
    // Check if the value is already present in the column
    for (int i = 0; i < N; i++) {
        if (board->cells[i][col].value == value) {
            return false;
        }
    }
    // Check if the value is already present in the 3x3 subgrid
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
        for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
            if (board->cells[i][j].value == value) {
                return false;
            }
        }
    }
    // The move is valid
    return true;
}

bool solve_sudoku(Board *board) {
    // Find an empty cell
    int row = -1;
    int col = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board->cells[i][j].value == 0) {
                row = i;
                col = j;
                break;
            }
        }
    }
    // If there are no empty cells, the puzzle is solved
    if (row == -1) {
        return true;
    }
    // Try all possible values for the empty cell
    for (int value = 1; value <= N; value++) {
        if (is_valid_move(board, row, col, value)) {
            // Set the value of the empty cell
            board->cells[row][col].value = value;
            // Recursively solve the rest of the puzzle
            if (solve_sudoku(board)) {
                return true;
            }
            // If the recursive call failed, reset the value of the empty cell
            board->cells[row][col].value = 0;
        }
    }
    // If no valid values were found for the empty cell, the puzzle cannot be solved
    return false;
}

int main() {
    Board *board = create_board();
    // Set the fixed values in the board
    board->cells[0][0].value = 5;
    board->cells[0][0].fixed = true;
    board->cells[0][1].value = 3;
    board->cells[0][1].fixed = true;
    board->cells[0][4].value = 6;
    board->cells[0][4].fixed = true;
    board->cells[1][0].value = 6;
    board->cells[1][0].fixed = true;
    board->cells[1][3].value = 1;
    board->cells[1][3].fixed = true;
    board->cells[1][4].value = 7;
    board->cells[1][4].fixed = true;
    board->cells[2][1].value = 4;
    board->cells[2][1].fixed = true;
    board->cells[2][2].value = 9;
    board->cells[2][2].fixed = true;
    board->cells[2][5].value = 8;
    board->cells[2][5].fixed = true;
    // Solve the Sudoku puzzle
    if (solve_sudoku(board)) {
        printf("The Sudoku puzzle was solved successfully.\n");
        print_board(board);
    } else {
        printf("The Sudoku puzzle could not be solved.\n");
    }
    free_board(board);
    return 0;
}