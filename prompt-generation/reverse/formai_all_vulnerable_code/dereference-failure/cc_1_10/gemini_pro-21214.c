//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 3
#define NUM_PLAYERS 2

typedef struct {
    char name[20];
    int score;
} player_t;

typedef struct {
    player_t *players[NUM_PLAYERS];
    int current_player;
    char board[SIZE][SIZE];
} game_t;

void init_game(game_t *game) {
    int i, j;

    for (i = 0; i < NUM_PLAYERS; i++) {
        game->players[i] = malloc(sizeof(player_t));
        strcpy(game->players[i]->name, "");
        game->players[i]->score = 0;
    }

    game->current_player = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            game->board[i][j] = ' ';
        }
    }
}

void free_game(game_t *game) {
    int i;

    for (i = 0; i < NUM_PLAYERS; i++) {
        free(game->players[i]);
    }
}

void print_board(game_t *game) {
    int i, j;

    printf("\n");

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c | ", game->board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int check_winner(game_t *game) {
    int i, j;

    // Check rows
    for (i = 0; i < SIZE; i++) {
        if (game->board[i][0] != ' ' && game->board[i][0] == game->board[i][1] && game->board[i][1] == game->board[i][2]) {
            return game->current_player;
        }
    }

    // Check columns
    for (j = 0; j < SIZE; j++) {
        if (game->board[0][j] != ' ' && game->board[0][j] == game->board[1][j] && game->board[1][j] == game->board[2][j]) {
            return game->current_player;
        }
    }

    // Check diagonals
    if (game->board[0][0] != ' ' && game->board[0][0] == game->board[1][1] && game->board[1][1] == game->board[2][2]) {
        return game->current_player;
    }

    if (game->board[0][2] != ' ' && game->board[0][2] == game->board[1][1] && game->board[1][1] == game->board[2][0]) {
        return game->current_player;
    }

    return -1;
}

int main() {
    game_t game;
    char input[3];
    int i, j;

    init_game(&game);

    while (1) {
        print_board(&game);

        printf("%s's turn: ", game.players[game.current_player]->name);
        scanf("%s", input);

        i = input[0] - '1';
        j = input[1] - '1';

        if (i < 0 || i >= SIZE || j < 0 || j >= SIZE || game.board[i][j] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        game.board[i][j] = game.current_player == 0 ? 'X' : 'O';

        if (check_winner(&game) != -1) {
            printf("%s wins!\n", game.players[game.current_player]->name);
            break;
        }

        game.current_player = (game.current_player + 1) % NUM_PLAYERS;
    }

    free_game(&game);

    return 0;
}