//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int num;
    int row;
    int col;
    bool used;
} Cell;

typedef struct {
    Cell* cells;
    int size;
} Sudoku;

void print_board(Sudoku* sudoku) {
    for (int i = 0; i < sudoku->size; i++) {
        for (int j = 0; j < sudoku->size; j++) {
            printf("%3d", sudoku->cells[i * sudoku->size + j].num);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_valid(Sudoku* sudoku, int num, int row, int col) {
    for (int i = 0; i < sudoku->size; i++) {
        if (sudoku->cells[i * sudoku->size + col].used ||
            sudoku->cells[row * sudoku->size + i].used ||
            sudoku->cells[i * sudoku->size + sudoku->size / 2].used == num) {
            return false;
        }
    }
    for (int i = 0; i < sudoku->size; i++) {
        if (sudoku->cells[row * sudoku->size + i].used == num) {
            return false;
        }
    }
    if (sudoku->cells[sudoku->size / 2 * sudoku->size + col].used == num) {
        return false;
    }
    return true;
}

bool solve_sudoku(Sudoku* sudoku) {
    int row = 0, col = 0;
    for (int i = 0; i < sudoku->size; i++) {
        for (int j = 0; j < sudoku->size; j++) {
            if (sudoku->cells[i * sudoku->size + j].used == false) {
                row = i;
                col = j;
                break;
            }
        }
        if (row!= 0) {
            break;
        }
    }
    if (row == 0 && col == 0) {
        return true;
    }
    int num = 1;
    while (num <= 9 &&!is_valid(sudoku, num, row, col)) {
        num++;
    }
    if (num > 9) {
        return false;
    }
    sudoku->cells[row * sudoku->size + col].num = num;
    sudoku->cells[row * sudoku->size + col].used = true;
    solve_sudoku(sudoku);
    return true;
}

int main() {
    int size = 9;
    Cell* cells = (Cell*)malloc(size * size * sizeof(Cell));
    Sudoku sudoku = {.cells = cells,.size = size};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i % 3 == 0 && j % 3 == 0) {
                cells[i * size + j].used = false;
                cells[i * size + j].num = 0;
            } else {
                cells[i * size + j].used = true;
                cells[i * size + j].num = 0;
            }
        }
    }
    solve_sudoku(&sudoku);
    print_board(&sudoku);
    free(cells);
    return 0;
}