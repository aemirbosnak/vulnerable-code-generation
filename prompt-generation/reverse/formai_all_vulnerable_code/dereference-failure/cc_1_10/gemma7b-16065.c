//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_BINGO 5

typedef struct BingoCard
{
    int numbers[MAX_NUM_BINGO];
    int marked[MAX_NUM_BINGO];
    int winning;
} BingoCard;

BingoCard *createBingoCard()
{
    BingoCard *card = malloc(sizeof(BingoCard));

    card->numbers[0] = rand() % 90 + 1;
    card->numbers[1] = rand() % 90 + 1;
    card->numbers[2] = rand() % 90 + 1;
    card->numbers[3] = rand() % 90 + 1;
    card->numbers[4] = rand() % 90 + 1;

    card->marked[0] = 0;
    card->marked[1] = 0;
    card->marked[2] = 0;
    card->marked[3] = 0;
    card->marked[4] = 0;

    card->winning = 0;

    return card;
}

void markBingoCard(BingoCard *card, int num)
{
    for (int i = 0; i < MAX_NUM_BINGO; i++)
    {
        if (card->numbers[i] == num && card->marked[i] == 0)
        {
            card->marked[i] = 1;
        }
    }
}

int checkBingoCard(BingoCard *card)
{
    // Check rows
    for (int i = 0; i < MAX_NUM_BINGO; i++)
    {
        if (card->marked[i] == 5)
        {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < MAX_NUM_BINGO; i++)
    {
        int columnWins = 1;
        for (int j = 0; j < MAX_NUM_BINGO; j++)
        {
            if (card->marked[j] != 1)
            {
                columnWins = 0;
            }
        }
        if (columnWins)
        {
            return 1;
        }
    }

    // Check diagonals
    if (card->marked[0] == card->marked[2] && card->marked[0] == card->marked[4] && card->marked[0] == card->marked[3])
    {
        return 1;
    }

    return 0;
}

int main()
{
    BingoCard *card = createBingoCard();

    markBingoCard(card, 12);
    markBingoCard(card, 24);
    markBingoCard(card, 36);

    if (checkBingoCard(card))
    {
        printf("You win!");
    } else
    {
        printf("Sorry, you lose.");
    }

    return 0;
}