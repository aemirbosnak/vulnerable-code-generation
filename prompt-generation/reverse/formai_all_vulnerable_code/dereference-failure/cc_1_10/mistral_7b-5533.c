//MISTRAL-7B DATASET v1.0 Category: Sudoku solver ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define WIDTH 9
#define HEIGHT 9

typedef struct cell {
    int value;
    bool is_visited;
} cell;

void print_board(cell **board) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%d%c", board[i][j].value, j == WIDTH - 1 ? '\n' : ' ');
        }
    }
}

bool is_valid(int num, int row, int col, cell **board) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        if (board[i][col].value == num) {
            return false;
        }
    }

    for (i = 0; i < WIDTH; i++) {
        if (board[row][i].value == num) {
            return false;
        }
    }

    for (i = row - 3; i < row + 3; i++) {
        for (j = col - 3; j < col + 3; j++) {
            if (i >= 0 && j >= 0 && i < HEIGHT && j < WIDTH && board[i][j].value == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(cell **board, int row, int col) {
    if (row >= HEIGHT) {
        return true;
    }

    if (col >= WIDTH) {
        return solve_sudoku(board, row + 1, 0);
    }

    if (board[row][col].value != 0) {
        return solve_sudoku(board, row, col + 1);
    }

    for (int num = 1; num <= WIDTH * HEIGHT; num++) {
        if (is_valid(num, row, col, board)) {
            board[row][col].value = num;
            if (solve_sudoku(board, row, col + 1)) {
                return true;
            }
            board[row][col].value = 0;
        }
    }

    return false;
}

int main() {
    srand(time(NULL));

    cell **board = (cell **)malloc(HEIGHT * sizeof(cell *));
    for (int i = 0; i < HEIGHT; i++) {
        board[i] = (cell *)calloc(WIDTH, sizeof(cell));
    }

    int num;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 10 > 5) {
                num = rand() % (WIDTH * HEIGHT + 1);
                board[i][j].value = num % WIDTH + 1;
            } else {
                board[i][j].value = 0;
            }
            board[i][j].is_visited = false;
        }
    }

    if (solve_sudoku(board, 0, 0)) {
        print_board(board);
    } else {
        printf("Unable to solve Sudoku.\n");
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}