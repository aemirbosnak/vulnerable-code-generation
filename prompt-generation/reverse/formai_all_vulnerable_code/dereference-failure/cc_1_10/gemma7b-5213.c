//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deal_cards(int **cards, int num_cards)
{
    for (int i = 0; i < num_cards; i++)
    {
        cards[i] = rand() % 52 + 1;
    }
}

void show_cards(int *cards, int num_cards)
{
    for (int i = 0; i < num_cards; i++)
    {
        switch (cards[i])
        {
            case 1:
                printf("Ace ");
                break;
            case 2:
                printf("Two ");
                break;
            case 3:
                printf("Three ");
                break;
            case 4:
                printf("Four ");
                break;
            case 5:
                printf("Five ");
                break;
            case 6:
                printf("Six ");
                break;
            case 7:
                printf("Seven ");
                break;
            case 8:
                printf("Eight ");
                break;
            case 9:
                printf("Nine ");
                break;
            case 10:
                printf("Ten ");
                break;
            case 11:
                printf("Jack ");
                break;
            case 12:
                printf("Queen ");
                break;
            case 13:
                printf("King ");
                break;
        }
    }
}

int main()
{
    int **cards = NULL;
    int num_cards = 5;

    cards = malloc(num_cards * sizeof(int));

    deal_cards(cards, num_cards);
    show_cards(cards, num_cards);

    free(cards);

    return 0;
}