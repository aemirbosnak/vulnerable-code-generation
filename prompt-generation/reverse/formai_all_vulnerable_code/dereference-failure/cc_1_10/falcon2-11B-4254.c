//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Cell;

typedef struct {
    int width, height;
    Cell **grid;
} GameOfLife;

void initialize_grid(GameOfLife *game, int width, int height) {
    game->width = width;
    game->height = height;
    game->grid = malloc(sizeof(Cell *) * height);
    for (int i = 0; i < height; i++) {
        game->grid[i] = malloc(sizeof(Cell) * width);
    }
}

void populate_grid(GameOfLife *game, int width, int height, int live_cells) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            game->grid[i][j].x = j;
            game->grid[i][j].y = i;
        }
    }
    for (int i = 0; i < live_cells; i++) {
        int r = rand() % height;
        int c = rand() % width;
        game->grid[r][c].x = c;
        game->grid[r][c].y = r;
    }
}

void print_grid(GameOfLife *game) {
    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->width; j++) {
            printf("%d ", game->grid[i][j].x);
        }
        printf("\n");
    }
}

int main() {
    int width = 20;
    int height = 20;
    int live_cells = 100;
    GameOfLife game;
    initialize_grid(&game, width, height);
    populate_grid(&game, width, height, live_cells);
    print_grid(&game);
    return 0;
}