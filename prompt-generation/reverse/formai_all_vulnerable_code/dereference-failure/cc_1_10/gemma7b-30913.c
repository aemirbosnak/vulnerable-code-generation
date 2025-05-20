//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 20

typedef struct BingoCard
{
    int numbers[MAX_NUM];
    int numFilled;
    int winning;
} BingoCard;

void generateBingoCard(BingoCard *card)
{
    card->numFilled = 0;
    for (int i = 0; i < MAX_NUM; i++)
    {
        card->numbers[i] = rand() % MAX_NUM + 1;
    }
    card->winning = 0;
}

void markCard(BingoCard *card, int num)
{
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (card->numbers[i] == num)
        {
            card->numbers[i] = -1;
            card->numFilled++;
        }
    }
}

int checkWin(BingoCard *card)
{
    // Check rows
    for (int i = 0; i < MAX_NUM / 5; i++)
    {
        int win = 1;
        for (int j = 0; j < 5; j++)
        {
            if (card->numbers[i * 5 + j] != -1)
            {
                win = 0;
            }
        }
        if (win)
        {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 5; i++)
    {
        int win = 1;
        for (int j = 0; j < MAX_NUM / 5; j++)
        {
            if (card->numbers[j * 5 + i] != -1)
            {
                win = 0;
            }
        }
        if (win)
        {
            return 1;
        }
    }

    // Check diagonals
    int win = 1;
    for (int i = 0; i < MAX_NUM / 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (card->numbers[i * 5 + j] != -1)
            {
                win = 0;
            }
        }
    }
    if (win)
    {
        return 1;
    }

    return 0;
}

int main()
{
    BingoCard *card = malloc(sizeof(BingoCard));
    generateBingoCard(card);

    // Simulate drawing numbers
    for (int i = 0; i < 10; i++)
    {
        int num = rand() % MAX_NUM + 1;
        markCard(card, num);

        if (checkWin(card))
        {
            printf("Winner! You won!\n");
            card->winning = 1;
            break;
        }
    }

    if (!card->winning)
    {
        printf("Sorry, you lose.\n");
    }

    return 0;
}