//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BOARD_SIZE 9

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int solved;
} Sudoku;

Sudoku* create_sudoku() {
    Sudoku* sudoku = malloc(sizeof(Sudoku));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            sudoku->board[i][j] = 0;
        }
    }
    sudoku->solved = 0;
    return sudoku;
}

void destroy_sudoku(Sudoku* sudoku) {
    free(sudoku);
}

int is_valid_move(Sudoku* sudoku, int row, int col, int value) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (sudoku->board[row][i] == value) {
            return 0;
        }
        if (sudoku->board[i][col] == value) {
            return 0;
        }
    }

    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (sudoku->board[i][j] == value) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku(Sudoku* sudoku, int row, int col) {
    if (row == BOARD_SIZE) {
        sudoku->solved = 1;
        return 1;
    }

    if (sudoku->board[row][col] != 0) {
        return solve_sudoku(sudoku, row + (col + 1) / BOARD_SIZE, (col + 1) % BOARD_SIZE);
    }

    for (int value = 1; value <= BOARD_SIZE; value++) {
        if (is_valid_move(sudoku, row, col, value)) {
            sudoku->board[row][col] = value;
            if (solve_sudoku(sudoku, row + (col + 1) / BOARD_SIZE, (col + 1) % BOARD_SIZE)) {
                return 1;
            }
            sudoku->board[row][col] = 0;
        }
    }

    return 0;
}

void print_sudoku(Sudoku* sudoku) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", sudoku->board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Sudoku* sudoku = create_sudoku();

    // Set some initial values
    sudoku->board[0][0] = 5;
    sudoku->board[0][1] = 3;
    sudoku->board[0][4] = 7;
    sudoku->board[1][0] = 6;
    sudoku->board[1][3] = 1;
    sudoku->board[1][4] = 9;
    sudoku->board[1][5] = 5;
    sudoku->board[2][1] = 9;
    sudoku->board[2][2] = 8;
    sudoku->board[2][7] = 6;
    sudoku->board[3][0] = 8;
    sudoku->board[3][4] = 6;
    sudoku->board[3][8] = 3;
    sudoku->board[4][0] = 4;
    sudoku->board[4][3] = 8;
    sudoku->board[4][5] = 3;
    sudoku->board[4][8] = 1;
    sudoku->board[5][0] = 7;
    sudoku->board[5][4] = 2;
    sudoku->board[5][8] = 6;
    sudoku->board[6][1] = 6;
    sudoku->board[6][6] = 2;
    sudoku->board[6][7] = 8;
    sudoku->board[7][3] = 4;
    sudoku->board[7][4] = 1;
    sudoku->board[7][5] = 9;
    sudoku->board[7][8] = 5;
    sudoku->board[8][4] = 8;
    sudoku->board[8][7] = 7;
    sudoku->board[8][8] = 9;

    printf("Original Sudoku:\n");
    print_sudoku(sudoku);

    if (solve_sudoku(sudoku, 0, 0)) {
        printf("\nSolved Sudoku:\n");
        print_sudoku(sudoku);
    } else {
        printf("\nNo solution found.\n");
    }

    destroy_sudoku(sudoku);
    return 0;
}