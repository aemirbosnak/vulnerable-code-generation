//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rows;
    int cols;
    int **board;
} grid_t;

void print_board(grid_t *grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            printf("%d ", grid->board[i][j]);
        }
        printf("\n");
    }
}

void create_grid(grid_t *grid, int rows, int cols) {
    grid->rows = rows;
    grid->cols = cols;
    grid->board = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid->board[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid->board[i][j] = 1;
        }
    }
}

void update_grid(grid_t *grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            int live_neighbors = 0;
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (k >= 0 && k < grid->rows && l >= 0 && l < grid->cols) {
                        live_neighbors += grid->board[k][l];
                    }
                }
            }
            if (grid->board[i][j] == 1 && live_neighbors < 2 || live_neighbors > 3) {
                grid->board[i][j] = 0;
            } else if (grid->board[i][j] == 0 && live_neighbors == 3) {
                grid->board[i][j] = 1;
            }
        }
    }
}

void random_grid(grid_t *grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid->board[i][j] = rand() % 2 == 0? 1 : 0;
        }
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int rows = 100, cols = 100;
    grid_t grid;
    create_grid(&grid, rows, cols);
    print_board(&grid);
    for (int i = 0; i < 20; i++) {
        update_grid(&grid);
        print_board(&grid);
    }
    return 0;
}