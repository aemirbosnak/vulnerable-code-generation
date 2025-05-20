//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 10
#define PLAYERS 4

typedef struct player {
    char name[50];
    int score;
} player_t;

typedef struct game {
    player_t players[PLAYERS];
    int game_state;
} game_t;

// Function prototypes
void init_game(game_t *game);
void add_player(game_t *game, char *name);
void roll_dice(game_t *game, int *roll);
void player_turn(game_t *game);
void end_game(game_t *game);

// Function definitions
void init_game(game_t *game) {
    int i;

    for (i = 0; i < PLAYERS; i++) {
        game->players[i].score = 0;
    }

    game->game_state = 0;
}

void add_player(game_t *game, char *name) {
    int i;

    for (i = 0; i < PLAYERS; i++) {
        if (strcmp(name, game->players[i].name) == 0) {
            // Player already exists, do nothing
            return;
        }
    }

    strcpy(game->players[i].name, name);
    game->players[i].score = 0;
}

void roll_dice(game_t *game, int *roll) {
    int die1, die2;

    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;

    *roll = die1 + die2;
}

void player_turn(game_t *game) {
    int roll, player_index;

    player_index = (game->game_state / 2) % PLAYERS;

    roll_dice(game, &roll);

    game->players[player_index].score += roll;

    if (game->players[player_index].score > 100) {
        game->players[player_index].score = 100;
    }

    game->game_state++;

    if (game->game_state == TABLE_SIZE * PLAYERS) {
        end_game(game);
    }
}

void end_game(game_t *game) {
    int i;

    for (i = 0; i < PLAYERS; i++) {
        printf("%s scored %d points\n", game->players[i].name, game->players[i].score);
    }

    printf("Game over, highest score is %d\n", game->players[0].score);
}

int main() {
    game_t game;

    init_game(&game);

    int i;

    for (i = 0; i < PLAYERS; i++) {
        add_player(&game, "Player");
    }

    for (i = 0; i < TABLE_SIZE; i++) {
        player_turn(&game);
    }

    end_game(&game);

    return 0;
}