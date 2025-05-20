//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 10
#define MAX_ROWS 5
#define MAX_COLS 5

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a bingo card
    int **bingoCard = (int **)malloc(MAX_ROWS * sizeof(int *));
    for (int i = 0; i < MAX_ROWS; i++)
    {
        bingoCard[i] = (int *)malloc(MAX_COLS * sizeof(int));
        for (int j = 0; j < MAX_COLS; j++)
        {
            bingoCard[i][j] = 0;
        }
    }

    // Draw the balls
    int ballsDrawn = 0;
    int **balls = (int *)malloc(MAX_BALLS * sizeof(int));
    for (int i = 0; i < MAX_BALLS; i++)
    {
        balls[i] = rand() % MAX_BALLS + 1;
    }

    // Mark the balls on the card
    for (int i = 0; i < MAX_BALLS; i++)
    {
        for (int r = 0; r < MAX_ROWS; r++)
        {
            for (int c = 0; c < MAX_COLS; c++)
            {
                if (bingoCard[r][c] == balls[i])
                {
                    bingoCard[r][c] = 1;
                }
            }
        }
    }

    // Check if the player has won
    int hasWon = 0;
    for (int r = 0; r < MAX_ROWS; r++)
    {
        // Check if the row has won
        if (bingoCard[r][0] == 1 && bingoCard[r][1] == 1 && bingoCard[r][2] == 1 && bingoCard[r][3] == 1 && bingoCard[r][4] == 1)
        {
            hasWon = 1;
        }
    }

    // Check if the column has won
    for (int c = 0; c < MAX_COLS; c++)
    {
        // Check if the column has won
        if (bingoCard[0][c] == 1 && bingoCard[1][c] == 1 && bingoCard[2][c] == 1 && bingoCard[3][c] == 1 && bingoCard[4][c] == 1)
        {
            hasWon = 1;
        }
    }

    // Check if the diagonal has won
    if (bingoCard[0][0] == 1 && bingoCard[1][1] == 1 && bingoCard[2][2] == 1 && bingoCard[3][3] == 1 && bingoCard[4][4] == 1)
    {
        hasWon = 1;
    }

    // Print the results
    if (hasWon)
    {
        printf("Congratulations! You have won!");
    }
    else
    {
        printf("Sorry, you have not won.");
    }

    // Free the memory
    free(bingoCard);
    free(balls);

    return 0;
}