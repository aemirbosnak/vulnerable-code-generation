//FormAI DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int players, rounds, roll, total;
    printf("Enter the number of players: ");
    scanf("%d", &players);
    printf("Enter the number of rounds: ");
    scanf("%d", &rounds);

    int scores[players][rounds];

    // Play the game
    for (int round = 0; round < rounds; round++)
    {
        printf("\nRound %d\n\n", round + 1);
        for (int player = 0; player < players; player++)
        {
            total = 0;
            printf("Player %d, it's your turn!\n", player + 1);
            for (int i = 0; i < 3; i++)
            {
                roll = rand() % 6 + 1; // Roll a 6-sided dice
                printf("You rolled: %d\n", roll);
                total += roll;
            }
            scores[player][round] = total;
            printf("Your total score this round is: %d\n\n", total);
        }
    }

    // Print out the scores
    printf("\nFinal Scores:\n\n");
    for (int player = 0; player < players; player++)
    {
        printf("Player %d: ", player + 1);
        int total = 0;
        for (int round = 0; round < rounds; round++)
        {
            printf("%d ", scores[player][round]);
            total += scores[player][round];
        }
        printf("Total Score: %d", total);
        printf("\n");
    }

    return 0;
}