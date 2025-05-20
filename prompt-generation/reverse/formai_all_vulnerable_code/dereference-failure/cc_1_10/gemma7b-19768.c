//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a bingo card structure
typedef struct BingoCard
{
    int numbers[5][5];
    int freeSpace;
    int wins;
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard()
{
    BingoCard* card = malloc(sizeof(BingoCard));

    // Initialize the numbers array
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            card->numbers[i][j] = 0;
        }
    }

    // Set the free space
    card->freeSpace = rand() % 24 + 1;

    // Set the wins to 0
    card->wins = 0;

    return card;
}

// Function to check if a card has won
int checkWin(BingoCard* card)
{
    // Check the rows
    for (int i = 0; i < 5; i++)
    {
        if (card->numbers[i][0] == card->numbers[i][1] && card->numbers[i][0] == card->numbers[i][2] && card->numbers[i][0] == card->numbers[i][3] && card->numbers[i][0] == card->numbers[i][4] && card->numbers[i][0] == card->freeSpace)
        {
            return 1;
        }
    }

    // Check the columns
    for (int j = 0; j < 5; j++)
    {
        if (card->numbers[0][j] == card->numbers[1][j] && card->numbers[0][j] == card->numbers[2][j] && card->numbers[0][j] == card->numbers[3][j] && card->numbers[0][j] == card->numbers[4][j] && card->numbers[0][j] == card->freeSpace)
        {
            return 1;
        }
    }

    // Check the diagonals
    if (card->numbers[0][0] == card->numbers[1][1] && card->numbers[0][0] == card->numbers[2][2] && card->numbers[0][0] == card->numbers[3][3] && card->numbers[0][0] == card->numbers[4][4] && card->numbers[0][0] == card->freeSpace)
    {
        return 1;
    }

    // If no wins, return 0
    return 0;
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create two bingo cards
    BingoCard* card1 = generateBingoCard();
    BingoCard* card2 = generateBingoCard();

    // Draw the numbers
    for (int i = 0; i < 20; i++)
    {
        // Generate a random number between 1 and 24
        int number = rand() % 24 + 1;

        // Mark the number on the cards
        for (int j = 0; j < 2; j++)
        {
            if (card1->numbers[number][j] == 0)
            {
                card1->numbers[number][j] = 1;
            }
            if (card2->numbers[number][j] == 0)
            {
                card2->numbers[number][j] = 1;
            }
        }

        // Check if either card has won
        if (checkWin(card1) || checkWin(card2))
        {
            // Print the winner
            printf("Winner: ");
            if (checkWin(card1))
            {
                printf("Card 1");
            }
            if (checkWin(card2))
            {
                printf("Card 2");
            }
            printf("\n");

            // Reset the cards
            generateBingoCard(card1);
            generateBingoCard(card2);
        }
    }

    return 0;
}