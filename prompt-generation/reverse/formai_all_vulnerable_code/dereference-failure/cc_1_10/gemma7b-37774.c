//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

typedef struct Cell {
    struct Cell* up;
    struct Cell* right;
    struct Cell* down;
    struct Cell* left;
    int x;
    int y;
} Cell;

Cell* createCell(int x, int y) {
    Cell* cell = malloc(sizeof(Cell));
    cell->up = NULL;
    cell->right = NULL;
    cell->down = NULL;
    cell->left = NULL;
    cell->x = x;
    cell->y = y;
    return cell;
}

void generateMaze() {
    srand(time(NULL));

    Cell* cells = createCell(0, 0);
    cells->up = createCell(-1, 0);
    cells->right = createCell(0, 1);

    for (int x = 0; x < MAZE_WIDTH; x++) {
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            if (rand() % 2 == 0) {
                cells->up = createCell(x, y - 1);
                cells->right = createCell(x + 1, y);
                cells->down = createCell(x, y + 1);
                cells->left = createCell(x - 1, y);
            } else {
                cells->up = NULL;
                cells->right = NULL;
                cells->down = NULL;
                cells->left = NULL;
            }
            cells = cells->right;
        }
        cells = cells->down;
    }

    // Print the maze
    for (int x = 0; x < MAZE_WIDTH; x++) {
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            if (cells->up == NULL && cells->right == NULL && cells->down == NULL && cells->left == NULL) {
                printf("%c ", EMPTY_CHAR);
            } else {
                printf("%c ", WALL_CHAR);
            }
            cells = cells->right;
        }
        printf("\n");
        cells = cells->down;
    }
}

int main() {
    generateMaze();
    return 0;
}