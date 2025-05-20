//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_ROWS 5
#define MAX_NUM_COLS 5

typedef struct BingoCard
{
    int **numbers;
    int rows;
    int cols;
    int wins;
} BingoCard;

BingoCard* createBingoCard()
{
    BingoCard* card = malloc(sizeof(BingoCard));
    card->rows = rand() % MAX_NUM_ROWS + 1;
    card->cols = rand() % MAX_NUM_COLS + 1;
    card->numbers = malloc(card->rows * card->cols * sizeof(int));
    card->wins = 0;
    return card;
}

void generateBingoNumbers(BingoCard* card)
{
    for (int r = 0; r < card->rows; r++)
    {
        for (int c = 0; c < card->cols; c++)
        {
            card->numbers[r][c] = rand() % 90 + 1;
        }
    }
}

void markBingoNumber(BingoCard* card, int number)
{
    for (int r = 0; r < card->rows; r++)
    {
        for (int c = 0; c < card->cols; c++)
        {
            if (card->numbers[r][c] == number)
            {
                card->numbers[r][c] = -1;
            }
        }
    }
}

int checkBingo(BingoCard* card)
{
    for (int r = 0; r < card->rows; r++)
    {
        if (card->numbers[r][0] == -1 && card->numbers[r][1] == -1 && card->numbers[r][2] == -1)
        {
            return 1;
        }
    }

    for (int c = 0; c < card->cols; c++)
    {
        if (card->numbers[0][c] == -1 && card->numbers[1][c] == -1 && card->numbers[2][c] == -1)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    BingoCard* card = createBingoCard();
    generateBingoNumbers(card);
    markBingoNumber(card, 12);
    markBingoNumber(card, 24);
    markBingoNumber(card, 36);
    if (checkBingo(card))
    {
        printf("Bingo!");
    }

    return 0;
}