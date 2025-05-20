//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

typedef struct {
    int x;
    int y;
} Cell;

typedef struct {
    Cell **grid;
    int width;
    int height;
} Game;

Game *create_game(int width, int height) {
    Game *game = malloc(sizeof(Game));
    game->width = width;
    game->height = height;
    game->grid = malloc(width * height * sizeof(Cell *));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            game->grid[i * height + j] = malloc(sizeof(Cell));
            game->grid[i * height + j]->x = i * CELL_SIZE;
            game->grid[i * height + j]->y = j * CELL_SIZE;
        }
    }
    return game;
}

void draw_grid(Game *game) {
    for (int i = 0; i < game->width; i++) {
        for (int j = 0; j < game->height; j++) {
            printf("%d ", game->grid[i * game->height + j]->x);
        }
        printf("\n");
    }
}

void update_game(Game *game) {
    for (int i = 0; i < game->width; i++) {
        for (int j = 0; j < game->height; j++) {
            Cell *cell = game->grid[i * game->height + j];
            if (cell->x + cell->y < CELL_SIZE) {
                cell->x += cell->y;
            } else if (cell->x - cell->y < CELL_SIZE) {
                cell->x -= cell->y;
            } else {
                cell->x = 0;
                cell->y = 0;
            }
        }
    }
}

void print_winner(Game *game) {
    for (int i = 0; i < game->width; i++) {
        for (int j = 0; j < game->height; j++) {
            Cell *cell = game->grid[i * game->height + j];
            if (cell->x == game->width - 1 && cell->y == game->height - 1) {
                printf("WINNER %d %d\n", i, j);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Game *game = create_game(WINDOW_WIDTH, WINDOW_HEIGHT);
    draw_grid(game);
    update_game(game);
    print_winner(game);
    return 0;
}