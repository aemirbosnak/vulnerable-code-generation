//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int row;
    int col;
    int val;
} Cell;

int is_valid(int **board, int row, int col, int val) {
    for(int i=0; i<9; i++) {
        if(board[row][i] == val || board[i][col] == val) {
            return 0;
        }
    }
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for(int i=box_row; i<box_row+3; i++) {
        for(int j=box_col; j<box_col+3; j++) {
            if(board[i][j] == val) {
                return 0;
            }
        }
    }
    return 1;
}

void print_board(int **board) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int **board = (int **)malloc(9 * sizeof(int *));
    for(int i=0; i<9; i++) {
        board[i] = (int *)malloc(9 * sizeof(int));
        for(int j=0; j<9; j++) {
            board[i][j] = rand() % 9 + 1;
        }
    }
    int empty_row, empty_col;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(board[i][j] == 0) {
                empty_row = i;
                empty_col = j;
                break;
            }
        }
    }
    int count = 0;
    while(count < 81) {
        int rand_row = rand() % 9;
        int rand_col = rand() % 9;
        while(!is_valid(board, rand_row, rand_col, board[empty_row][empty_col] + 1)) {
            rand_row = rand() % 9;
            rand_col = rand() % 9;
        }
        board[rand_row][rand_col] = board[empty_row][empty_col] + 1;
        count++;
    }
    print_board(board);
    return 0;
}