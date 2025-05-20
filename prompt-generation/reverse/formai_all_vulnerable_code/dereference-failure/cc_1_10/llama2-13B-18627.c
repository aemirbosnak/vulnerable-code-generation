//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 1024
#define HEIGHT 1024

typedef struct {
    int x;
    int y;
    int alive;
} cell_t;

cell_t** grid;

void init_grid(void) {
    grid = calloc(HEIGHT, sizeof(cell_t*));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = calloc(WIDTH, sizeof(cell_t));
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j].x = j;
            grid[i][j].y = i;
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
        }
    }
}

void update_grid(void) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) neighbors++;
            if (i + 1 < HEIGHT && grid[i + 1][j].alive) neighbors++;
            if (j - 1 >= 0 && grid[i][j - 1].alive) neighbors++;
            if (j + 1 < WIDTH && grid[i][j + 1].alive) neighbors++;
            if (neighbors == 2 || neighbors == 3) {
                grid[i][j].alive = !grid[i][j].alive;
            }
        }
    }
}

void draw_grid(void) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));
    init_grid();
    for (int i = 0; i < 1000; i++) {
        update_grid();
        draw_grid();
    }
    return 0;
}