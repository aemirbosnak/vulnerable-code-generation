//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct {
    int x;
    int y;
    int alive;
} cell_t;

cell_t *grid;
int generation = 0;

void init_grid() {
    grid = (cell_t *)calloc(WIDTH * HEIGHT, sizeof(cell_t));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        grid[i].x = rand() % WIDTH;
        grid[i].y = rand() % HEIGHT;
        grid[i].alive = (rand() % 2) == 0;
    }
}

void update_grid() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int x = grid[i].x;
        int y = grid[i].y;
        int alive = grid[i].alive;

        // Apply rules
        if (alive) {
            if (x < WIDTH / 2 && y < HEIGHT / 2) {
                // Alive cell in the top-left corner
                grid[i].alive = (rand() % 2) == 0;
            } else if (x < WIDTH / 2 && y >= HEIGHT / 2) {
                // Alive cell in the top-right corner
                grid[i].alive = (rand() % 2) == 1;
            } else if (x >= WIDTH / 2 && y < HEIGHT / 2) {
                // Alive cell in the bottom-left corner
                grid[i].alive = (rand() % 2) == 0;
            } else {
                // Alive cell in the bottom-right corner
                grid[i].alive = (rand() % 2) == 1;
            }
        }
    }
}

void draw_grid() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (grid[i].alive) {
            printf("O ");
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    init_grid();

    for (int i = 0; i < 100; i++) {
        update_grid();
        draw_grid();
    }

    return 0;
}