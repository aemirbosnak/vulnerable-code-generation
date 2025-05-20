//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define TILE_SIZE 3
#define BOARD_SIZE 10
#define EXPRESSION_MAX_LENGTH 10

typedef struct {
    char symbol;
    int value;
} Tile;

typedef struct {
    Tile tile[BOARD_SIZE];
    int current_tile;
} Game;

Game *create_game(void) {
    Game *game = malloc(sizeof(Game));
    for (int i = 0; i < BOARD_SIZE; i++) {
        game->tile[i].symbol = '?';
        game->tile[i].value = 0;
    }
    game->current_tile = 0;
    return game;
}

void print_board(Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c: %d\n", game->tile[i].symbol, game->tile[i].value);
    }
}

void move_tile(Game *game, int row, int col) {
    int old_tile = game->current_tile;
    game->tile[old_tile].symbol = '?';
    game->tile[old_tile].value = 0;
    game->current_tile = row * BOARD_SIZE + col;
    game->tile[game->current_tile].symbol = game->tile[old_tile].symbol;
    game->tile[game->current_tile].value = game->tile[old_tile].value;
}

int is_valid_expression(Game *game) {
    int expression_length = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->tile[i].symbol == '+' || game->tile[i].symbol == '-' || game->tile[i].symbol == '*' || game->tile[i].symbol == '/') {
            expression_length++;
        }
    }
    if (expression_length > EXPRESSION_MAX_LENGTH) {
        return 0;
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->tile[i].symbol == '+' && game->tile[i - 1].symbol == '+' ||
                game->tile[i].symbol == '-' && game->tile[i - 1].symbol == '-' ||
                game->tile[i].symbol == '*' && game->tile[i - 1].symbol == '*' ||
                game->tile[i].symbol == '/' && game->tile[i - 1].symbol == '/') {
            return 0;
        }
    }
    return 1;
}

void solve_puzzle(Game *game) {
    int i, j, k;
    int num_moves = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            for (k = 0; k < BOARD_SIZE; k++) {
                if (game->tile[i * BOARD_SIZE + j].symbol == '?') {
                    move_tile(game, i, j);
                    if (is_valid_expression(game)) {
                        num_moves++;
                        print_board(game);
                    }
                }
            }
        }
    }
    printf("Solved in %d moves\n", num_moves);
}

int main(void) {
    srand(time(NULL));
    Game *game = create_game();
    solve_puzzle(game);
    return 0;
}