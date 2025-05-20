//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard
{
    int **numbers;
    int **marks;
    int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card)
{
    card->numbers = malloc(NUM_ROWS * sizeof(int *));
    for (int i = 0; i < NUM_ROWS; i++)
    {
        card->numbers[i] = malloc(NUM_COLS * sizeof(int));
    }

    card->marks = malloc(NUM_ROWS * sizeof(int *));
    for (int i = 0; i < NUM_ROWS; i++)
    {
        card->marks[i] = malloc(NUM_COLS * sizeof(int));
    }

    card->wins = 0;
}

void markBingoCard(BingoCard *card, int number)
{
    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int col = 0; col < NUM_COLS; col++)
        {
            if (card->numbers[row][col] == number && card->marks[row][col] == 0)
            {
                card->marks[row][col] = 1;
            }
        }
    }
}

int checkBingoCard(BingoCard *card)
{
    // Check columns
    for (int col = 0; col < NUM_COLS; col++)
    {
        if (card->marks[0][col] == 1 && card->marks[1][col] == 1 && card->marks[2][col] == 1 && card->marks[3][col] == 1 && card->marks[4][col] == 1)
        {
            return 1;
        }
    }

    // Check rows
    for (int row = 0; row < NUM_ROWS; row++)
    {
        if (card->marks[row][0] == 1 && card->marks[row][1] == 1 && card->marks[row][2] == 1 && card->marks[row][3] == 1 && card->marks[row][4] == 1)
        {
            return 1;
        }
    }

    // Check diagonals
    if (card->marks[0][0] == 1 && card->marks[1][1] == 1 && card->marks[2][2] == 1 && card->marks[3][3] == 1 && card->marks[4][4] == 1)
    {
        return 1;
    }

    return 0;
}

int main()
{
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);

    // Generate random numbers
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int number = rand() % 25 + 1;
        markBingoCard(card, number);
    }

    // Check if the player has won
    if (checkBingoCard(card))
    {
        printf("You have won!");
    }
    else
    {
        printf("Sorry, you have not won.");
    }

    return 0;
}