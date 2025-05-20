//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1024
#define HEIGHT 1024
#define CELL_SIZE 20

typedef struct cell {
    int x;
    int y;
    int alive;
} cell_t;

cell_t** generate_grid(void) {
    cell_t** grid = calloc(HEIGHT, sizeof(cell_t*));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = calloc(WIDTH, sizeof(cell_t));
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = (cell_t) {
                .x = j * CELL_SIZE,
                .y = i * CELL_SIZE,
                .alive = (rand() % 2) == 0,
            };
        }
    }
    return grid;
}

void draw_grid(cell_t** grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void update_grid(cell_t** grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j].alive && grid[i][j].x + 1 < WIDTH && grid[i][j].alive == grid[i][j + 1].alive) {
                // Move cell to right
                grid[i][j].x += CELL_SIZE;
                grid[i][j + 1].x = grid[i][j].x;
            } else if (grid[i][j].alive && grid[i][j].x - 1 >= 0 && grid[i][j].alive == grid[i][j - 1].alive) {
                // Move cell to left
                grid[i][j].x -= CELL_SIZE;
                grid[i][j - 1].x = grid[i][j].x;
            } else if (grid[i][j].alive && grid[i][j].y + 1 < HEIGHT && grid[i][j].alive == grid[i + 1][j].alive) {
                // Move cell down
                grid[i][j].y += CELL_SIZE;
                grid[i + 1][j].y = grid[i][j].y;
            } else if (grid[i][j].alive && grid[i][j].y - 1 >= 0 && grid[i][j].alive == grid[i - 1][j].alive) {
                // Move cell up
                grid[i][j].y -= CELL_SIZE;
                grid[i - 1][j].y = grid[i][j].y;
            }
        }
    }
}

int main(void) {
    srand(time(NULL));
    cell_t** grid = generate_grid();
    draw_grid(grid);

    for (int i = 0; i < 1000; i++) {
        update_grid(grid);
        draw_grid(grid);
    }

    return 0;
}