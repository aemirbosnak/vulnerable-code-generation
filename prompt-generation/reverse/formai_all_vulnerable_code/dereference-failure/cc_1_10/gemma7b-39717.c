//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 1000

int main()
{
    int numPlayers = 2;
    char **words = (char**)malloc(numPlayers * MAX_WORDS * sizeof(char*));
    for (int i = 0; i < numPlayers; i++)
    {
        words[i] = (char*)malloc(MAX_WORDS * sizeof(char));
    }

    // Game loop
    for (int round = 0; round < 5; round++)
    {
        // Each player enters a word
        for (int i = 0; i < numPlayers; i++)
        {
            printf("Player %d, enter a word: ", i + 1);
            scanf("%s", words[i]);
        }

        // Compare words
        int winner = -1;
        for (int i = 0; i < numPlayers; i++)
        {
            for (int j = 0; j < numPlayers; j++)
            {
                if (i != j && strcmp(words[i], words[j]) == 0)
                {
                    winner = i;
                }
            }
        }

        // Print winner
        if (winner != -1)
        {
            printf("Player %d won the round!\n", winner + 1);
        }
    }

    // Free memory
    for (int i = 0; i < numPlayers; i++)
    {
        free(words[i]);
    }
    free(words);

    return 0;
}