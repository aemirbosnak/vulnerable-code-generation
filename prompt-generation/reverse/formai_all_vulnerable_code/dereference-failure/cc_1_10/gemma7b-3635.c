//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

typedef struct Cell {
    int x;
    int y;
    struct Cell* north;
    struct Cell* south;
    struct Cell* east;
    struct Cell* west;
} Cell;

Cell* createCell(int x, int y) {
    Cell* cell = (Cell*)malloc(sizeof(Cell));
    cell->x = x;
    cell->y = y;
    cell->north = NULL;
    cell->south = NULL;
    cell->east = NULL;
    cell->west = NULL;
    return cell;
}

void generateMaze(Cell* cell) {
    srand(time(NULL));
    int chance = rand() % 2;

    if (chance == 0) {
        cell->north = createCell(cell->x, cell->y - 1);
    }
    if (chance == 1) {
        cell->south = createCell(cell->x, cell->y + 1);
    }
    if (chance == 0) {
        cell->east = createCell(cell->x + 1, cell->y);
    }
    if (chance == 1) {
        cell->west = createCell(cell->x - 1, cell->y);
    }
}

void printMaze(Cell* cell) {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            if (cell->x == x && cell->y == y) {
                printf("%c ", EMPTY_CHAR);
            } else if (cell->x + 1 == x && cell->y == y) {
                printf("%c ", WALL_CHAR);
            } else {
                printf("%c ", WALL_CHAR);
            }
        }
        printf("\n");
    }
}

int main() {
    Cell* cell = createCell(0, 0);
    generateMaze(cell);
    printMaze(cell);

    return 0;
}