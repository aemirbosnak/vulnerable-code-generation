//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 5

typedef struct BingoCard
{
    int **numbers;
    int rows;
    int cols;
} BingoCard;

void initializeBingoCard(BingoCard *card, int rows, int cols)
{
    card->rows = rows;
    card->cols = cols;
    card->numbers = (int **)malloc(rows * sizeof(int *) + 1);
    for (int r = 0; r < rows; r++)
    {
        card->numbers[r] = (int *)malloc(cols * sizeof(int) + 1);
    }
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            card->numbers[r][c] = 0;
        }
    }
}

void markBingoCard(BingoCard *card, int num)
{
    for (int r = 0; r < card->rows; r++)
    {
        for (int c = 0; c < card->cols; c++)
        {
            if (card->numbers[r][c] == num)
            {
                card->numbers[r][c] = -1;
            }
        }
    }
}

int checkBingo(BingoCard *card)
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
    if (card->numbers[0][0] == -1 && card->numbers[1][1] == -1 && card->numbers[2][2] == -1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card, 3, 5);

    markBingoCard(card, 1);
    markBingoCard(card, 2);
    markBingoCard(card, 4);
    markBingoCard(card, 6);

    if (checkBingo(card))
    {
        printf("Bingo!\n");
    } else
    {
        printf("No bingo.\n");
    }

    free(card);

    return 0;
}