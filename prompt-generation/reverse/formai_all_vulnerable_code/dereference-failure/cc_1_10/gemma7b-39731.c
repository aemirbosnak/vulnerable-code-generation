//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct BingoCard
{
    int numbers[MAX];
    int freeSpaces;
} BingoCard;

BingoCard* createBingoCard()
{
    BingoCard* card = malloc(sizeof(BingoCard));
    card->freeSpaces = MAX;
    for (int i = 0; i < MAX; i++)
    {
        card->numbers[i] = 0;
    }
    return card;
}

void markBingoCard(BingoCard* card, int number)
{
    for (int i = 0; i < MAX; i++)
    {
        if (card->numbers[i] == number)
        {
            card->numbers[i] = -1;
            card->freeSpaces--;
        }
    }
}

int main()
{
    BingoCard* card = createBingoCard();
    markBingoCard(card, 12);
    markBingoCard(card, 34);
    markBingoCard(card, 45);
    markBingoCard(card, 21);
    markBingoCard(card, 52);

    int win = card->freeSpaces == 0;
    if (win)
    {
        printf("You win!");
    }
    else
    {
        printf("Try again!");
    }

    return 0;
}