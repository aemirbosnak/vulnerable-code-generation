//Gemma-7B DATASET v1.0 Category: Table Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void play_game(int **board, int size)
{
    int i, j, turn = 0;
    char player = 'X';

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (board[i][j] == 'O')
            {
                board[i][j] = player;
            }
        }
    }

    while (!board[size - 1][size - 1] && turn < 9)
    {
        int move_x, move_y;

        printf("Enter move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        if (board[move_x][move_y] == ' ')
        {
            board[move_x][move_y] = player;
            turn++;
        }
        else
        {
            printf("Invalid move.\n");
        }
    }

    if (board[size - 1][size - 1] == player)
    {
        printf("You won!\n");
    }
    else
    {
        printf("Draw.\n");
    }
}

int main()
{
    int size;

    printf("Enter the size of the board: ");
    scanf("%d", &size);

    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    play_game(board, size);

    return 0;
}