//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    char animal[10];
    int alive;
} cell_t;

typedef struct grid {
    cell_t cells[GRID_SIZE][CELL_SIZE];
} grid_t;

void create_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            grid->cells[i][j].animal[0] = 'O'; // default animal is "O" (ox)
            grid->cells[i][j].alive = 1; // all cells are initially alive
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            // check if the cell is alive and has two or three alive neighbors
            if (grid->cells[i][j].alive && (i == 0 || grid->cells[i][j].alive == grid->cells[i][j-1].alive && grid->cells[i][j].alive == grid->cells[i][j+1].alive)) {
                // if the cell is alive and has two or three alive neighbors, leave it alive
                grid->cells[i][j].alive = 1;
            } else {
                // if the cell is alive and has fewer than two alive neighbors, die
                grid->cells[i][j].alive = 0;
            }
        }
    }
}

void draw_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->cells[i][j].alive) {
                printf("%c", grid->cells[i][j].animal);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    grid_t *grid = malloc(sizeof(grid_t));
    create_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
        sleep(1); // simulate time passing
    }

    free(grid);
    return 0;
}