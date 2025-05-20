//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num_cards = rand() % 5 + 1;
    char **cards = malloc(num_cards * sizeof(char *));
    for (int i = 0; i < num_cards; i++)
    {
        cards[i] = malloc(20 * sizeof(char));
    }

    // Fill the cards with gibberish
    for (int i = 0; i < num_cards; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cards[i][j] = (rand() % 26) + 'a';
        }
    }

    // Shuffle the cards
    for (int i = 0; i < num_cards; i++)
    {
        for (int j = i; j < num_cards - 1; j++)
        {
            int r = rand() % (j - i + 1);
            char *t = cards[i];
            cards[i] = cards[j];
            cards[j] = t;
        }
    }

    // Read the cards
    for (int i = 0; i < num_cards; i++)
    {
        printf("%s ", cards[i]);
    }

    // Free the memory
    for (int i = 0; i < num_cards; i++)
    {
        free(cards[i]);
    }
    free(cards);

    return 0;
}