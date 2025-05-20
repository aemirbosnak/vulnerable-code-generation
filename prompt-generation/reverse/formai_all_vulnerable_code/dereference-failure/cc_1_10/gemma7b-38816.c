//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 9
#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard
{
    int **numbers;
    int **marked;
    int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card)
{
    card->numbers = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++)
    {
        card->numbers[r] = (int *)malloc(NUM_COLS * sizeof(int));
        for (int c = 0; c < NUM_COLS; c++)
        {
            card->numbers[r][c] = rand() % MAX_NUM + 1;
        }
    }

    card->marked = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++)
    {
        card->marked[r] = (int *)malloc(NUM_COLS * sizeof(int));
        for (int c = 0; c < NUM_COLS; c++)
        {
            card->marked[r][c] = 0;
        }
    }

    card->wins = 0;
}

void markBingoCard(BingoCard *card, int number)
{
    for (int r = 0; r < NUM_ROWS; r++)
    {
        for (int c = 0; c < NUM_COLS; c++)
        {
            if (card->numbers[r][c] == number && card->marked[r][c] == 0)
            {
                card->marked[r][c] = 1;
            }
        }
    }

    if (card->wins == 0 && isBingo(card))
    {
        card->wins = 1;
    }
}

int isBingo(BingoCard *card)
{
    for (int r = 0; r < NUM_ROWS; r++)
    {
        if (card->marked[r][0] == 1 && card->marked[r][1] == 1 && card->marked[r][2] == 1)
        {
            return 1;
        }
    }

    for (int c = 0; c < NUM_COLS; c++)
    {
        if (card->marked[0][c] == 1 && card->marked[1][c] == 1 && card->marked[2][c] == 1)
        {
            return 1;
        }
    }

    if (card->marked[0][0] == 1 && card->marked[1][1] == 1 && card->marked[2][2] == 1)
    {
        return 1;
    }

    return 0;
}

int main()
{
    BingoCard card;
    initializeBingoCard(&card);

    for (int i = 0; i < 20; i++)
    {
        markBingoCard(&card, rand() % MAX_NUM + 1);
    }

    if (card.wins)
    {
        printf("Congratulations! You won!\n");
    }
    else
    {
        printf("Sorry, you lost.\n");
    }

    return 0;
}