//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void shuffle_cards(int **cards, int num_cards);

int main()
{
    int num_cards = 52;
    int **cards = (int **)malloc(num_cards * sizeof(int *));

    for (int i = 0; i < num_cards; i++)
    {
        cards[i] = (int *)malloc(4 * sizeof(int));
    }

    // Deal the cards
    for (int i = 0; i < num_cards; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cards[i][j] = rand() % 13 + 1;
        }
    }

    // Shuffle the cards
    shuffle_cards(cards, num_cards);

    // Show the cards
    for (int i = 0; i < num_cards; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", cards[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < num_cards; i++)
    {
        free(cards[i]);
    }
    free(cards);

    return 0;
}

void shuffle_cards(int **cards, int num_cards)
{
    for (int i = 0; i < num_cards; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int r = rand() % num_cards;
            int tmp = cards[i][j];
            cards[i][j] = cards[r][j];
            cards[r][j] = tmp;
        }
    }
}