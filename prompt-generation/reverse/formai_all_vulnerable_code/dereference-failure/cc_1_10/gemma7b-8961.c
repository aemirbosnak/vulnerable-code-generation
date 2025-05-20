//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Cell {
    int x, y;
    char state;
} Cell;

void initializeGrid(Cell **grid, int size) {
    grid = (Cell **)malloc(size * sizeof(Cell *));
    for (int i = 0; i < size; i++) {
        grid[i] = (Cell *)malloc(size * sizeof(Cell));
        for (int j = 0; j < size; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].state = 'o';
        }
    }
}

void printGrid(Cell **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", grid[i][j].state);
        }
        printf("\n");
    }
}

void calculateNextState(Cell **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = 0;
            if (i > 0) neighbors++;
            if (i < size - 1) neighbors++;
            if (j > 0) neighbors++;
            if (j < size - 1) neighbors++;

            switch (grid[i][j].state) {
                case 'o':
                    if (neighbors == 3) grid[i][j].state = 'b';
                    break;
                case 'b':
                    if (neighbors < 2 || neighbors > 3) grid[i][j].state = 'o';
                    break;
            }
        }
    }
}

int main() {
    int size = 10;
    Cell **grid;

    initializeGrid(&grid, size);

    // Print the initial grid
    printGrid(grid, size);

    // Calculate the next state of the grid
    calculateNextState(grid, size);

    // Print the next state of the grid
    printGrid(grid, size);

    return 0;
}