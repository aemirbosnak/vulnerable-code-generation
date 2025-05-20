//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Get number of players
    int numPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    // Get number of dice per player
    int numDice;
    printf("Enter the number of dice per player: ");
    scanf("%d", &numDice);

    // Initialize array of player scores
    int scores[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        scores[i] = 0;
    }

    // Roll dice for each player
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < numDice; j++) {
            // Roll a single die
            int roll = rand() % 6 + 1;

            // Add roll to player's score
            scores[i] += roll;
        }
    }

    // Print player scores
    printf("Player scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %d\n", i + 1, scores[i]);
    }

    // Find the winner
    int winningScore = 0;
    int winningPlayer = 0;
    for (int i = 0; i < numPlayers; i++) {
        if (scores[i] > winningScore) {
            winningScore = scores[i];
            winningPlayer = i;
        }
    }

    // Print the winner
    printf("The winner is Player %d with a score of %d!\n", winningPlayer + 1, winningScore);

    return 0;
}