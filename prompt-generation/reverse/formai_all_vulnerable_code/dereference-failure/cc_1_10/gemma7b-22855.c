//Gemma-7B DATASET v1.0 Category: Chess engine ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 64

typedef struct Piece {
    char type;
    int x, y;
    struct Piece* next;
} Piece;

typedef struct Game {
    Piece* white, *black;
    char whose_turn;
    int move_counter;
    struct Game* next;
} Game;

Game* create_game() {
    Game* game = malloc(sizeof(Game));
    game->white = NULL;
    game->black = NULL;
    game->whose_turn = 'W';
    game->move_counter = 0;
    game->next = NULL;
    return game;
}

void make_move(Game* game, int x, int y) {
    Piece* piece = malloc(sizeof(Piece));
    piece->type = 'P';
    piece->x = x;
    piece->y = y;
    piece->next = NULL;

    if (game->whose_turn == 'W') {
        game->white = piece;
    } else {
        game->black = piece;
    }

    game->move_counter++;
    game->whose_turn = (game->whose_turn == 'W') ? 'B' : 'W';
}

void print_board(Game* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", game->white->x == i ? 'W' : ' ');
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", game->black->x == i ? 'B' : ' ');
    }
    printf("\n");
}

int main() {
    Game* game = create_game();
    make_move(game, 0, 0);
    make_move(game, 1, 0);
    make_move(game, 2, 0);
    print_board(game);

    return 0;
}