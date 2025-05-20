//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50
#define CELL_SIZE 10

typedef struct {
    int x;
    int y;
} Cell;

typedef struct {
    Cell **grid;
    int width;
    int height;
} Game;

Game *create_game(void) {
    Game *game = malloc(sizeof(Game));
    game->grid = malloc(sizeof(Cell*) * WIDTH * HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        game->grid[i] = malloc(sizeof(Cell) * CELL_SIZE);
    }
    game->width = WIDTH;
    game->height = HEIGHT;
    return game;
}

void update_game(Game *game) {
    for (int i = 0; i < game->width * game->height; i++) {
        Cell *cell = game->grid[i];
        if (cell->x % 2 == 0) {
            if (cell->y % 2 == 0) {
                cell->x++;
            } else {
                cell->x--;
            }
        } else {
            if (cell->y % 2 == 0) {
                cell->y++;
            } else {
                cell->y--;
            }
        }
    }
}

void draw_game(Game *game) {
    for (int i = 0; i < game->width; i++) {
        for (int j = 0; j < game->height; j++) {
            Cell *cell = game->grid[i * game->width + j];
            if (cell->x < 0) {
                printf(" X");
            } else if (cell->x >= game->width) {
                printf(" X");
            } else if (cell->y < 0) {
                printf(" Y");
            } else if (cell->y >= game->height) {
                printf(" Y");
            } else {
                printf("%d", cell->x);
            }
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));
    Game *game = create_game();
    for (int i = 0; i < 100; i++) {
        update_game(game);
        draw_game(game);
        sleep(1);
    }
    free(game->grid);
    free(game);
    return 0;
}