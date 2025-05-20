//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 9
#define EMPTY_CELL 0

// Define a cell structure to store the value and the possibilities of a cell
typedef struct {
    int value;
    bool possibilities[BOARD_SIZE + 1];
} Cell;

// Create a new sudoku board
Cell** create_board() {
    Cell** board = malloc(sizeof(Cell*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(sizeof(Cell) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = EMPTY_CELL;
            for (int k = 1; k <= BOARD_SIZE; k++) {
                board[i][j].possibilities[k] = true;
            }
        }
    }
    return board;
}

// Free the memory allocated for the sudoku board
void destroy_board(Cell** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);
}

// Load the sudoku board from a file
bool load_board(Cell** board, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int value;
            if (fscanf(file, "%d ", &value) != 1) {
                fclose(file);
                return false;
            }
            board[i][j].value = value;
            if (value != EMPTY_CELL) {
                for (int k = 1; k <= BOARD_SIZE; k++) {
                    board[i][j].possibilities[k] = (k == value);
                }
            }
        }
    }

    fclose(file);
    return true;
}

// Print the sudoku board to the console
void print_board(Cell** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j].value);
        }
        printf("\n");
    }
}

// Check if the sudoku board is valid
bool is_valid_board(Cell** board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        bool used[BOARD_SIZE + 1] = { false };
        for (int j = 0; j < BOARD_SIZE; j++) {
            int value = board[i][j].value;
            if (value != EMPTY_CELL) {
                if (used[value]) {
                    return false;
                }
                used[value] = true;
            }
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        bool used[BOARD_SIZE + 1] = { false };
        for (int i = 0; i < BOARD_SIZE; i++) {
            int value = board[i][j].value;
            if (value != EMPTY_CELL) {
                if (used[value]) {
                    return false;
                }
                used[value] = true;
            }
        }
    }

    // Check 3x3 blocks
    for (int i = 0; i < BOARD_SIZE; i += 3) {
        for (int j = 0; j < BOARD_SIZE; j += 3) {
            bool used[BOARD_SIZE + 1] = { false };
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    int value = board[k][l].value;
                    if (value != EMPTY_CELL) {
                        if (used[value]) {
                            return false;
                        }
                        used[value] = true;
                    }
                }
            }
        }
    }

    return true;
}

// Find the next empty cell in the sudoku board
bool find_empty_cell(Cell** board, int* row, int* col) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].value == EMPTY_CELL) {
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false;
}

// Solve the sudoku board using backtracking
bool solve_board(Cell** board) {
    int row, col;
    if (!find_empty_cell(board, &row, &col)) {
        return true;
    }

    for (int value = 1; value <= BOARD_SIZE; value++) {
        if (board[row][col].possibilities[value]) {
            board[row][col].value = value;
            if (solve_board(board)) {
                return true;
            }
            board[row][col].value = EMPTY_CELL;
        }
    }

    return false;
}

int main() {
    Cell** board = create_board();
    if (!load_board(board, "input.txt")) {
        printf("Error loading the board from the file.\n");
        return 1;
    }

    if (!is_valid_board(board)) {
        printf("The board is not valid.\n");
        return 1;
    }

    if (!solve_board(board)) {
        printf("No solution found.\n");
    } else {
        print_board(board);
    }

    destroy_board(board);
    return 0;
}