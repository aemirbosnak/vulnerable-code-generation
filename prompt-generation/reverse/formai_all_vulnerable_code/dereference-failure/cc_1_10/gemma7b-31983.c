//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void initGrid(Cell **grid) {
    *grid = (Cell *)malloc(GRID_SIZE * GRID_SIZE * sizeof(Cell));
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        (*grid)[i].x = i / GRID_SIZE;
        (*grid)[i].y = i % GRID_SIZE;
        (*grid)[i].state = rand() % 2;
    }
}

void simulate(Cell **grid) {
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        int neighbors = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                int x = (*grid)[i].x + dx;
                int y = (*grid)[i].y + dy;
                if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
                    neighbors++;
                }
            }
        }
        if ((*grid)[i].state == 0 && neighbors >= 3) {
            (*grid)[i].state = 1;
        } else if ((*grid)[i].state == 1 && neighbors < 2) {
            (*grid)[i].state = 0;
        }
    }
}

int main() {
    srand(time(NULL));
    Cell **grid = NULL;
    initGrid(grid);
    simulate(grid);
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        printf("%d ", (*grid)[i].state);
    }
    printf("\n");
    free(grid);
    return 0;
}