//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

// Player struct
typedef struct {
    char* name;
    int score;
    int turn;
} Player;

// Game struct
typedef struct {
    Player* players[4];
    int num_players;
    int current_player;
    char* sequence;
    int sequence_length;
} Game;

// Function to create a new player
Player* create_player(char* name) {
    Player* player = (Player*)malloc(sizeof(Player));
    player->name = (char*)malloc(strlen(name) + 1);
    strcpy(player->name, name);
    player->score = 0;
    player->turn = 0;
    return player;
}

// Function to create a new game
Game* create_game(int num_players) {
    Game* game = (Game*)malloc(sizeof(Game));
    game->num_players = num_players;
    game->current_player = 0;

    // Create players
    for (int i = 0; i < num_players; i++) {
        char* name = (char*)malloc(10);
        sprintf(name, "Player %d", i + 1);
        game->players[i] = create_player(name);
    }

    // Create sequence
    game->sequence_length = 10;
    game->sequence = (char*)malloc(game->sequence_length + 1);
    for (int i = 0; i < game->sequence_length; i++) {
        game->sequence[i] = 'A' + rand() % 4;
    }
    game->sequence[game->sequence_length] = '\0';

    return game;
}

// Function to start the game
void start_game(Game* game) {
    while (1) {
        // Get input from current player
        char guess;
        printf("%s's turn: ", game->players[game->current_player]->name);
        scanf(" %c", &guess);

        // Check if guess is correct
        if (guess == game->sequence[game->current_player]) {
            // Increment player's score
            game->players[game->current_player]->score++;

            // Check if player has won
            if (game->players[game->current_player]->score == game->sequence_length) {
                printf("%s wins!\n", game->players[game->current_player]->name);
                break;
            }
        }

        // Advance to next player
        game->current_player++;
        if (game->current_player == game->num_players) {
            game->current_player = 0;
        }
    }
}

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create a new game
    Game* game = create_game(4);

    // Start the game
    start_game(game);

    return 0;
}