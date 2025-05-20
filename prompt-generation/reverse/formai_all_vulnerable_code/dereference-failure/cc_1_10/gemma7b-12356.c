//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

void play_game(int **board, int size)
{
    int i, j, turn = 0, won = 0;
    board = (int **)malloc(size * size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
        for (j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }

    while (!won && turn < MAX_SIZE * size * size)
    {
        printf("Enter row: ");
        int row = getchar() - '0';
        printf("Enter column: ");
        int column = getchar() - '0';

        if (board[row][column] == 0)
        {
            board[row][column] = turn + 1;
            turn++;
        }
        else
        {
            printf("This cell is already occupied.\n");
        }

        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (board[i][j] == turn)
                {
                    printf("O");
                }
                else if (board[i][j] != 0)
                {
                    printf("X");
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }

        if (board[row][column] == MAX_SIZE)
        {
            won = 1;
            printf("Congratulations! You won!\n");
        }
    }

    if (!won)
    {
        printf("Sorry, no winner.\n");
    }

    free(board);
}

int main()
{
    play_game(NULL, 5);
    return 0;
}