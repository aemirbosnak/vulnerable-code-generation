//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100

typedef struct BingoCard
{
    int **numbers;
    int rows;
    int columns;
    int winning_number;
} BingoCard;

BingoCard *createBingoCard(int rows, int columns)
{
    BingoCard *card = malloc(sizeof(BingoCard));
    card->rows = rows;
    card->columns = columns;
    card->numbers = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        card->numbers[i] = (int *)malloc(columns * sizeof(int));
    }

    return card;
}

void fillBingoCard(BingoCard *card)
{
    for (int i = 0; i < card->rows; i++)
    {
        for (int j = 0; j < card->columns; j++)
        {
            card->numbers[i][j] = rand() % MAX_NUM;
        }
    }
}

int checkBingo(BingoCard *card)
{
    // Check rows
    for (int i = 0; i < card->rows; i++)
    {
        int is_bingo = 1;
        for (int j = 0; j < card->columns; j++)
        {
            if (card->numbers[i][j] != card->winning_number)
            {
                is_bingo = 0;
            }
        }

        if (is_bingo)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < card->columns; j++)
    {
        int is_bingo = 1;
        for (int i = 0; i < card->rows; i++)
        {
            if (card->numbers[i][j] != card->winning_number)
            {
                is_bingo = 0;
            }
        }

        if (is_bingo)
        {
            return 1;
        }
    }

    // Check diagonals
    if (card->rows == card->columns)
    {
        int is_bingo = 1;
        for (int i = 0; i < card->rows; i++)
        {
            if (card->numbers[i][i] != card->winning_number)
            {
                is_bingo = 0;
            }
        }

        if (is_bingo)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    BingoCard *card = createBingoCard(5, 5);
    fillBingoCard(card);
    card->winning_number = 25;

    if (checkBingo(card))
    {
        printf("Bingo!");
    } else
    {
        printf("No bingo!");
    }

    return 0;
}