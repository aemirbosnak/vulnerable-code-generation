//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int score;
} Player;

typedef struct {
    Player *players;
    int num_players;
} Game;

Game *create_game(int num_players) {
    Game *game = malloc(sizeof(Game));
    game->players = malloc(sizeof(Player) * num_players);
    game->num_players = num_players;
    return game;
}

void destroy_game(Game *game) {
    for (int i = 0; i < game->num_players; i++) {
        free(game->players[i].name);
    }
    free(game->players);
    free(game);
}

void add_player(Game *game, char *name) {
    Player *player = game->players + game->num_players;
    player->name = strdup(name);
    player->score = 0;
    game->num_players++;
}

void print_game(Game *game) {
    printf("Players:\n");
    for (int i = 0; i < game->num_players; i++) {
        printf("%s: %d\n", game->players[i].name, game->players[i].score);
    }
    printf("\n");
}

int main() {
    Game *game = create_game(2);
    add_player(game, "Player 1");
    add_player(game, "Player 2");

    print_game(game);

    destroy_game(game);

    return 0;
}