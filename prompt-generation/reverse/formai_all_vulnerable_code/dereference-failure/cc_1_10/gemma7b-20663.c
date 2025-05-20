//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

Cell **createGrid(int size) {
    Cell **grid = (Cell **)malloc(size * sizeof(Cell *));
    for (int i = 0; i < size; i++) {
        grid[i] = (Cell *)malloc(size * sizeof(Cell));
        for (int j = 0; j < size; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].state = 0;
        }
    }
    return grid;
}

void simulate(Cell **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    if (grid[i + x][j + y].state == 1) neighbors++;
                }
            }
            if (neighbors < 2) grid[i][j].state = 0;
            else if (neighbors == 2) grid[i][j].state = 1;
            else grid[i][j].state = 3;
        }
    }
}

int main() {
    Cell **grid = createGrid(MAX_SIZE);
    simulate(grid, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", grid[i][j].state);
        }
        printf("\n");
    }

    free(grid);
    return 0;
}