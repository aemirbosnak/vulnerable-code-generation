//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: surprised
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

typedef struct Cell {
    int x;
    int y;
    struct Cell* up;
    struct Cell* right;
    struct Cell* down;
    struct Cell* left;
} Cell;

Cell* createCell(int x, int y) {
    Cell* cell = malloc(sizeof(Cell));
    cell->x = x;
    cell->y = y;
    cell->up = NULL;
    cell->right = NULL;
    cell->down = NULL;
    cell->left = NULL;
    return cell;
}

void generateMaze(Cell* cell) {
    srand(time(NULL));
    int chance = rand() % 2;

    if (cell->x > 0) {
        cell->up = createCell(cell->x - 1, cell->y);
    }
    if (cell->y > 0) {
        cell->left = createCell(cell->x, cell->y - 1);
    }
    if (cell->x < MAZE_WIDTH - 1) {
        cell->right = createCell(cell->x + 1, cell->y);
    }
    if (cell->y < MAZE_HEIGHT - 1) {
        cell->down = createCell(cell->x, cell->y + 1);
    }

    if (chance) {
        cell->up = NULL;
        cell->left = NULL;
        cell->right = NULL;
        cell->down = NULL;
    }
}

void traverseMaze(Cell* cell) {
    printf("(%d, %d)\n", cell->x, cell->y);

    if (cell->up) {
        traverseMaze(cell->up);
    }
    if (cell->right) {
        traverseMaze(cell->right);
    }
    if (cell->down) {
        traverseMaze(cell->down);
    }
    if (cell->left) {
        traverseMaze(cell->left);
    }
}

int main() {
    Cell* cell = createCell(0, 0);
    generateMaze(cell);
    traverseMaze(cell);

    return 0;
}