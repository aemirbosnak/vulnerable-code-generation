//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Position;

typedef struct {
    char *name;
    char *symbol;
    int color; // 0: white, 1: black
} Player;

typedef struct {
    char **board;
    int size;
    Player *players;
    int current_player;
} Game;

Game *create_game(int size) {
    Game *game = malloc(sizeof(Game));
    game->size = size;
    game->board = malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++) {
        game->board[i] = malloc(sizeof(char) * size);
    }
    game->players = malloc(sizeof(Player) * 2);
    game->players[0].name = "White";
    game->players[0].symbol = "W";
    game->players[0].color = 0;
    game->players[1].name = "Black";
    game->players[1].symbol = "B";
    game->players[1].color = 1;
    game->current_player = 0;
    return game;
}

void destroy_game(Game *game) {
    for (int i = 0; i < game->size; i++) {
        free(game->board[i]);
    }
    free(game->board);
    free(game->players);
    free(game);
}

void print_board(Game *game) {
    printf("  ");
    for (int i = 0; i < game->size; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < game->size; i++) {
        printf("%d ", i);
        for (int j = 0; j < game->size; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(Game *game, Position from, Position to) {
    if (from.x < 0 || from.x >= game->size || from.y < 0 || from.y >= game->size) {
        return 0;
    }
    if (to.x < 0 || to.x >= game->size || to.y < 0 || to.y >= game->size) {
        return 0;
    }
    if (game->board[from.x][from.y] != game->players[game->current_player].symbol) {
        return 0;
    }
    if (game->board[to.x][to.y] != ' ') {
        return 0;
    }
    int dx = abs(to.x - from.x);
    int dy = abs(to.y - from.y);
    if (dx != 1 && dy != 1) {
        return 0;
    }
    if (dx == 1 && dy == 1) {
        return 1;
    }
    if (dx == 2 && dy == 2) {
        int mx = (from.x + to.x) / 2;
        int my = (from.y + to.y) / 2;
        if (game->board[mx][my] != game->players[1 - game->current_player].symbol) {
            return 0;
        }
        return 1;
    }
    return 0;
}

void make_move(Game *game, Position from, Position to) {
    game->board[from.x][from.y] = ' ';
    game->board[to.x][to.y] = game->players[game->current_player].symbol;
    int dx = abs(to.x - from.x);
    int dy = abs(to.y - from.y);
    if (dx == 2 && dy == 2) {
        int mx = (from.x + to.x) / 2;
        int my = (from.y + to.y) / 2;
        game->board[mx][my] = ' ';
    }
    game->current_player = 1 - game->current_player;
}

int is_game_over(Game *game) {
    for (int i = 0; i < game->size; i++) {
        for (int j = 0; j < game->size; j++) {
            if (game->board[i][j] == 'W') {
                return 0;
            }
        }
    }
    for (int i = 0; i < game->size; i++) {
        for (int j = 0; j < game->size; j++) {
            if (game->board[i][j] == 'B') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    Game *game = create_game(8);
    for (int i = 0; i < game->size; i++) {
        for (int j = 0; j < game->size; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    game->board[i][j] = 'B';
                } else if (i > 4) {
                    game->board[i][j] = 'W';
                } else {
                    game->board[i][j] = ' ';
                }
            } else {
                game->board[i][j] = ' ';
            }
        }
    }
    print_board(game);
    while (!is_game_over(game)) {
        printf("%s's turn:\n", game->players[game->current_player].name);
        char from_x, from_y, to_x, to_y;
        printf("From: ");
        scanf(" %c%c", &from_x, &from_y);
        printf("To: ");
        scanf(" %c%c", &to_x, &to_y);
        Position from = {from_x - 'a', from_y - '1'};
        Position to = {to_x - 'a', to_y - '1'};
        if (is_valid_move(game, from, to)) {
            make_move(game, from, to);
            print_board(game);
        } else {
            printf("Invalid move!\n");
        }
    }
    if (game->current_player == 0) {
        printf("Black wins!\n");
    } else {
        printf("White wins!\n");
    }
    destroy_game(game);
    return 0;
}