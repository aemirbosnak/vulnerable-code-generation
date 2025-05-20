//Falcon-180B DATASET v1.0 Category: Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_MINES 50

typedef struct {
    int row;
    int col;
} Cell;

typedef struct {
    Cell **grid;
    int rows;
    int cols;
    int num_mines;
} Minesweeper;

void init_minesweeper(Minesweeper *game) {
    game->grid = (Cell **)malloc(MAX_ROWS * sizeof(Cell *));
    for (int i = 0; i < MAX_ROWS; i++) {
        game->grid[i] = (Cell *)malloc(MAX_COLS * sizeof(Cell));
    }
    game->rows = MAX_ROWS;
    game->cols = MAX_COLS;
    game->num_mines = rand() % MAX_MINES + 1;
    srand(time(NULL));
    for (int i = 0; i < game->num_mines; i++) {
        int row = rand() % game->rows;
        int col = rand() % game->cols;
        while (game->grid[row][col].row!= -1) {
            row = rand() % game->rows;
            col = rand() % game->cols;
        }
        game->grid[row][col].row = row;
        game->grid[row][col].col = col;
    }
}

void print_minesweeper(Minesweeper *game) {
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            if (game->grid[i][j].row == -1) {
                printf(" ");
            } else {
                printf("%d ", game->grid[i][j].row);
            }
        }
        printf("\n");
    }
}

int main() {
    Minesweeper game;
    init_minesweeper(&game);
    print_minesweeper(&game);
    return 0;
}