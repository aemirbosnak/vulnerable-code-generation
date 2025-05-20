//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 9
#define MAX_VAL 9

typedef struct {
    int row;
    int col;
    int val;
} Cell;

typedef struct {
    Cell *cells;
    int numCells;
} Board;

typedef struct {
    Board *board;
    bool valid;
} Sudoku;

bool validCell(Cell *cell, Board *board, int numCells) {
    int row = cell->row, col = cell->col;
    for (int i = 0; i < numCells; i++) {
        if (board->cells[i].val == cell->val && row == board->cells[i].row && col == board->cells[i].col) {
            return false;
        }
        for (int j = 0; j < 3; j++) {
            if (board->cells[i].val == cell->val && row == board->cells[i].row + 3 * j && col == board->cells[i].col + 3 * j) {
                return false;
            }
        }
        for (int j = 0; j < 3; j++) {
            if (board->cells[i].val == cell->val && row == board->cells[i].row + 3 * (j + 1) && col == board->cells[i].col + 3 * j) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(Board *board, int numCells) {
    int row, col;
    for (row = 0; row < numCells; row++) {
        for (col = 0; col < numCells; col++) {
            if (board->cells[row].val == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (validCell(&board->cells[row], board, numCells)) {
                        board->cells[row].val = val;
                        if (solveSudoku(board, numCells)) {
                            return true;
                        }
                        board->cells[row].val = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    Board board;
    board.numCells = MAX_SIZE;
    board.cells = (Cell *)malloc(MAX_SIZE * sizeof(Cell));
    for (int i = 0; i < MAX_SIZE; i++) {
        board.cells[i].row = i / MAX_VAL;
        board.cells[i].col = i % MAX_VAL;
        board.cells[i].val = 0;
    }
    if (!solveSudoku(&board, MAX_SIZE)) {
        printf("No solution found\n");
    } else {
        printf("Solution:\n");
        for (int i = 0; i < MAX_SIZE; i++) {
            if (board.cells[i].val == 0) {
                printf(" ");
            } else {
                printf("%d ", board.cells[i].val);
            }
        }
        printf("\n");
    }
    free(board.cells);
    return 0;
}