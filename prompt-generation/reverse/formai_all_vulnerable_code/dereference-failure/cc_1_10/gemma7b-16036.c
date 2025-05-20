//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 25

typedef struct BingoCard
{
    int numbers[MAX_NUM];
    int numCards;
    struct BingoCard* nextCard;
} BingoCard;

void generateBingoCard(BingoCard* card)
{
    for (int i = 0; i < MAX_NUM; i++)
    {
        card->numbers[i] = rand() % MAX_NUM + 1;
    }
    card->numCards = 1;
}

void addBingoCard(BingoCard* card, BingoCard* newCard)
{
    newCard->nextCard = card;
    card = newCard;
    card->numCards++;
}

void playBingo(BingoCard* card)
{

    for (int i = 0; i < MAX_NUM; i++)
    {
        int num = rand() % MAX_NUM + 1;
        if (card->numbers[num] == 0)
        {
            card->numbers[num] = 1;
            printf("Bingo! Number: %d\n", num);
            break;
        }
    }
}

int main()
{
    BingoCard* head = NULL;
    BingoCard* currentCard = NULL;

    // Generate and add 5 bingo cards to the head
    for (int i = 0; i < 5; i++)
    {
        BingoCard* newCard = malloc(sizeof(BingoCard));
        generateBingoCard(newCard);
        addBingoCard(head, newCard);
        head = newCard;
    }

    // Play bingo on each card
    for (BingoCard* card = head; card; card = card->nextCard)
    {
        playBingo(card);
    }

    return 0;
}