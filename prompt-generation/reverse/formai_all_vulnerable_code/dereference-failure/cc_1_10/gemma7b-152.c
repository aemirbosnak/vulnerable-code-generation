//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUM_BALLS 10

typedef struct BingoCard
{
    int **numbers;
    int rows;
    int cols;
    int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card)
{
    card->numbers = (int **)malloc(card->rows * sizeof(int *));
    for (int r = 0; r < card->rows; r++)
    {
        card->numbers[r] = (int *)malloc(card->cols * sizeof(int));
        for (int c = 0; c < card->cols; c++)
        {
            card->numbers[r][c] = 0;
        }
    }
    card->wins = 0;
}

void markBingoCard(BingoCard *card, int number)
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
    return 0;
}

int main()
{
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);

    // Generate balls
    int balls[MAX_NUM_BALLS];
    for (int i = 0; i < MAX_NUM_BALLS; i++)
    {
        balls[i] = rand() % MAX_BINGO_CARD_SIZE + 1;
    }

    // Draw balls
    for (int i = 0; i < MAX_NUM_BALLS; i++)
    {
        markBingoCard(card, balls[i]);
        if (checkBingo(card))
        {
            card->wins++;
            printf("Bingo! You won %d times!\n", card->wins);
            break;
        }
    }

    return 0;
}