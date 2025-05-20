//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct Cell {
    int x;
    int y;
    int visited;
    struct Cell* north;
    struct Cell* south;
    struct Cell* east;
    struct Cell* west;
} Cell;

void generateMaze(Cell* cell) {
    srand(time(NULL));
    int r = rand() % 4;
    switch (r) {
        case 0:
            cell->north = malloc(sizeof(Cell));
            cell->north->x = cell->x;
            cell->north->y = cell->y - 1;
            generateMaze(cell->north);
            break;
        case 1:
            cell->south = malloc(sizeof(Cell));
            cell->south->x = cell->x;
            cell->south->y = cell->y + 1;
            generateMaze(cell->south);
            break;
        case 2:
            cell->east = malloc(sizeof(Cell));
            cell->east->x = cell->x + 1;
            cell->east->y = cell->y;
            generateMaze(cell->east);
            break;
        case 3:
            cell->west = malloc(sizeof(Cell));
            cell->west->x = cell->x - 1;
            cell->west->y = cell->y;
            generateMaze(cell->west);
            break;
    }
}

int main() {
    Cell* cell = malloc(sizeof(Cell));
    cell->x = 0;
    cell->y = 0;
    cell->visited = 0;
    generateMaze(cell);
    return 0;
}