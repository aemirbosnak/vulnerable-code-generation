//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 50

typedef struct BingoCard
{
    int **numbers;
    int rows;
    int cols;
    int freeSpaces;
} BingoCard;

void createBingoCard(BingoCard *card)
{
    card->rows = 5;
    card->cols = 5;
    card->freeSpaces = 16;
    card->numbers = (int **)malloc(card->rows * sizeof(int *));
    for (int i = 0; i < card->rows; i++)
    {
        card->numbers[i] = (int *)malloc(card->cols * sizeof(int));
    }

    for (int i = 0; i < card->rows; i++)
    {
        for (int j = 0; j < card->cols; j++)
        {
            card->numbers[i][j] = 0;
        }
    }
}

void getRandomNumber(BingoCard *card)
{
    int num = rand() % MAX_NUM + 1;
    if (card->numbers[0][0] == num)
    {
        getRandomNumber(card);
    }
    else
    {
        card->numbers[rand() % card->rows][rand() % card->cols] = num;
    }
}

void printBingoCard(BingoCard *card)
{
    for (int i = 0; i < card->rows; i++)
    {
        for (int j = 0; j < card->cols; j++)
        {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    BingoCard *card = (BingoCard *)malloc(sizeof(BingoCard));
    createBingoCard(card);
    getRandomNumber(card);
    printBingoCard(card);

    return 0;
}