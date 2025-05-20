//FormAI DATASET v1.0 Category: Memory management ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PLAYERS 4

typedef struct Player {
    int id;
    int score;
    struct Player *next;
} Player;

typedef struct Game {
    int num_players;
    Player *players[MAX_PLAYERS];
} Game;

void add_player(Game *game, int id) {
    Player *new_player = malloc(sizeof(Player));
    new_player->id = id;
    new_player->score = 0;
    new_player->next = NULL;
    for(int i=0; i < MAX_PLAYERS; i++) {
        if(game->players[i] == NULL) {
            game->players[i] = new_player;
            game->num_players++;
            printf("Player with id %d added to the game.\n", id);
            return;
        }
    }
    printf("Game is full! Could not add player with id %d.\n", id);
}

void remove_player(Game *game, int id) {
    Player *curr_player = NULL;
    Player *prev_player = NULL;
    for(int i=0; i < MAX_PLAYERS; i++) {
        if(game->players[i] != NULL && game->players[i]->id == id) {
            curr_player = game->players[i];
            if(prev_player == NULL) {
                game->players[i] = curr_player->next;
            }
            else {
                prev_player->next = curr_player->next;
            }
            free(curr_player);
            game->num_players--;
            printf("Player with id %d removed from game.\n", id);
            return;
        }
        prev_player = game->players[i];
    }
    printf("Player with id %d not found in the game.\n", id);
}

void print_scores(Game *game) {
    printf("Scores:\n");
    for(int i=0; i < MAX_PLAYERS; i++) {
        if(game->players[i] != NULL) {
            printf("Player id: %d, score: %d\n", game->players[i]->id, game->players[i]->score);
        }
    }
}

int main() {
    srand(time(NULL));
    Game *game = malloc(sizeof(Game));
    game->num_players = 0;
    for(int i=1; i <= 5; i++) {
        add_player(game, i);
    }

    for(int i=0; i < 25; i++) {
        int player_id = rand() % 5 + 1;
        int score = rand() % 100;
        for(int j=0; j < MAX_PLAYERS; j++) {
            if(game->players[j] != NULL && game->players[j]->id == player_id) {
                game->players[j]->score += score;
                break;
            }
        }
    }
    print_scores(game);

    while(game->num_players > 0) {
        int player_id = rand() % 5 + 1;
        remove_player(game, player_id);
    }

    free(game);

    return 0;
}