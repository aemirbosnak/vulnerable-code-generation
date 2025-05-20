//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct player {
    int id;
    int score;
    int time;
};

struct game {
    int num_players;
    int num_turns;
    struct player *players;
};

// Create a new game
struct game *create_game(int num_players, int num_turns) {
    struct game *game = malloc(sizeof(struct game));
    game->num_players = num_players;
    game->num_turns = num_turns;
    game->players = malloc(sizeof(struct player) * num_players);
    for (int i = 0; i < num_players; i++) {
        game->players[i].id = i;
        game->players[i].score = 0;
        game->players[i].time = 0;
    }
    return game;
}

// Free the memory allocated for a game
void free_game(struct game *game) {
    free(game->players);
    free(game);
}

// Play a game
void play_game(struct game *game) {
    for (int i = 0; i < game->num_turns; i++) {
        for (int j = 0; j < game->num_players; j++) {
            // Get the player's input
            int input;
            printf("Player %d, enter a number: ", game->players[j].id);
            scanf("%d", &input);

            // Check if the input is valid
            if (input < 0 || input > 100) {
                printf("Invalid input. Please enter a number between 0 and 100.\n");
                j--;
                continue;
            }

            // Update the player's score and time
            game->players[j].score += input;
            game->players[j].time += 1;
        }
    }
}

// Print the results of the game
void print_results(struct game *game) {
    printf("Player Scores:\n");
    for (int i = 0; i < game->num_players; i++) {
        printf("Player %d: %d points in %d seconds\n", game->players[i].id, game->players[i].score, game->players[i].time);
    }

    // Find the winner
    int max_score = -1;
    int winner = -1;
    for (int i = 0; i < game->num_players; i++) {
        if (game->players[i].score > max_score) {
            max_score = game->players[i].score;
            winner = i;
        }
        else 
        if (game->players[i].score == max_score)
        if (game->players[i].time < game->players[winner].time){
            max_score = game->players[i].score;
            winner = i;
        }
    }

    // Print the winner
    printf("The winner is Player %d with a score of %d points in %d seconds\n", winner, max_score, game->players[winner].time);
}

// Main function
int main() {
    // Create a new game
    struct game *game = create_game(2, 10);

    // Play the game
    play_game(game);

    // Print the results of the game
    print_results(game);

    // Free the memory allocated for the game
    free_game(game);

    return 0;
}