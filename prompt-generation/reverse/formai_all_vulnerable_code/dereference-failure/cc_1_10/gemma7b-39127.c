//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void play_bingo(int **bingo_card, int num_cards, int balls_drawn)
{
    for (int i = 0; i < num_cards; i++)
    {
        for (int j = 0; j < balls_drawn; j++)
        {
            // Check if the ball drawn matches the number on the card
            if (bingo_card[i][j] == balls_drawn)
            {
                // Mark the number as called
                bingo_card[i][j] = -1;
            }
        }
    }

    // Check if anyone has won
    for (int i = 0; i < num_cards; i++)
    {
        // Check if the row has won
        for (int j = 0; j < balls_drawn; j++)
        {
            if (bingo_card[i][j] == -1 && bingo_card[i][j] != 0)
            {
                // The row has won
                printf("Row %d has won!\n", i + 1);
                return;
            }
        }

        // Check if the column has won
        for (int j = 0; j < balls_drawn; j++)
        {
            if (bingo_card[i][j] == -1 && bingo_card[i][j] != 0)
            {
                // The column has won
                printf("Column %d has won!\n", j + 1);
                return;
            }
        }

        // Check if the diagonal has won
        if (bingo_card[0][0] == -1 && bingo_card[0][0] != 0)
        {
            // The diagonal has won
            printf("Diagonal has won!\n");
            return;
        }
    }

    // If no one has won, print a message
    printf("No one has won.\n");
}

int main()
{
    // Create a bingo card
    int **bingo_card = NULL;
    int num_cards = 5;
    int balls_drawn = 20;

    bingo_card = (int **)malloc(num_cards * sizeof(int *));
    for (int i = 0; i < num_cards; i++)
    {
        bingo_card[i] = (int *)malloc(balls_drawn * sizeof(int));
    }

    // Populate the bingo card
    for (int i = 0; i < num_cards; i++)
    {
        for (int j = 0; j < balls_drawn; j++)
        {
            bingo_card[i][j] = rand() % 10;
        }
    }

    // Play bingo
    play_bingo(bingo_card, num_cards, balls_drawn);

    // Free the memory
    for (int i = 0; i < num_cards; i++)
    {
        free(bingo_card[i]);
    }
    free(bingo_card);

    return 0;
}