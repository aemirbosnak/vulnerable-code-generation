//GEMINI-pro DATASET v1.0 Category: Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

typedef struct {
    Player players[MAX_PLAYERS];
    int num_players;
    int current_player;
} Game;

Game* create_game() {
    Game* game = malloc(sizeof(Game));
    assert(game != NULL);
    game->num_players = 0;
    game->current_player = 0;
    return game;
}

void destroy_game(Game* game) {
    free(game);
}

void add_player(Game* game, char* name) {
    assert(game->num_players < MAX_PLAYERS);
    strcpy(game->players[game->num_players].name, name);
    game->players[game->num_players].score = 0;
    game->num_players++;
}

void print_game(Game* game) {
    printf("Game:\n");
    for (int i = 0; i < game->num_players; i++) {
        printf("  Player %d: %s, Score: %d\n", i + 1, game->players[i].name, game->players[i].score);
    }
    printf("Current player: %s\n", game->players[game->current_player].name);
}

void roll_dice(Game* game) {
    int dice_roll = rand() % 6 + 1;
    printf("Player %s rolled a %d\n", game->players[game->current_player].name, dice_roll);
    game->players[game->current_player].score += dice_roll;
}

void next_player(Game* game) {
    game->current_player = (game->current_player + 1) % game->num_players;
}

bool is_game_over(Game* game) {
    for (int i = 0; i < game->num_players; i++) {
        if (game->players[i].score >= 100) {
            return true;
        }
    }
    return false;
}

int main() {
    Game* game = create_game();

    add_player(game, "Player 1");
    add_player(game, "Player 2");
    add_player(game, "Player 3");
    add_player(game, "Player 4");

    print_game(game);

    while (!is_game_over(game)) {
        roll_dice(game);
        next_player(game);
        print_game(game);
    }

    printf("Game Over!\n");
    for (int i = 0; i < game->num_players; i++) {
        if (game->players[i].score >= 100) {
            printf("Player %s wins!\n", game->players[i].name);
        }
    }

    destroy_game(game);

    return 0;
}