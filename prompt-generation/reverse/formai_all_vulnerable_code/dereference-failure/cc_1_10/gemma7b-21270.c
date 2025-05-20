//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the Bingo Card
typedef struct BingoCard
{
    int numbers[5][5];
    int freeSpaces;
    int winStatus;
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard()
{
    BingoCard* card = malloc(sizeof(BingoCard));
    card->freeSpaces = 24;
    card->winStatus = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    return card;
}

// Function to check if a card has won
int checkWin(BingoCard* card)
{
    // Check rows
    for (int i = 0; i < 5; i++)
    {
        if (card->numbers[0][i] == card->numbers[1][i] && card->numbers[0][i] == card->numbers[2][i] && card->numbers[0][i] == card->numbers[3][i] && card->numbers[0][i] == card->numbers[4][i])
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++)
    {
        if (card->numbers[j][0] == card->numbers[j][1] && card->numbers[j][0] == card->numbers[j][2] && card->numbers[j][0] == card->numbers[j][3] && card->numbers[j][0] == card->numbers[j][4])
        {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == card->numbers[2][2] && card->numbers[0][0] == card->numbers[4][4])
    {
        return 1;
    }

    // Check for free spaces
    if (card->freeSpaces == 0)
    {
        return 1;
    }

    return 0;
}

int main()
{
    BingoCard* card = generateBingoCard();

    // Play the game
    while (!checkWin(card))
    {
        // Get the number called
        int numberCalled = rand() % 90 + 1;

        // Check if the number is on the card
        if (card->numbers[numberCalled / 5][numberCalled % 5] == numberCalled)
        {
            // Mark the number as called
            card->numbers[numberCalled / 5][numberCalled % 5] = -1;

            // Check if the card has won
            if (checkWin(card))
            {
                // Print the winning card
                printf("Winning card:\n");
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        printf("%d ", card->numbers[i][j]);
                    }
                    printf("\n");
                }

                // Print the winning message
                printf("You have won!\n");
            }
        }
    }

    return 0;
}