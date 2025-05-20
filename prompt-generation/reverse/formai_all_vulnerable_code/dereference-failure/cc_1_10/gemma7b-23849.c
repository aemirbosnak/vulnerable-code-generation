//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_NUMS 9
#define MAX_NUMS_PER_ROW 5

typedef struct BingoCard
{
    int **numbers;
    int rows;
    int cols;
    int wins;
} BingoCard;

BingoCard *createBingoCard(int rows, int cols)
{
    BingoCard *card = malloc(sizeof(BingoCard));
    card->rows = rows;
    card->cols = cols;
    card->numbers = malloc(rows * cols * sizeof(int));
    card->wins = 0;
    return card;
}

void populateBingoCard(BingoCard *card)
{
    srand(time(NULL));
    for (int i = 0; i < card->rows; i++)
    {
        for (int j = 0; j < card->cols; j++)
        {
            card->numbers[i][j] = rand() % MAX_BINGO_NUMS + 1;
        }
    }
}

int checkBingo(BingoCard *card)
{
    for (int i = 0; i < card->rows; i++)
    {
        for (int j = 0; j < card->cols; j++)
        {
            if (card->numbers[i][j] == card->numbers[0][0])
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    BingoCard *card = createBingoCard(5, 5);
    populateBingoCard(card);

    if (checkBingo(card))
    {
        printf("Bingo!");
    } else
    {
        printf("Sorry, no bingo.");
    }

    return 0;
}