//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

typedef struct cell {
    int alive;
    int next_alive;
} cell_t;

void game_of_life(cell_t** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cell_t* cell = grid[i * cols + j];
            if (cell->alive) {
                if (cell->next_alive == 0) {
                    // alive and has no living neighbors, die
                    cell->alive = 0;
                } else if (cell->next_alive == 2) {
                    // alive and has two or three living neighbors, survive
                    cell->alive = 1;
                } else {
                    // alive and has four or more living neighbors, die
                    cell->alive = 0;
                }
            } else {
                // dead and has three living neighbors, come to life
                cell->alive = 1;
                cell->next_alive = 2;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // create a 10x10 grid of cells
    cell_t** grid = calloc(10, sizeof(cell_t*) * 10);
    for (int i = 0; i < 10; i++) {
        grid[i] = calloc(10, sizeof(cell_t));
    }

    // initialize the grid with random alive and dead cells
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (rand() % 2) {
                grid[i][j].alive = 1;
            } else {
                grid[i][j].alive = 0;
            }
            grid[i][j].next_alive = 0;
        }
    }

    // run the game of life for 100 generations
    for (int i = 0; i < 100; i++) {
        game_of_life(grid, 10, 10);
    }

    // display the final state of the grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j].alive) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}