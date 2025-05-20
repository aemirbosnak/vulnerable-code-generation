//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void play_bingo(int **board, int size)
{
    int i, j, num, win = 0;
    system("clear");
    printf("Let's play Bingo!\n");

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (board[i][j] == num)
            {
                board[i][j] = -1;
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (board[i][j] != -1)
            {
                win = 1;
            }
        }
    }

    if (win)
    {
        printf("You win!\n");
    }
    else
    {
        printf("Sorry, you lose.\n");
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = rand() % 90 + 1;
        }
    }

    play_bingo(board, size);

    return 0;
}