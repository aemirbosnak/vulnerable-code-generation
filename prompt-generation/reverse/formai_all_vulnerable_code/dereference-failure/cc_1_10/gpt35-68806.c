//FormAI DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum array sizes
#define MAX_NAME_LENGTH 20
#define MAX_PLAYERS 10

// Define a struct to hold player information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

int main() {
    Player *players[MAX_PLAYERS]; // Array to hold pointers to players
    int num_players = 0; // Track number of players currently in players array

    // Loop to add players
    while (1) {
        // Prompt user for player name
        printf("Enter player name (or 'done' to finish): ");
        char name[MAX_NAME_LENGTH];
        fgets(name, MAX_NAME_LENGTH, stdin); // Read input

        // If user entered "done", exit the loop
        if (strcmp(name, "done\n") == 0) {
            break;
        }

        // Allocate memory for the new player
        Player *new_player = malloc(sizeof(Player));

        // Copy the name into the new player's name member
        strcpy(new_player->name, name);

        // Set the initial score to 0
        new_player->score = 0;

        // Add the new player to the players array
        players[num_players] = new_player;
        num_players++;
    }

    // Game loop
    while (1) {
        // Print current scores
        printf("Current scores:\n");
        for (int i = 0; i < num_players; i++) {
            printf("%s: %d\n", players[i]->name, players[i]->score);
        }

        // Prompt user for which player's score to change
        printf("Enter player name to modify score (or 'done' to finish): ");
        char name[MAX_NAME_LENGTH];
        fgets(name, MAX_NAME_LENGTH, stdin); // Read input

        // If user entered "done", exit the loop
        if (strcmp(name, "done\n") == 0) {
            break;
        }

        // Find the player in the players array
        Player *player_to_modify = NULL;
        for (int i = 0; i < num_players; i++) {
            if (strcmp(players[i]->name, name) == 0) {
                player_to_modify = players[i];
                break;
            }
        }

        // If player was not found, continue to next iteration of loop
        if (player_to_modify == NULL) {
            printf("Player not found.\n");
            continue;
        }

        // Prompt user for score change amount
        printf("Enter amount to change score: ");
        int score_change;
        scanf("%d", &score_change);
        getchar(); // Consume the newline character left over from the scanf call

        // Modify the player's score
        player_to_modify->score += score_change;
    }

    // Free memory for all players
    for (int i = 0; i < num_players; i++) {
        free(players[i]);
    }

    return 0;
}