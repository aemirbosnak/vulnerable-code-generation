//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateBingoCard(int **card, int size);
void markCard(int **card, int number);
int checkBingo(int **card, int size);

int main()
{
    int size = 5;
    int **card = NULL;
    int i, j, number, won = 0;

    card = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        card[i] = (int *)malloc(size * sizeof(int));
    }

    generateBingoCard(card, size);

    // Simulate drawing numbers
    for (i = 0; i < 20; i++)
    {
        number = rand() % 90 + 1;
        markCard(card, number);

        if (checkBingo(card, size) == 1)
        {
            won = 1;
            break;
        }
    }

    if (won)
    {
        printf("Congratulations! You won!");
    }
    else
    {
        printf("Sorry, you lost.");
    }

    return 0;
}

void generateBingoCard(int **card, int size)
{
    int i, j, num;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            card[i][j] = 0;
        }
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            num = rand() % 90 + 1;
            card[i][j] = num;
        }
    }
}

void markCard(int **card, int number)
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (card[i][j] == number)
            {
                card[i][j] = -1;
            }
        }
    }
}

int checkBingo(int **card, int size)
{
    int i, j, win = 0;

    // Check rows
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (card[i][j] == -1)
            {
                win = 1;
            }
        }
    }

    // Check columns
    for (j = 0; j < size; j++)
    {
        for (i = 0; i < size; i++)
        {
            if (card[i][j] == -1)
            {
                win = 1;
            }
        }
    }

    // Check diagonals
    if (card[0][0] == -1 && card[2][2] == -1)
    {
        win = 1;
    }

    if (card[0][2] == -1 && card[2][0] == -1)
    {
        win = 1;
    }

    return win;
}