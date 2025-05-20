//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: rigorous
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR ' '

typedef struct Cell {
    int x, y;
    struct Cell* up, *down, *right, *left;
} Cell;

Cell* createCell(int x, int y) {
    Cell* cell = malloc(sizeof(Cell));
    cell->x = x;
    cell->y = y;
    cell->up = NULL;
    cell->down = NULL;
    cell->right = NULL;
    cell->left = NULL;
    return cell;
}

void generateMaze(Cell* cell) {
    srand(time(NULL));
    int chance = rand() % 2;
    if (chance == 0) {
        cell->up = createCell(cell->x, cell->y - 1);
    }
    chance = rand() % 2;
    if (chance == 0) {
        cell->down = createCell(cell->x, cell->y + 1);
    }
    chance = rand() % 2;
    if (chance == 0) {
        cell->right = createCell(cell->x + 1, cell->y);
    }
    chance = rand() % 2;
    if (chance == 0) {
        cell->left = createCell(cell->x - 1, cell->y);
    }
}

void drawMaze(Cell* cell) {
    system("clear");
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            if (cell->x == x && cell->y == y) {
                printf("X");
            } else if (cell->up) {
                if (cell->up->x == x && cell->up->y == y) {
                    printf("#");
                } else {
                    printf(" ");
                }
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    Cell* cell = createCell(0, 0);
    generateMaze(cell);
    drawMaze(cell);

    return 0;
}