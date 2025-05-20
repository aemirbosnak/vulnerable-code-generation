//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

typedef struct Cell {
    int x;
    int y;
    struct Cell* up;
    struct Cell* down;
    struct Cell* right;
    struct Cell* left;
} Cell;

void initGame(Cell** grid) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            *grid = malloc(sizeof(Cell));
            (*grid)->x = x;
            (*grid)->y = y;
            (*grid)->up = NULL;
            (*grid)->down = NULL;
            (*grid)->right = NULL;
            (*grid)->left = NULL;
            grid++;
        }
    }
}

void playGame(Cell* current) {
    char direction;
    printf("Enter direction (w, a, s, d): ");
    scanf("%c", &direction);

    switch (direction) {
        case 'w':
            if (current->up) {
                current = current->up;
            }
            break;
        case 'a':
            if (current->left) {
                current = current->left;
            }
            break;
        case 's':
            if (current->down) {
                current = current->down;
            }
            break;
        case 'd':
            if (current->right) {
                current = current->right;
            }
            break;
    }

    printf("Current position: (%d, %d)\n", current->x, current->y);
    playGame(current);
}

int main() {
    Cell** grid;
    initGame(&grid);
    playGame(grid[0]);

    return 0;
}