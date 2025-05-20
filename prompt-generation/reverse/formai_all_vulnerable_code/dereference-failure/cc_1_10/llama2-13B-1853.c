//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GENERATIONS 100

typedef struct cell {
    int alive;
    int x;
    int y;
} cell_t;

cell_t* create_grid(int size) {
    cell_t* grid = malloc(size * size * sizeof(cell_t));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i * size + j].alive = (i % 2 == 0) && (j % 2 == 0);
            grid[i * size + j].x = i * CELL_WIDTH / size;
            grid[i * size + j].y = j * CELL_HEIGHT / size;
        }
    }
    return grid;
}

void print_grid(cell_t* grid) {
    for (int i = 0; i < CELL_HEIGHT; i++) {
        for (int j = 0; j < CELL_WIDTH; j++) {
            if (grid[i * CELL_WIDTH + j].alive) {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

void update_grid(cell_t* grid) {
    for (int i = 0; i < CELL_HEIGHT; i++) {
        for (int j = 0; j < CELL_WIDTH; j++) {
            int alive_neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1 * CELL_WIDTH + j].alive) {
                alive_neighbors++;
            }
            if (i + 1 < CELL_HEIGHT && grid[i + 1 * CELL_WIDTH + j].alive) {
                alive_neighbors++;
            }
            if (j - 1 >= 0 && grid[i * CELL_WIDTH + j - 1].alive) {
                alive_neighbors++;
            }
            if (j + 1 < CELL_WIDTH && grid[i * CELL_WIDTH + j + 1].alive) {
                alive_neighbors++;
            }
            if (alive_neighbors == 2 && grid[i * CELL_WIDTH + j].alive) {
                grid[i * CELL_WIDTH + j].alive = 1;
            } else if (alive_neighbors < 2 && grid[i * CELL_WIDTH + j].alive) {
                grid[i * CELL_WIDTH + j].alive = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    cell_t* grid = create_grid(CELL_WIDTH * CELL_HEIGHT);
    for (int i = 0; i < GENERATIONS; i++) {
        update_grid(grid);
        print_grid(grid);
        sleep(1);
    }
    free(grid);
    return 0;
}