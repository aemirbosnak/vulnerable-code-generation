//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Structure definition for the players
typedef struct player_struct {
    char name[50];
    int score;
} player_t;

// Function to add players to the game
player_t *add_player(char *name) {
    player_t *new_player = (player_t*) malloc(sizeof(player_t));
    strcpy(new_player->name, name);
    new_player->score = 0;
    return new_player;
}

// Function to update player scores
void update_scores(player_t *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        players[i].score += 1;
    }
}

// Function to display player scores
void display_scores(player_t *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

// Main function
int main() {
    player_t *players[10];
    int num_players = 0;

    // Add players to the game
    printf("Enter player names (Press Enter to finish):\n");
    while (1) {
        char name[50];
        scanf("%s", name);
        if (strcmp(name, "\0") == 0) {
            break;
        }
        players[num_players++] = add_player(name);
    }

    // Update player scores
    update_scores(players, num_players);

    // Display player scores
    display_scores(players, num_players);

    return 0;
}