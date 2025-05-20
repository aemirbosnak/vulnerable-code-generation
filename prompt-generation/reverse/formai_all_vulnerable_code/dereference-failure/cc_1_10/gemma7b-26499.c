//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 9

typedef struct BingoCard
{
    int numbers[MAX_NUM];
    int marked[MAX_NUM];
    int wins;
} BingoCard;

BingoCard *createBingoCard()
{
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers[0] = 1;
    card->numbers[1] = 2;
    card->numbers[2] = 3;
    card->numbers[3] = 4;
    card->numbers[4] = 5;
    card->numbers[5] = 6;
    card->numbers[6] = 7;
    card->numbers[7] = 8;
    card->numbers[8] = 9;
    card->marked[0] = 0;
    card->marked[1] = 0;
    card->marked[2] = 0;
    card->marked[3] = 0;
    card->marked[4] = 0;
    card->wins = 0;
    return card;
}

void markCard(BingoCard *card, int number)
{
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (card->numbers[i] == number && card->marked[i] == 0)
        {
            card->marked[i] = 1;
        }
    }
}

int checkWins(BingoCard *card)
{
    // Horizontal win
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (card->marked[i] == 1 && card->marked[i + 1] == 1 && card->marked[i + 2] == 1)
        {
            return 1;
        }
    }

    // Vertical win
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (card->marked[i] == 1 && card->marked[i + MAX_NUM] == 1 && card->marked[i + MAX_NUM * 2] == 1)
        {
            return 1;
        }
    }

    // Diagonal win
    if (card->marked[0] == 1 && card->marked[MAX_NUM - 1] == 1 && card->marked[MAX_NUM - 1] == 1)
    {
        return 1;
    }

    return 0;
}

int main()
{
    BingoCard *card = createBingoCard();
    markCard(card, 5);
    markCard(card, 2);
    markCard(card, 3);
    markCard(card, 8);
    markCard(card, 6);

    if (checkWins(card))
    {
        printf("You win!");
    } else
    {
        printf("Try again!");
    }

    return 0;
}