//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9
#define MAX_NUM 9

int **create_board(int size) {
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        board[i] = (int *)malloc(size * sizeof(int));
    }
    return board;
}

void print_board(int **board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void fill_board(int **board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
}

int is_valid_move(int **board, int size, int row, int col, int num) {
    for (int i = 0; i < size; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku(int **board, int size) {
    int row, col;
    for (row = 0; row < size; row++) {
        for (col = 0; col < size; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= size; num++) {
                    if (is_valid_move(board, size, row, col, num)) {
                        board[row][col] = num;
                        if (solve_sudoku(board, size)) {
                            return 1;
                        } else {
                            board[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int size = MAX_SIZE;
    int **board = create_board(size);
    fill_board(board, size);

    int count = 0;
    while (count < size * size) {
        int row = rand() % size;
        int col = rand() % size;
        if (board[row][col] == 0) {
            int num = rand() % MAX_NUM + 1;
            if (is_valid_move(board, size, row, col, num)) {
                board[row][col] = num;
                count++;
            }
        }
    }

    solve_sudoku(board, size);

    printf("Sudoku solution:\n");
    print_board(board, size);

    free(board[0]);
    free(board);

    return 0;
}