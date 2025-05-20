//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void deal_cards(int **cards, int num_cards);
void show_cards(int **cards, int num_cards);

int main()
{
    int num_players = 2;
    int num_cards = 5;
    int **cards = NULL;

    cards = (int **)malloc(num_players * sizeof(int *));
    for (int i = 0; i < num_players; i++)
    {
        cards[i] = (int *)malloc(num_cards * sizeof(int));
    }

    deal_cards(cards, num_cards);
    show_cards(cards, num_cards);

    for (int i = 0; i < num_players; i++)
    {
        free(cards[i]);
    }
    free(cards);

    return 0;
}

void deal_cards(int **cards, int num_cards)
{
    // Shuffle the deck
    srand(time(NULL));
    for (int i = 0; i < num_cards; i++)
    {
        int random_card = rand() % 52;
        cards[0][i] = random_card;
    }
}

void show_cards(int **cards, int num_cards)
{
    for (int i = 0; i < num_cards; i++)
    {
        printf("%d ", cards[0][i]);
    }
    printf("\n");
}