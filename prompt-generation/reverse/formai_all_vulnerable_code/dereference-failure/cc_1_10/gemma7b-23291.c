//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9

typedef struct Sudoku {
    int **board;
    int size;
    int **solution;
} Sudoku;

Sudoku *createSudoku(int size) {
    Sudoku *sudoku = malloc(sizeof(Sudoku));
    sudoku->board = malloc(sizeof(int *) * size);
    sudoku->solution = malloc(sizeof(int *) * size);
    sudoku->size = size;

    for (int i = 0; i < size; i++) {
        sudoku->board[i] = malloc(sizeof(int) * size);
        sudoku->solution[i] = malloc(sizeof(int) * size);
    }

    return sudoku;
}

void generateSudoku(Sudoku *sudoku) {
    srand(time(NULL));

    for (int i = 0; i < sudoku->size; i++) {
        for (int j = 0; j < sudoku->size; j++) {
            sudoku->board[i][j] = rand() % MAX_SIZE + 1;
        }
    }
}

void solveSudoku(Sudoku *sudoku) {
    int **visited = malloc(sizeof(int *) * sudoku->size);
    for (int i = 0; i < sudoku->size; i++) {
        visited[i] = malloc(sizeof(int) * sudoku->size);
    }

    for (int i = 0; i < sudoku->size; i++) {
        for (int j = 0; j < sudoku->size; j++) {
            if (sudoku->board[i][j] == 0) {
                for (int k = 0; k < sudoku->size; k++) {
                    if (sudoku->board[k][j] != 0 && visited[k][j] == 0) {
                        visited[k][j] = 1;
                        sudoku->board[i][j] = sudoku->board[k][j];
                        solveSudoku(sudoku);
                        sudoku->board[i][j] = 0;
                    }
                }
            }
        }
    }

    free(visited);
}

int main() {
    Sudoku *sudoku = createSudoku(MAX_SIZE);
    generateSudoku(sudoku);
    solveSudoku(sudoku);

    for (int i = 0; i < sudoku->size; i++) {
        for (int j = 0; j < sudoku->size; j++) {
            printf("%d ", sudoku->solution[i][j]);
        }
        printf("\n");
    }

    free(sudoku);

    return 0;
}