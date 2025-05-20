//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int roll_dice() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 1 and 6
    int roll = rand() % 6 + 1;

    // Return the roll
    return roll;
}

// Function to play a game of dice
void play_game() {
    // Get the number of players from the user
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    // Create an array to store the scores of the players
    int scores[num_players];

    // Initialize the scores of the players to 0
    for (int i = 0; i < num_players; i++) {
        scores[i] = 0;
    }

    // Play the game until a player reaches a score of 100
    while (1) {
        // Roll the dice for each player
        for (int i = 0; i < num_players; i++) {
            int roll = roll_dice();

            // Add the roll to the player's score
            scores[i] += roll;

            // Check if the player has reached a score of 100
            if (scores[i] >= 100) {
                // The player has reached a score of 100, so they win the game
                printf("Player %d wins!\n", i + 1);

                // Exit the game
                return;
            }
        }
    }
}

// Main function
int main() {
    // Play the game of dice
    play_game();

    return 0;
}