//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 25
#define MAX_CARDS 10

typedef struct Card
{
    int **numbers;
    int rows;
    int cols;
} Card;

void generate_cards(Card **cards, int num_cards)
{
    for (int i = 0; i < num_cards; i++)
    {
        cards[i] = malloc(sizeof(Card));
        cards[i]->rows = 5;
        cards[i]->cols = 5;
        cards[i]->numbers = malloc(sizeof(int *) * cards[i]->rows);
        for (int r = 0; r < cards[i]->rows; r++)
        {
            cards[i]->numbers[r] = malloc(sizeof(int) * cards[i]->cols);
            for (int c = 0; c < cards[i]->cols; c++)
            {
                cards[i]->numbers[r][c] = rand() % MAX_NUM + 1;
            }
        }
    }
}

int main()
{
    Card **cards = NULL;
    int num_cards = MAX_CARDS;
    generate_cards(&cards, num_cards);

    for (int i = 0; i < num_cards; i++)
    {
        printf("Card %d:\n", i + 1);
        for (int r = 0; r < cards[i]->rows; r++)
        {
            for (int c = 0; c < cards[i]->cols; c++)
            {
                printf("%d ", cards[i]->numbers[r][c]);
            }
            printf("\n");
        }
    }

    return 0;
}