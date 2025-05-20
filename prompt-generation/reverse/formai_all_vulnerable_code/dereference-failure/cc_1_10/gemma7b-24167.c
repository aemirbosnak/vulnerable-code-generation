//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20

typedef struct BingoCard
{
    int **numbers;
    int rows;
    int cols;
    int win_line;
} BingoCard;

void generate_bingo_card(BingoCard *card)
{
    card->numbers = (int **)malloc(card->rows * sizeof(int *));
    for (int i = 0; i < card->rows; i++)
    {
        card->numbers[i] = (int *)malloc(card->cols * sizeof(int));
    }

    for (int i = 0; i < card->rows; i++)
    {
        for (int j = 0; j < card->cols; j++)
        {
            card->numbers[i][j] = rand() % MAX_NUM + 1;
        }
    }
}

int check_bingo(BingoCard *card)
{
    // Check horizontal win
    for (int i = 0; i < card->rows; i++)
    {
        int is_win = 1;
        for (int j = 0; j < card->cols; j++)
        {
            if (card->numbers[i][j] != card->win_line)
            {
                is_win = 0;
            }
        }

        if (is_win)
        {
            return 1;
        }
    }

    // Check vertical win
    for (int j = 0; j < card->cols; j++)
    {
        int is_win = 1;
        for (int i = 0; i < card->rows; i++)
        {
            if (card->numbers[i][j] != card->win_line)
            {
                is_win = 0;
            }
        }

        if (is_win)
        {
            return 1;
        }
    }

    // Check diagonal win
    int is_win = 1;
    for (int i = 0; i < card->rows; i++)
    {
        for (int j = 0; j < card->cols; j++)
        {
            if (card->numbers[i][j] != card->win_line)
            {
                is_win = 0;
            }
        }
    }

    if (is_win)
    {
        return 1;
    }

    return 0;
}

int main()
{
    BingoCard *card = malloc(sizeof(BingoCard));
    card->rows = 5;
    card->cols = 5;
    card->win_line = 10;

    generate_bingo_card(card);

    if (check_bingo(card))
    {
        printf("You win!");
    } else
    {
        printf("Sorry, you lose!");
    }

    return 0;
}