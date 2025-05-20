//GEMINI-pro DATASET v1.0 Category: Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define GRID_SIZE 4
#define GRID_WIDTH 400
#define GRID_HEIGHT 400
#define CELL_SIZE (GRID_WIDTH / GRID_SIZE)

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Cell {
    int value;
    enum Direction direction;
};

struct Game {
    struct Cell grid[GRID_SIZE][GRID_SIZE];
    int score;
};

struct Game *game_new() {
    struct Game *game = malloc(sizeof(struct Game));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            game->grid[i][j].value = 0;
            game->grid[i][j].direction = UP;
        }
    }
    game->score = 0;
    return game;
}

void game_free(struct Game *game) {
    free(game);
}

void game_reset(struct Game *game) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            game->grid[i][j].value = 0;
            game->grid[i][j].direction = UP;
        }
    }
    game->score = 0;
}

void game_draw(struct Game *game) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int value = game->grid[i][j].value;
            if (value == 0) {
                printf("    ");
            } else {
                printf("%4d", value);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int game_move(struct Game *game, enum Direction direction) {
    int moved = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (game->grid[i][j].value != 0) {
                int dx = 0, dy = 0;
                switch (direction) {
                    case UP:
                        dy = -1;
                        break;
                    case DOWN:
                        dy = 1;
                        break;
                    case LEFT:
                        dx = -1;
                        break;
                    case RIGHT:
                        dx = 1;
                        break;
                }
                int new_i = i + dy;
                int new_j = j + dx;
                if (new_i >= 0 && new_i < GRID_SIZE && new_j >= 0 && new_j < GRID_SIZE) {
                    if (game->grid[new_i][new_j].value == 0) {
                        game->grid[new_i][new_j].value = game->grid[i][j].value;
                        game->grid[i][j].value = 0;
                        moved = 1;
                    } else if (game->grid[new_i][new_j].value == game->grid[i][j].value) {
                        game->grid[new_i][new_j].value *= 2;
                        game->grid[i][j].value = 0;
                        game->score += game->grid[new_i][new_j].value;
                        moved = 1;
                    }
                }
            }
        }
    }
    return moved;
}

int main() {
    struct Game *game = game_new();
    game_draw(game);

    while (1) {
        int moved = 0;
        char c = getchar();
        switch (c) {
            case 'w':
                moved = game_move(game, UP);
                break;
            case 's':
                moved = game_move(game, DOWN);
                break;
            case 'a':
                moved = game_move(game, LEFT);
                break;
            case 'd':
                moved = game_move(game, RIGHT);
                break;
            case 'q':
                game_free(game);
                return 0;
        }
        if (moved) {
            game_draw(game);
        }
    }

    return 0;
}