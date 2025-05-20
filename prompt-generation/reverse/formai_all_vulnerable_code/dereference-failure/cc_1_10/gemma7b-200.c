//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: calm
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

typedef struct Cell {
    int x, y;
    struct Cell* north, *south, *east, *west;
} Cell;

Cell* createCell(int x, int y) {
    Cell* cell = malloc(sizeof(Cell));
    cell->x = x;
    cell->y = y;
    cell->north = NULL;
    cell->south = NULL;
    cell->east = NULL;
    cell->west = NULL;
    return cell;
}

void generateMaze(Cell* cell, int seed) {
    srand(seed);
    int r = rand() % 4;
    switch (r) {
        case 0:
            cell->north = createCell(cell->x, cell->y - 1);
            break;
        case 1:
            cell->south = createCell(cell->x, cell->y + 1);
            break;
        case 2:
            cell->east = createCell(cell->x + 1, cell->y);
            break;
        case 3:
            cell->west = createCell(cell->x - 1, cell->y);
            break;
    }
}

void printMaze(Cell* cell) {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            Cell* currentCell = cell;
            while (currentCell) {
                if (currentCell->x == x && currentCell->y == y) {
                    printf("O ");
                } else {
                    printf(" ");
                }
                currentCell = currentCell->north;
            }
            printf("\n");
        }
    }
}

int main() {
    Cell* start = createCell(0, 0);
    generateMaze(start, time(NULL));
    printMaze(start);
    return 0;
}