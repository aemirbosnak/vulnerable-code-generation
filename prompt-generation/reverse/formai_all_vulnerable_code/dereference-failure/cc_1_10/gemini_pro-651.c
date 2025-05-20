//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 9

typedef struct {
    int row;
    int col;
    int value;
} Cell;

typedef struct {
    Cell cells[BOARD_SIZE * BOARD_SIZE];
    int num_cells;
} Board;

Board* create_board() {
    Board* board = malloc(sizeof(Board));
    board->num_cells = 0;
    return board;
}

void free_board(Board* board) {
    free(board);
}

int is_valid_move(Board* board, int row, int col, int value) {
    // Check if the value is already present in the row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->cells[row * BOARD_SIZE + i].value == value) {
            return 0;
        }
    }

    // Check if the value is already present in the column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->cells[i * BOARD_SIZE + col].value == value) {
            return 0;
        }
    }

    // Check if the value is already present in the 3x3 box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cell = (box_row * 3 + i) * BOARD_SIZE + box_col * 3 + j;
            if (board->cells[cell].value == value) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku(Board* board) {
    // Find the first empty cell
    int row = -1;
    int col = -1;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        if (board->cells[i].value == 0) {
            row = board->cells[i].row;
            col = board->cells[i].col;
            break;
        }
    }

    // If there are no empty cells, the sudoku is solved
    if (row == -1 || col == -1) {
        return 1;
    }

    // Try all possible values for the empty cell
    for (int value = 1; value <= BOARD_SIZE; value++) {
        if (is_valid_move(board, row, col, value)) {
            // Set the value of the empty cell
            board->cells[row * BOARD_SIZE + col].value = value;

            // Recursively solve the sudoku
            if (solve_sudoku(board)) {
                return 1;
            } else {
                // If the sudoku could not be solved with the current value, reset the value of the empty cell to 0
                board->cells[row * BOARD_SIZE + col].value = 0;
            }
        }
    }

    return 0;
}

void print_board(Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board->cells[i * BOARD_SIZE + j].value);
        }
        printf("\n");
    }
}

int main() {
    Board* board = create_board();

    // Set the values of the given cells
    board->cells[0].row = 0;
    board->cells[0].col = 0;
    board->cells[0].value = 5;
    board->cells[1].row = 0;
    board->cells[1].col = 2;
    board->cells[1].value = 3;
    board->cells[2].row = 2;
    board->cells[2].col = 1;
    board->cells[2].value = 4;
    board->cells[3].row = 3;
    board->cells[3].col = 3;
    board->cells[3].value = 7;
    board->cells[4].row = 4;
    board->cells[4].col = 0;
    board->cells[4].value = 1;
    board->cells[5].row = 5;
    board->cells[5].col = 2;
    board->cells[5].value = 6;
    board->cells[6].row = 6;
    board->cells[6].col = 1;
    board->cells[6].value = 8;
    board->cells[7].row = 8;
    board->cells[7].col = 1;
    board->cells[7].value = 9;
    board->cells[8].row = 8;
    board->cells[8].col = 3;
    board->cells[8].value = 2;

    // Solve the sudoku
    if (solve_sudoku(board)) {
        printf("The sudoku was solved successfully:\n");
        print_board(board);
    } else {
        printf("The sudoku could not be solved.\n");
    }

    free_board(board);

    return 0;
}