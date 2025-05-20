//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_VAL 9

int **create_board(void);
int is_valid_move(int **board, int row, int col, int val);
void print_board(int **board);
int **solve_sudoku(int **board);

int main(void) {
    int **board;
    int i, j;

    board = create_board();
    srand(time(NULL));

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            board[i][j] = rand() % MAX_VAL + 1;
        }
    }

    print_board(board);

    board = solve_sudoku(board);

    print_board(board);

    return 0;
}

int **create_board(void) {
    int i, j;
    int **board;

    board = (int **)malloc(MAX_ROWS * sizeof(int *));

    for (i = 0; i < MAX_ROWS; i++) {
        board[i] = (int *)malloc(MAX_COLS * sizeof(int));

        for (j = 0; j < MAX_COLS; j++) {
            board[i][j] = 0;
        }
    }

    return board;
}

int is_valid_move(int **board, int row, int col, int val) {
    int i, j;

    for (i = 0; i < MAX_ROWS; i++) {
        if (board[i][col] == val) {
            return 0;
        }
    }

    for (i = 0; i < MAX_COLS; i++) {
        if (board[row][i] == val) {
            return 0;
        }
    }

    int box_row = row - row % 3;
    int box_col = col - col % 3;

    for (i = box_row; i < box_row + 3; i++) {
        for (j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == val) {
                return 0;
            }
        }
    }

    return 1;
}

void print_board(int **board) {
    int i, j;

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int **solve_sudoku(int **board) {
    int i, j;
    int row, col;
    int moves = 0;

    while (moves < MAX_ROWS * MAX_COLS) {
        row = rand() % MAX_ROWS;
        col = rand() % MAX_COLS;

        if (board[row][col] == 0) {
            int val = 1;

            while (!is_valid_move(board, row, col, val)) {
                val++;
            }

            board[row][col] = val;
            moves++;
        }
    }

    return board;
}