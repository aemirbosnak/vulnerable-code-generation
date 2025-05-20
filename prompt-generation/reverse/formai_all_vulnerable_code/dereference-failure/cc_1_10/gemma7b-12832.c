//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 50

typedef struct BingoCard
{
    int numbers[MAX_NUM];
    int numCards;
    int wins;
} BingoCard;

BingoCard *createBingoCard(int numCards)
{
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numCards = numCards;
    card->wins = 0;
    for (int i = 0; i < MAX_NUM; i++)
    {
        card->numbers[i] = -1;
    }
    return card;
}

void generateBingoCard(BingoCard *card)
{
    for (int i = 0; i < card->numCards; i++)
    {
        card->numbers[rand() % MAX_NUM] = 1;
    }
}

int checkBingo(BingoCard *card)
{
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (card->numbers[i] == 1)
        {
            // Horizontal win
            if (card->numbers[i] == card->numbers[i + 1] && card->numbers[i] == card->numbers[i + 2])
            {
                return 1;
            }
            // Vertical win
            if (card->numbers[i] == card->numbers[i + MAX_NUM] && card->numbers[i] == card->numbers[i + MAX_NUM * 2])
            {
                return 1;
            }
            // Diagonal win
            if (card->numbers[i] == card->numbers[i + MAX_NUM] && card->numbers[i] == card->numbers[i + MAX_NUM * 2])
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    BingoCard *cards = createBingoCard(5);
    generateBingoCard(cards);

    for (int i = 0; i < cards->numCards; i++)
    {
        if (checkBingo(cards) == 1)
        {
            cards->wins++;
            printf("Bingo! Card %d won!\n", i + 1);
        }
    }

    return 0;
}