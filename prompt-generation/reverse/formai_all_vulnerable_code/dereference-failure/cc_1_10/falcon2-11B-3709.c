//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 9
#define INF 1000000

typedef struct {
    int row;
    int col;
    int value;
} SudokuCell;

typedef struct {
    int size;
    SudokuCell *cells;
} Sudoku;

Sudoku* createSudoku(int size) {
    Sudoku *sudoku = (Sudoku*)malloc(sizeof(Sudoku));
    sudoku->size = size;
    sudoku->cells = (SudokuCell*)malloc(size * sizeof(SudokuCell));
    return sudoku;
}

void setCell(Sudoku *sudoku, int row, int col, int value) {
    sudoku->cells[row * sudoku->size + col].value = value;
}

int isValid(Sudoku *sudoku, int row, int col, int value) {
    for (int i = 0; i < sudoku->size; i++) {
        if (sudoku->cells[row * sudoku->size + i].value == value ||
            sudoku->cells[i * sudoku->size + col].value == value ||
            sudoku->cells[sudoku->size * row + i].value == value) {
            return 0;
        }
    }
    int block = row / 3 * 3 + col / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku->cells[block * 3 + i].value == value ||
                sudoku->cells[(block * 3 + i) * 3 + j].value == value ||
                sudoku->cells[(block * 3 + j) * 3 + i].value == value) {
                return 0;
            }
        }
    }
    return 1;
}

void solveSudoku(Sudoku *sudoku) {
    int i, j;
    for (i = 0; i < sudoku->size; i++) {
        for (j = 0; j < sudoku->size; j++) {
            if (sudoku->cells[i * sudoku->size + j].value == 0) {
                int value = 1;
                while (!isValid(sudoku, i, j, value)) {
                    value++;
                }
                setCell(sudoku, i, j, value);
                solveSudoku(sudoku);
                if (value > 1) {
                    value--;
                    setCell(sudoku, i, j, value);
                    solveSudoku(sudoku);
                }
            }
        }
    }
}

int main() {
    int size = 9;
    int *puzzle = (int*)malloc(size * size * sizeof(int));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            puzzle[i * size + j] = INF;
        }
    }
    puzzle[0] = 8;
    puzzle[1] = 6;
    puzzle[2] = 5;
    puzzle[3] = 3;
    puzzle[4] = 7;
    puzzle[5] = 2;
    puzzle[6] = 9;
    puzzle[7] = 1;
    puzzle[8] = 4;

    Sudoku *sudoku = createSudoku(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            setCell(sudoku, i, j, puzzle[i * size + j]);
        }
    }
    solveSudoku(sudoku);

    printf("Sudoku Solved!\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", sudoku->cells[i * size + j].value);
        }
        printf("\n");
    }

    free(sudoku->cells);
    free(sudoku);

    return 0;
}