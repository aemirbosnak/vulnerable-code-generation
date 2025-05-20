//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int players, maxPoints;
    printf("How many players? (2-4): ");
    scanf("%d", &players);
    printf("What's the maximum points to win? (10-50): ");
    scanf("%d", &maxPoints);
    printf("\n\nLet's play the C Table Game!\n\n");

    // Initialize player scores to 0
    int scores[players];
    for (int i = 0; i < players; i++) {
        scores[i] = 0;
    }

    // Keep playing until a player wins
    int winner = -1;
    srand(time(NULL));
    while (winner == -1) {
        for (int i = 0; i < players; i++) {
            printf("Player %d's turn:\n", i+1);
            printf("Press 'r' to roll the die: ");
            getchar(); // Clear input buffer
            char c = getchar();
            if (c == 'r') {
                int roll = rand() % 6 + 1;
                printf("You rolled a %d!\n", roll);
                if (roll == 1) {
                    printf("Oh no, you lose all your points!\n");
                    scores[i] = 0;
                } else {
                    scores[i] += roll;
                    printf("Your current score is %d.\n", scores[i]);
                    if (scores[i] >= maxPoints) {
                        winner = i+1;
                        break;
                    }
                }
            } else {
                printf("Invalid input. Try again.\n");
            }
            printf("\n");
        }
    }

    printf("\n\nCongratulations, Player %d wins with %d points!", winner, scores[winner-1]);

    return 0;
}