//FormAI DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int roll_dice() {
    return (rand() % 6) + 1; // Returns a random number between 1 to 6.
}

// Function to play a round
void play_round(int player_number, int *player_score) {
    printf("\nPlayer %d's turn:\n", player_number);
    int roll = roll_dice(); // Roll the dice
    printf("You rolled a %d\n", roll);
    if (roll == 1) {
        printf("Oops! You lose all your points.\n");
        *player_score = 0;
    } else {
        *player_score += roll;
        printf("Your score is now %d\n", *player_score);
    }
}

// Function to check if a player has won
int is_winner(int *player_scores, int num_players, int winning_score) {
    for (int i = 0; i < num_players; i++) {
        if (player_scores[i] >= winning_score) {
            return i; // Returns the index of the winning player
        }
    }
    return -1; // No winner yet
}

int main() {
    srand(time(NULL)); // Initialize random number generator

    int num_players;
    printf("How many players? ");
    scanf("%d", &num_players);

    int winning_score;
    printf("What's the winning score? ");
    scanf("%d", &winning_score);

    int *player_scores = (int *) calloc(num_players, sizeof(int)); // Initialize all player scores to 0.

    int current_player = 0;
    while (is_winner(player_scores, num_players, winning_score) == -1) { // Keep playing until there's a winner.
        play_round(current_player + 1, &player_scores[current_player]); // Play a round for the current player
        current_player = (current_player + 1) % num_players; // Switch to the next player
    }

    printf("\nPlayer %d wins with a score of %d!\n", is_winner(player_scores, num_players, winning_score) + 1, player_scores[is_winner(player_scores, num_players, winning_score)]);

    free(player_scores); // Free the memory used to store player scores
    return 0;
}