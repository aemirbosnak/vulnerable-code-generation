//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 2)
#define WINDOW_HEIGHT (CELL_SIZE * 2)

typedef struct {
    int x;
    int y;
} cell_t;

cell_t *grid;
int num_cells;

void init_grid(void) {
    num_cells = WINDOW_WIDTH * WINDOW_HEIGHT;
    grid = calloc(num_cells, sizeof(cell_t));
}

void update_grid(void) {
    for (int i = 0; i < num_cells; i++) {
        cell_t *cur_cell = &grid[i];
        if (cur_cell->x % 2 == 0) {
            if (cur_cell->y % 2 == 0) {
                // alive and alive, keep alive
                cur_cell->x++;
            } else {
                // alive and dead, become dead
                cur_cell->x--;
            }
        } else {
            if (cur_cell->y % 2 == 0) {
                // dead and alive, become alive
                cur_cell->x++;
            } else {
                // dead and dead, keep dead
                cur_cell->x--;
            }
        }
    }
}

void draw_grid(void) {
    for (int i = 0; i < num_cells; i++) {
        cell_t *cur_cell = &grid[i];
        if (cur_cell->x % 2 == 0) {
            printf("O ");
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));
    init_grid();

    for (int i = 0; i < 100; i++) {
        update_grid();
        draw_grid();
        printf("Generation %d\n", i + 1);
        sleep(1);
    }

    return 0;
}