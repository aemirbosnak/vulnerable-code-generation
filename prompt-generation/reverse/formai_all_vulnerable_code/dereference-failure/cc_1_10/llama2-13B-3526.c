//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

typedef struct {
    int x;
    int y;
} cell_t;

cell_t* generate_random_grid(int size) {
    cell_t* grid = calloc(size, sizeof(cell_t));
    for (int i = 0; i < size; i++) {
        grid[i].x = rand() % WINDOW_WIDTH;
        grid[i].y = rand() % WINDOW_HEIGHT;
    }
    return grid;
}

void draw_grid(cell_t* grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %d", grid[i * size + j].x);
        }
        printf("\n");
    }
}

void update_grid(cell_t* grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i * size + j].x == grid[i * size + j].y) {
                grid[i * size + j].x = 0;
            } else {
                grid[i * size + j].x = grid[i * size + j].x + grid[i * size + j].y;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    cell_t* grid = generate_random_grid(100);
    draw_grid(grid, 100);
    update_grid(grid, 100);
    draw_grid(grid, 100);
    return 0;
}