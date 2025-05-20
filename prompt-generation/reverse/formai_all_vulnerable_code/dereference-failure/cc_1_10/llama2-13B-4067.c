//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

typedef struct cell {
    int x;
    int y;
    int alive;
} cell_t;

typedef struct grid {
    cell_t** grid;
    int width;
    int height;
} grid_t;

void init_grid(grid_t* grid, int width, int height) {
    grid->width = width;
    grid->height = height;
    grid->grid = calloc(width, sizeof(cell_t*));

    for (int i = 0; i < width; i++) {
        grid->grid[i] = calloc(height, sizeof(cell_t));

        for (int j = 0; j < height; j++) {
            grid->grid[i][j].x = i * CELL_SIZE;
            grid->grid[i][j].y = j * CELL_SIZE;
            grid->grid[i][j].alive = (rand() % 2) == 0;
        }
    }
}

void draw_grid(grid_t* grid) {
    for (int i = 0; i < grid->width; i++) {
        for (int j = 0; j < grid->height; j++) {
            if (grid->grid[i][j].alive) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void update_grid(grid_t* grid) {
    for (int i = 0; i < grid->width; i++) {
        for (int j = 0; j < grid->height; j++) {
            int alive_neighbors = 0;

            // Check north neighbors
            if (i > 0 && grid->grid[i - 1][j].alive) {
                alive_neighbors++;
            }

            // Check south neighbors
            if (i < grid->width - 1 && grid->grid[i + 1][j].alive) {
                alive_neighbors++;
            }

            // Check west neighbors
            if (j > 0 && grid->grid[i][j - 1].alive) {
                alive_neighbors++;
            }

            // Check east neighbors
            if (j < grid->height - 1 && grid->grid[i][j + 1].alive) {
                alive_neighbors++;
            }

            // Update cell state based on number of alive neighbors
            if (alive_neighbors < 2) {
                grid->grid[i][j].alive = 0;
            } else if (alive_neighbors > 3) {
                grid->grid[i][j].alive = 1;
            } else {
                grid->grid[i][j].alive = grid->grid[i][j].alive;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    grid_t* grid = calloc(1, sizeof(grid_t));
    init_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);

    while (1) {
        draw_grid(grid);
        update_grid(grid);

        // Wait for a key press
        printf("Press a key to continue...");
        getchar();
    }

    free(grid);
    return 0;
}