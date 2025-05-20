//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bingo Card Structure
typedef struct BingoCard
{
    int numbers[5][5];
    int freeSpaces;
    int winningNumbers[2];
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard()
{
    BingoCard* card = (BingoCard*)malloc(sizeof(BingoCard));
    card->freeSpaces = 24;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            card->numbers[i][j] = 0;
        }
    }
    return card;
}

// Function to fill the bingo card
void fillBingoCard(BingoCard* card)
{
    // Seed the random number generator
    srand(time(NULL));

    // Generate the numbers for the card
    for (int i = 0; i < 24; i++)
    {
        int number = rand() % 90 + 1;
        card->numbers[rand() % 5][rand() % 5] = number;
    }

    // Mark the free spaces
    card->freeSpaces = 0;
}

// Function to check if a card has won
int hasWon(BingoCard* card)
{
    // Check if the card has won in a row
    for (int i = 0; i < 5; i++)
    {
        if (card->numbers[0][i] == card->winningNumbers[0] &&
            card->numbers[1][i] == card->winningNumbers[0] &&
            card->numbers[2][i] == card->winningNumbers[0] &&
            card->numbers[3][i] == card->winningNumbers[0] &&
            card->numbers[4][i] == card->winningNumbers[0])
        {
            return 1;
        }
    }

    // Check if the card has won in a column
    for (int j = 0; j < 5; j++)
    {
        if (card->numbers[j][0] == card->winningNumbers[0] &&
            card->numbers[j][1] == card->winningNumbers[0] &&
            card->numbers[j][2] == card->winningNumbers[0] &&
            card->numbers[j][3] == card->winningNumbers[0] &&
            card->numbers[j][4] == card->winningNumbers[0])
        {
            return 1;
        }
    }

    // Check if the card has won in the diagonal
    if (card->numbers[0][0] == card->winningNumbers[0] &&
        card->numbers[2][2] == card->winningNumbers[0] &&
        card->numbers[4][0] == card->winningNumbers[0])
    {
        return 1;
    }

    // If the card has not won, return 0
    return 0;
}

int main()
{
    // Create a bingo card
    BingoCard* card = generateBingoCard();

    // Fill the bingo card
    fillBingoCard(card);

    // Check if the card has won
    if (hasWon(card))
    {
        printf("You have won!");
    }
    else
    {
        printf("Sorry, you have not won.");
    }

    return 0;
}