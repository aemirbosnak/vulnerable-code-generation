//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAZE_SIZE 20

typedef struct Cell {
    int x;
    int y;
    struct Cell* north;
    struct Cell* south;
    struct Cell* east;
    struct Cell* west;
} Cell;

void generateMaze(Cell* cell) {
    int r, x, y;
    srand(time(NULL));

    x = cell->x;
    y = cell->y;

    // Probability of creating a wall
    r = rand() % 2;

    if (r == 0) {
        cell->north = NULL;
    } else {
        cell->north = malloc(sizeof(Cell));
        cell->north->x = x;
        cell->north->y = y - 1;
        generateMaze(cell->north);
    }

    r = rand() % 2;

    if (r == 0) {
        cell->south = NULL;
    } else {
        cell->south = malloc(sizeof(Cell));
        cell->south->x = x;
        cell->south->y = y + 1;
        generateMaze(cell->south);
    }

    r = rand() % 2;

    if (r == 0) {
        cell->east = NULL;
    } else {
        cell->east = malloc(sizeof(Cell));
        cell->east->x = x + 1;
        cell->east->y = y;
        generateMaze(cell->east);
    }

    r = rand() % 2;

    if (r == 0) {
        cell->west = NULL;
    } else {
        cell->west = malloc(sizeof(Cell));
        cell->west->x = x - 1;
        cell->west->y = y;
        generateMaze(cell->west);
    }
}

int main() {
    Cell* start = malloc(sizeof(Cell));
    start->x = 0;
    start->y = 0;

    generateMaze(start);

    return 0;
}