//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROLLS 3

int main()
{
    // Number of players
    int numPlayers = 2;

    // Allocate memory for player data
    struct player
    {
        char name[20];
        int score;
    } *players = (struct player *)malloc(numPlayers * sizeof(struct player));

    // Initialize player data
    for (int i = 0; i < numPlayers; i++)
    {
        players[i].name[0] = '\0';
        players[i].score = 0;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Roll the dice for each player
    for (int round = 0; round < NUM_ROLLS; round++)
    {
        for (int i = 0; i < numPlayers; i++)
        {
            int roll = rand() % 6 + 1;
            printf("%s rolled a %d\n", players[i].name, roll);
            players[i].score += roll;
        }
    }

    // Print the final scores
    for (int i = 0; i < numPlayers; i++)
    {
        printf("%s's final score is %d\n", players[i].name, players[i].score);
    }

    // Free the allocated memory
    free(players);

    return 0;
}