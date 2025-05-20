//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: imaginative
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 10
#define MAX_HEIGHT 10

#define CELL_SIZE 20

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

Cell** createGrid(int w, int h) {
    Cell** grid = (Cell**)malloc(w * h * sizeof(Cell));
    for (int i = 0; i < w * h; i++) {
        grid[i] = (Cell*)malloc(sizeof(Cell));
        grid[i]->x = i % w;
        grid[i]->y = i / w;
        grid[i]->state = 0;
    }
    return grid;
}

void simulatePercolation(Cell** grid) {
    int r = rand() % MAX_HEIGHT;
    int c = rand() % MAX_WIDTH;
    grid[r * MAX_WIDTH + c]->state = 1;

    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (grid[i * MAX_WIDTH + j]->state == 1) {
                if (i > 0 && grid[i * MAX_WIDTH + j]->state != grid[(i - 1) * MAX_WIDTH + j]->state) {
                    grid[i * MAX_WIDTH + j]->state = 0;
                }
                if (j > 0 && grid[i * MAX_WIDTH + j]->state != grid[i * MAX_WIDTH + j - 1]->state) {
                    grid[i * MAX_WIDTH + j]->state = 0;
                }
            }
        }
    }
}

int main() {
    Cell** grid = createGrid(MAX_WIDTH, MAX_HEIGHT);
    simulatePercolation(grid);

    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (grid[i * MAX_WIDTH + j]->state == 1) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }

    return 0;
}