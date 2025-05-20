//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void deal_cards(int **cards, int num_cards);
void show_cards(int **cards, int num_cards);
int compare_cards(int **cards1, int **cards2, int num_cards);

int main()
{
    int **cards;
    int num_cards = 52;

    cards = (int *)malloc(num_cards * sizeof(int));
    deal_cards(cards, num_cards);
    show_cards(cards, num_cards);
    compare_cards(cards, cards, num_cards);

    free(cards);

    return 0;
}

void deal_cards(int **cards, int num_cards)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < num_cards; i++)
    {
        cards[i] = rand() % 52 + 1;
    }
}

void show_cards(int **cards, int num_cards)
{
    int i;

    for (i = 0; i < num_cards; i++)
    {
        printf("%d ", cards[i]);
    }
    printf("\n");
}

int compare_cards(int **cards1, int **cards2, int num_cards)
{
    int i;
    int winner = 0;

    for (i = 0; i < num_cards; i++)
    {
        if (cards1[i] > cards2[i])
        {
            winner = 1;
        }
        else if (cards1[i] < cards2[i])
        {
            winner = 2;
        }
    }

    if (winner == 1)
    {
        printf("Player 1 won!\n");
    }
    else if (winner == 2)
    {
        printf("Player 2 won!\n");
    }
    else
    {
        printf("It's a draw.\n");
    }

    return winner;
}