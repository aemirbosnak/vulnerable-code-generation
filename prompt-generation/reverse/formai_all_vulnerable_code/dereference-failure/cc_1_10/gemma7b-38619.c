//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_BALLS_NUMBER 100

typedef struct BingoCard
{
    int **numbers;
    int rows;
    int columns;
    int balls_won;
} BingoCard;

void generate_bingo_card(BingoCard *card)
{
    card->numbers = malloc(card->rows * card->columns * sizeof(int));
    for (int i = 0; i < card->rows; i++)
    {
        for (int j = 0; j < card->columns; j++)
        {
            card->numbers[i][j] = rand() % MAX_BALLS_NUMBER + 1;
        }
    }
}

void check_bingo(BingoCard *card)
{
    for (int i = 0; i < card->rows; i++)
    {
        for (int j = 0; j < card->columns; j++)
        {
            if (card->numbers[i][j] == card->balls_won)
            {
                card->numbers[i][j] = -1;
            }
        }
    }

    if (card->balls_won == MAX_BALLS_NUMBER)
    {
        card->balls_won = -1;
    }
}

int main()
{
    BingoCard card;
    card.rows = MAX_BINGO_CARD_SIZE;
    card.columns = MAX_BINGO_CARD_SIZE;

    generate_bingo_card(&card);

    // Simulate drawing balls
    for (int i = 0; i < MAX_BALLS_NUMBER; i++)
    {
        card.balls_won = rand() % MAX_BALLS_NUMBER + 1;
        check_bingo(&card);
    }

    if (card.balls_won != -1)
    {
        printf("Congratulations! You won!");
    } else
    {
        printf("Sorry, you lost.");
    }

    return 0;
}