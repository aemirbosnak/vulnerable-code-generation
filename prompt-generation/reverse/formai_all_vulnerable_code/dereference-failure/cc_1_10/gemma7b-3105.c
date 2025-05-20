//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 50

typedef struct BingoCard
{
    int **numbers;
    int rows;
    int cols;
} BingoCard;

BingoCard* createBingoCard(int r, int c)
{
    BingoCard* card = malloc(sizeof(BingoCard));
    card->rows = r;
    card->cols = c;
    card->numbers = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        card->numbers[i] = (int*)malloc(c * sizeof(int));
    }
    return card;
}

void generateBingoCard(BingoCard* card)
{
    for (int r = 0; r < card->rows; r++)
    {
        for (int c = 0; c < card->cols; c++)
        {
            card->numbers[r][c] = rand() % MAX_NUM + 1;
        }
    }
}

int main()
{
    BingoCard* card = createBingoCard(5, 5);
    generateBingoCard(card);

    for (int i = 0; i < card->rows; i++)
    {
        for (int j = 0; j < card->cols; j++)
        {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }

    free(card->numbers);
    free(card);

    return 0;
}