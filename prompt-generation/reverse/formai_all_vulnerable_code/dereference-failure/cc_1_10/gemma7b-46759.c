//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>

#define MAX_LENGHT 10
#define MAX_WIDTH 10

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
    int r, w;
    srand(time(NULL));

    // Generate random number for north, south, east, west walls
    r = rand() % 4;
    w = rand() % 4;

    // North wall
    if (r == 0 && cell->north == NULL) {
        cell->north = malloc(sizeof(Cell));
        cell->north->x = cell->x;
        cell->north->y = cell->y - 1;
        cell->north->visited = 0;
        generateMaze(cell->north);
    }

    // South wall
    if (r == 1 && cell->south == NULL) {
        cell->south = malloc(sizeof(Cell));
        cell->south->x = cell->x;
        cell->south->y = cell->y + 1;
        cell->south->visited = 0;
        generateMaze(cell->south);
    }

    // East wall
    if (w == 0 && cell->east == NULL) {
        cell->east = malloc(sizeof(Cell));
        cell->east->x = cell->x + 1;
        cell->east->y = cell->y;
        cell->east->visited = 0;
        generateMaze(cell->east);
    }

    // West wall
    if (w == 1 && cell->west == NULL) {
        cell->west = malloc(sizeof(Cell));
        cell->west->x = cell->x - 1;
        cell->west->y = cell->y;
        cell->west->visited = 0;
        generateMaze(cell->west);
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