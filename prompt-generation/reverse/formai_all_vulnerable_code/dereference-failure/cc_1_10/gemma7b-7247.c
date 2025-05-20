//Gemma-7B DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num_players = rand() % 2 + 1;
    printf("Welcome to the Crazy Dice Rolling Game!\n");
    printf("Number of players: %d\n", num_players);

    // Create an array of pointers to player hands
    int **hands = (int **)malloc(num_players * sizeof(int *));
    for(int i = 0; i < num_players; i++)
    {
        hands[i] = (int *)malloc(6 * sizeof(int));
    }

    // Initialize the player hands
    for(int i = 0; i < num_players; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            hands[i][j] = 0;
        }
    }

    // Roll the dice
    int roll_result = rand() % 6 + 1;
    printf("The dice rolled: %d\n", roll_result);

    // Place the roll result in the player hands
    for(int i = 0; i < num_players; i++)
    {
        hands[i][roll_result - 1] = 1;
    }

    // Print the player hands
    for(int i = 0; i < num_players; i++)
    {
        printf("Player %d's hand: ", i + 1);
        for(int j = 0; j < 6; j++)
        {
            if(hands[i][j] == 1)
            {
                printf("%d ", j + 1);
            }
        }
        printf("\n");
    }

    // Free the memory
    for(int i = 0; i < num_players; i++)
    {
        free(hands[i]);
    }
    free(hands);

    return 0;
}