//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 5

int main()
{
    int num_players = 2;
    int **bingo_cards = NULL;
    int round = 1;
    int current_num = 0;
    int won = 0;

    // Allocate memory for bingo cards
    bingo_cards = (int**)malloc(num_players * sizeof(int*));
    for (int i = 0; i < num_players; i++)
    {
        bingo_cards[i] = (int*)malloc(MAX_NUM * sizeof(int));
    }

    // Generate bingo cards
    for (int i = 0; i < num_players; i++)
    {
        for (int j = 0; j < MAX_NUM; j++)
        {
            bingo_cards[i][j] = rand() % MAX_NUM + 1;
        }
    }

    // Draw numbers
    while (!won)
    {
        current_num = rand() % MAX_NUM + 1;
        printf("Number drawn: %d\n", current_num);

        // Check if player has won
        for (int i = 0; i < num_players; i++)
        {
            for (int j = 0; j < MAX_NUM; j++)
            {
                if (bingo_cards[i][j] == current_num)
                {
                    bingo_cards[i][j] = 0;
                    if (bingo_cards[i][0] == 0)
                    {
                        won = 1;
                        printf("Player %d has won!\n", i + 1);
                    }
                }
            }
        }

        round++;
    }

    // Free memory
    for (int i = 0; i < num_players; i++)
    {
        free(bingo_cards[i]);
    }
    free(bingo_cards);

    return 0;
}