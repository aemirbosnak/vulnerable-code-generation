//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 30

typedef struct Ball
{
    int number;
    struct Ball* next;
} Ball;

typedef struct BingoCard
{
    int rows;
    int cols;
    Ball** cards;
} BingoCard;

void initializeBingoCard(BingoCard* card, int rows, int cols)
{
    card->rows = rows;
    card->cols = cols;
    card->cards = (Ball**)malloc(rows * cols * sizeof(Ball));
    for (int i = 0; i < rows * cols; i++)
    {
        card->cards[i] = NULL;
    }
}

void addBallToCard(BingoCard* card, int number)
{
    Ball* newBall = (Ball*)malloc(sizeof(Ball));
    newBall->number = number;
    newBall->next = NULL;

    if (card->cards[number] == NULL)
    {
        card->cards[number] = newBall;
    }
    else
    {
        card->cards[number]->next = newBall;
    }
}

int drawBall(BingoCard* card)
{
    srand(time(NULL));
    int number = rand() % MAX_BALLS + 1;

    if (card->cards[number] != NULL)
    {
        Ball* currentBall = card->cards[number];
        card->cards[number] = currentBall->next;
        return number;
    }

    return -1;
}

int main()
{
    BingoCard* card = (BingoCard*)malloc(sizeof(BingoCard));
    initializeBingoCard(card, 5, 5);

    for (int i = 0; i < 10; i++)
    {
        int number = drawBall(card);
        if (number != -1)
        {
            printf("Ball drawn: %d\n", number);
        }
    }

    return 0;
}