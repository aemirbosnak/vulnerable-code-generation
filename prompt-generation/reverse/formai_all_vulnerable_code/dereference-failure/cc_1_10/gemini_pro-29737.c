//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100
#define MAX_NAME_LENGTH 32

// Define the player structure
typedef struct player {
    char name[MAX_NAME_LENGTH];
    int score;
} player_t;

// Define the game state structure
typedef struct game_state {
    player_t players[MAX_PLAYERS];
    int num_players;
} game_state_t;

// Create a new game state
game_state_t* create_game_state() {
    game_state_t* game_state = malloc(sizeof(game_state_t));
    game_state->num_players = 0;
    return game_state;
}

// Free the game state
void free_game_state(game_state_t* game_state) {
    free(game_state);
}

// Add a player to the game state
void add_player(game_state_t* game_state, char* name) {
    if (game_state->num_players >= MAX_PLAYERS) {
        printf("Error: Maximum number of players reached\n");
        return;
    }

    strcpy(game_state->players[game_state->num_players].name, name);
    game_state->players[game_state->num_players].score = 0;
    game_state->num_players++;
}

// Remove a player from the game state
void remove_player(game_state_t* game_state, char* name) {
    int i;

    for (i = 0; i < game_state->num_players; i++) {
        if (strcmp(game_state->players[i].name, name) == 0) {
            game_state->num_players--;
            memmove(&game_state->players[i], &game_state->players[i + 1], (game_state->num_players - i) * sizeof(player_t));
            return;
        }
    }

    printf("Error: Player not found\n");
}

// Print the game state
void print_game_state(game_state_t* game_state) {
    int i;

    printf("Game state:\n");
    for (i = 0; i < game_state->num_players; i++) {
        printf("  Player %d: %s (%d points)\n", i + 1, game_state->players[i].name, game_state->players[i].score);
    }
}

// Main function
int main() {
    game_state_t* game_state;
    char input[100];
    char name[MAX_NAME_LENGTH];

    // Create a new game state
    game_state = create_game_state();

    // Main game loop
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Parse the input
        if (strncmp(input, "add", 3) == 0) {
            sscanf(input, "add %s", name);
            add_player(game_state, name);
        } else if (strncmp(input, "remove", 6) == 0) {
            sscanf(input, "remove %s", name);
            remove_player(game_state, name);
        } else if (strcmp(input, "print") == 0) {
            print_game_state(game_state);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Unknown command\n");
        }
    }

    // Free the game state
    free_game_state(game_state);

    return 0;
}