//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100
#define GENERATIONS 100

typedef struct cell {
    int age;
    int alive;
} cell_t;

typedef struct grid {
    cell_t** cells;
    int width;
    int height;
} grid_t;

void init_grid(grid_t* grid) {
    int i, j;

    grid->width = GRID_SIZE;
    grid->height = GRID_SIZE;

    grid->cells = (cell_t**) malloc(grid->width * grid->height * sizeof(cell_t*));

    for (i = 0; i < grid->width; i++) {
        for (j = 0; j < grid->height; j++) {
            grid->cells[i * grid->height + j] = (cell_t*) malloc(sizeof(cell_t));
            grid->cells[i * grid->height + j]->age = 0;
            grid->cells[i * grid->height + j]->alive = (rand() % 2) ? 1 : 0;
        }
    }
}

void update_grid(grid_t* grid) {
    int i, j;

    for (i = 0; i < grid->width; i++) {
        for (j = 0; j < grid->height; j++) {
            cell_t* cell = grid->cells[i * grid->height + j];

            // Apply rules
            if (cell->alive && (cell->age == 0 || cell->age == 2)) {
                cell->alive = (rand() % 2) ? 1 : 0;
            } else if (!cell->alive && (cell->age == 1 || cell->age == 3)) {
                cell->alive = (rand() % 2) ? 1 : 0;
            }

            // Update age
            cell->age++;

            // Check for border collisions
            if (i == 0 || i == grid->width - 1 || j == 0 || j == grid->height - 1) {
                cell->alive = 0;
            }
        }
    }
}

void draw_grid(grid_t* grid) {
    int i, j;

    for (i = 0; i < grid->width; i++) {
        for (j = 0; j < grid->height; j++) {
            cell_t* cell = grid->cells[i * grid->height + j];

            if (cell->alive) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    grid_t* grid = (grid_t*) malloc(sizeof(grid_t));
    init_grid(grid);

    for (int generation = 0; generation < GENERATIONS; generation++) {
        update_grid(grid);
        draw_grid(grid);
        printf("Generation %d\n", generation + 1);
    }

    return 0;
}