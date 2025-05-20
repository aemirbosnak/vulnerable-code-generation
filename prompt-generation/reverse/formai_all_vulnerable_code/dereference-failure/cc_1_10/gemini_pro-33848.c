//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 9
#define BLOCK_SIZE 3

// A single Sudoku cell
typedef struct Cell {
    int value;
    bool fixed;
} Cell;

// The entire Sudoku board
typedef struct Board {
    Cell cells[BOARD_SIZE][BOARD_SIZE];
} Board;

// Read a Sudoku board from a file
Board* read_board(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    Board* board = malloc(sizeof(Board));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int value;
            fscanf(file, "%d", &value);
            board->cells[i][j].value = value;
            board->cells[i][j].fixed = (value != 0);
        }
    }

    fclose(file);
    return board;
}

// Print a Sudoku board
void print_board(Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board->cells[i][j].value);
        }
        printf("\n");
    }
}

// Check if a value is valid for a given cell
bool is_valid(Board* board, int row, int col, int value) {
    // Check row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->cells[row][i].value == value) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->cells[i][col].value == value) {
            return false;
        }
    }

    // Check block
    int block_row = row / BLOCK_SIZE;
    int block_col = col / BLOCK_SIZE;
    for (int i = block_row * BLOCK_SIZE; i < (block_row + 1) * BLOCK_SIZE; i++) {
        for (int j = block_col * BLOCK_SIZE; j < (block_col + 1) * BLOCK_SIZE; j++) {
            if (board->cells[i][j].value == value) {
                return false;
            }
        }
    }

    return true;
}

// Solve a Sudoku board using backtracking
bool solve_board(Board* board) {
    // Find the first empty cell
    int row = -1;
    int col = -1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cells[i][j].value == 0) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }

    // If no empty cells were found, the board is solved
    if (row == -1) {
        return true;
    }

    // Try all possible values for the empty cell
    for (int value = 1; value <= BOARD_SIZE; value++) {
        // Check if the value is valid
        if (is_valid(board, row, col, value)) {
            // Set the value and recursively solve the board
            board->cells[row][col].value = value;
            if (solve_board(board)) {
                return true;
            } else {
                // If the recursive call failed, reset the value to 0
                board->cells[row][col].value = 0;
            }
        }
    }

    // If no valid values were found, the board cannot be solved
    return false;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    Board* board = read_board(argv[1]);
    print_board(board);

    if (solve_board(board)) {
        printf("Solved board:\n");
        print_board(board);
    } else {
        printf("Board cannot be solved.\n");
    }

    free(board);
    return 0;
}