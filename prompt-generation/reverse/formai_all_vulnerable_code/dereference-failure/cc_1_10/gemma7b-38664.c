//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUMBERS_PER_CARD 5

typedef struct BingoCard
{
    int **numbers;
    int rows;
    int columns;
} BingoCard;

void initializeBingoCard(BingoCard *card)
{
    card->rows = MAX_BINGO_CARD_SIZE;
    card->columns = MAX_NUMBERS_PER_CARD;
    card->numbers = (int **)malloc(card->rows * sizeof(int *));
    for (int r = 0; r < card->rows; r++)
    {
        card->numbers[r] = (int *)malloc(card->columns * sizeof(int));
    }
    for (int r = 0; r < card->rows; r++)
    {
        for (int c = 0; c < card->columns; c++)
        {
            card->numbers[r][c] = 0;
        }
    }
}

void markBingoCard(BingoCard *card, int number)
{
    for (int r = 0; r < card->rows; r++)
    {
        for (int c = 0; c < card->columns; c++)
        {
            if (card->numbers[r][c] == number)
            {
                card->numbers[r][c] = -1;
            }
        }
    }
}

int checkBingo(BingoCard *card)
{
    // Check rows
    for (int r = 0; r < card->rows; r++)
    {
        int isBingo = 1;
        for (int c = 0; c < card->columns; c++)
        {
            if (card->numbers[r][c] != -1)
            {
                isBingo = 0;
            }
        }
        if (isBingo)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < card->columns; c++)
    {
        int isBingo = 1;
        for (int r = 0; r < card->rows; r++)
        {
            if (card->numbers[r][c] != -1)
            {
                isBingo = 0;
            }
        }
        if (isBingo)
        {
            return 1;
        }
    }

    // Check diagonals
    int isBingo = 1;
    for (int d = 0; d < card->rows - 1; d++)
    {
        for (int h = 0; h < card->columns - 1; h++)
        {
            if (card->numbers[h][d] != -1)
            {
                isBingo = 0;
            }
        }
    }
    if (isBingo)
    {
        return 1;
    }

    return 0;
}

int main()
{
    BingoCard *card = NULL;
    initializeBingoCard(card);

    // Generate some random numbers
    srand(time(NULL));
    int numbers[MAX_NUMBERS_PER_CARD];
    for (int i = 0; i < MAX_NUMBERS_PER_CARD; i++)
    {
        numbers[i] = rand() % 90 + 1;
    }

    // Mark the card
    for (int i = 0; i < MAX_NUMBERS_PER_CARD; i++)
    {
        markBingoCard(card, numbers[i]);
    }

    // Check if the player has won
    if (checkBingo(card))
    {
        printf("You have won!");
    }
    else
    {
        printf("Sorry, you have not won.");
    }

    return 0;
}