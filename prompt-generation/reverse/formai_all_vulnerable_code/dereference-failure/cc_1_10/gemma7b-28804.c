//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 10

void deal_cards(int **cards, int num_cards)
{
    for (int i = 0; i < num_cards; i++)
    {
        cards[i] = rand() % MAX_NUMBER + 1;
    }
}

int compare_cards(int card1, int card2)
{
    return card1 - card2;
}

int main()
{
    int num_players = 2;
    int num_cards = 5;
    int **cards = (int **)malloc(num_players * num_cards * sizeof(int));

    deal_cards(cards, num_cards);

    for (int i = 0; i < num_players; i++)
    {
        printf("Player %d's cards: ", i + 1);
        for (int j = 0; j < num_cards; j++)
        {
            printf("%d ", cards[i][j]);
        }
        printf("\n");
    }

    int winner = compare_cards(cards[0][0], cards[1][0]);

    if (winner > 0)
    {
        printf("Player 1 wins!");
    }
    else if (winner < 0)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("It's a draw!");
    }

    free(cards);

    return 0;
}