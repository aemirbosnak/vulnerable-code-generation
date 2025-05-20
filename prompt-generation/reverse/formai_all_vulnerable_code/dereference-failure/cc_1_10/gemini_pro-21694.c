//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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

void destroy_board(Board* board) {
    free(board);
}

bool is_valid_move(Board* board, int row, int col, int value) {
    // Check if the value is already present in the row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->cells[row * BOARD_SIZE + i].value == value) {
            return false;
        }
    }

    // Check if the value is already present in the column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->cells[i * BOARD_SIZE + col].value == value) {
            return false;
        }
    }

    // Check if the value is already present in the 3x3 box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = box_row * 3; i < (box_row + 1) * 3; i++) {
        for (int j = box_col * 3; j < (box_col + 1) * 3; j++) {
            if (board->cells[i * BOARD_SIZE + j].value == value) {
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(Board* board) {
    // If all cells are filled, the puzzle is solved
    if (board->num_cells == BOARD_SIZE * BOARD_SIZE) {
        return true;
    }

    // Find an empty cell
    int row, col;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (board->cells[row * BOARD_SIZE + col].value == 0) {
                break;
            }
        }
        if (col != BOARD_SIZE) {
            break;
        }
    }

    // Try all possible values for the empty cell
    for (int value = 1; value <= BOARD_SIZE; value++) {
        if (is_valid_move(board, row, col, value)) {
            // Set the value and recursively solve the puzzle
            board->cells[row * BOARD_SIZE + col].value = value;
            board->num_cells++;
            if (solve_sudoku(board)) {
                return true;
            }
            // If the puzzle cannot be solved with the current value, reset the cell
            board->num_cells--;
            board->cells[row * BOARD_SIZE + col].value = 0;
        }
    }

    // If no valid value can be found for the empty cell, the puzzle cannot be solved
    return false;
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
    // Create a new board
    Board* board = create_board();

    // Read the puzzle from a file
    FILE* fp = fopen("puzzle.txt", "r");
    assert(fp != NULL);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            fscanf(fp, "%d ", &board->cells[i * BOARD_SIZE + j].value);
        }
    }
    fclose(fp);

    // Solve the puzzle
    bool solved = solve_sudoku(board);

    // Print the solved puzzle
    if (solved) {
        print_board(board);
    } else {
        printf("Puzzle cannot be solved\n");
    }

    // Destroy the board
    destroy_board(board);

    return 0;
}