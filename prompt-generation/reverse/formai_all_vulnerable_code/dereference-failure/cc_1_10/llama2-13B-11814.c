//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

typedef struct {
    int x;
    int y;
    int alive;
} cell_t;

void init_cells(cell_t **grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            grid[i][j].x = i * CELL_SIZE;
            grid[i][j].y = j * CELL_SIZE;
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
        }
    }
}

void draw_cells(cell_t **grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

void update_cells(cell_t **grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            int alive_neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                alive_neighbors++;
            }
            if (i + 1 < width && grid[i + 1][j].alive) {
                alive_neighbors++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                alive_neighbors++;
            }
            if (j + 1 < height && grid[i][j + 1].alive) {
                alive_neighbors++;
            }
            if (alive_neighbors < 2 || alive_neighbors > 3) {
                grid[i][j].alive = 0;
            } else {
                grid[i][j].alive = 1;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    cell_t **grid = calloc(WINDOW_WIDTH, sizeof(cell_t *));
    for (int i = 0; i < WINDOW_WIDTH; i++) {
        grid[i] = calloc(WINDOW_HEIGHT, sizeof(cell_t));
    }
    init_cells(grid, WINDOW_WIDTH, WINDOW_HEIGHT);

    while (1) {
        update_cells(grid, WINDOW_WIDTH, WINDOW_HEIGHT);
        draw_cells(grid, WINDOW_WIDTH, WINDOW_HEIGHT);
        printf("Press enter to continue...");
        getchar();
    }

    return 0;
}