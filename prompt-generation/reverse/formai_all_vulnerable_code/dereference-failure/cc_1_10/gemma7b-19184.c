//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 25

typedef struct BingoCard
{
    int **cards;
    int rows;
    int cols;
    int win_num;
} BingoCard;

void generate_card(BingoCard *card)
{
    card->cards = (int **)malloc(card->rows * sizeof(int *));
    for (int r = 0; r < card->rows; r++)
    {
        card->cards[r] = (int *)malloc(card->cols * sizeof(int));
        for (int c = 0; c < card->cols; c++)
        {
            card->cards[r][c] = rand() % MAX_NUM + 1;
        }
    }
}

int check_win(BingoCard *card)
{
    // Check rows
    for (int r = 0; r < card->rows; r++)
    {
        int win = 1;
        for (int c = 0; c < card->cols; c++)
        {
            if (card->cards[r][c] != card->win_num)
            {
                win = 0;
            }
        }
        if (win)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < card->cols; c++)
    {
        int win = 1;
        for (int r = 0; r < card->rows; r++)
        {
            if (card->cards[r][c] != card->win_num)
            {
                win = 0;
            }
        }
        if (win)
        {
            return 1;
        }
    }

    // Check diagonals
    if (card->rows == card->cols)
    {
        int win = 1;
        for (int d = 0; d < card->rows; d++)
        {
            if (card->cards[d][d] != card->win_num)
            {
                win = 0;
            }
        }
        if (win)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    BingoCard card;
    card.rows = 5;
    card.cols = 5;
    generate_card(&card);

    if (check_win(&card))
    {
        printf("You win!");
    } else
    {
        printf("Sorry, you lose.");
    }

    return 0;
}