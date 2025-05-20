//FormAI DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

//Helper function to print out the Sudoku board
void print_board(int **board) {
    printf("\n");
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Helper function to check if a number is valid in a given cell
int is_valid(int **board, int row, int col, int num) {
    //check row
    for(int i = 0; i < 9; i++) {
        if(board[row][i] == num) {
            return 0;
        }
    }
    //check column
    for(int i = 0; i < 9; i++) {
        if(board[i][col] == num) {
            return 0;
        }
    }
    //check box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for(int i = box_row; i < box_row + 3; i++) {
        for(int j = box_col; j < box_col + 3; j++) {
            if(board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

//Main recursive function to solve the Sudoku board
int solve_board(int **board, int row, int col) {
    //if we have filled out the entire board, return 1
    if(row == 9) {
        return 1;
    }
    //if we have filled out a row, move on to the next row
    if(col == 9) {
        return solve_board(board, row+1, 0);
    }
    //if the cell is already filled out, move on to the next cell
    if(board[row][col] != 0) {
        return solve_board(board, row, col+1);
    }
    //try each number from 1-9 in the cell, if a number is valid, fill out the cell and continue recursively
    for(int i = 1; i <= 9; i++) {
        if(is_valid(board, row, col, i)) {
            board[row][col] = i;
            if(solve_board(board, row, col+1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    //if we haven't found a valid number for this cell, backtrack
    return 0;
}

//Main function to initialize and solve the Sudoku board
int main() {
    int **board = malloc(sizeof(int*) * 9);
    for(int i = 0; i < 9; i++) {
        board[i] = malloc(sizeof(int) * 9);
    }
    printf("Enter the Sudoku board (row by row, use 0 for blank cells):\n");
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    printf("\nInitial Sudoku board:\n");
    print_board(board);
    solve_board(board, 0, 0);
    printf("Solved Sudoku board:\n");
    print_board(board);
    return 0;
}