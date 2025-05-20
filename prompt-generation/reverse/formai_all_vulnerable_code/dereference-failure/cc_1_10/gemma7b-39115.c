//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: portable
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

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

    if (cell->x == 0) {
        cell->up = createCell(cell->x, cell->y - 1);
    }
    if (cell->y == MAZE_HEIGHT - 1) {
        cell->down = createCell(cell->x, cell->y + 1);
    }
    if (cell->x == MAZE_WIDTH - 1) {
        cell->right = createCell(cell->x + 1, cell->y);
    }
    if (cell->y == 0) {
        cell->left = createCell(cell->x - 1, cell->y);
    }

    if (chance == 0) {
        cell->up = NULL;
        cell->down = NULL;
        cell->right = NULL;
        cell->left = NULL;
    }
}

void drawMaze(Cell* cell) {
    system("clear");

    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            Cell* current = cell;
            while (current) {
                if (current->x == x && current->y == y) {
                    printf(WALL_CHAR);
                } else {
                    printf(EMPTY_CHAR);
                }
                current = current->up;
            }
            printf("\n");
        }
    }
}

int main() {
    Cell* cell = createCell(0, 0);
    generateMaze(cell);
    drawMaze(cell);

    return 0;
}