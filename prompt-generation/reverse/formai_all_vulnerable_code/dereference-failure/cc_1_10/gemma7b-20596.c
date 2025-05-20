//Gemma-7B DATASET v1.0 Category: Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **board = NULL;
    int size = 0;
    int i = 0, j = 0, k = 0;

    board = malloc(sizeof(char *) * 10);
    for (i = 0; i < 10; i++)
    {
        board[i] = malloc(sizeof(char) * 10);
    }

    size = 3;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            board[i][j] = ' ';
        }
    }

    board[0][0] = 'X';
    board[1][1] = 'O';
    board[2][2] = 'X';

    k = 0;
    while (!board[size - 1][size - 1] && k < 100)
    {
        printf("Enter move (x, y): ");
        scanf("%d, %d", &i, &j);

        if (board[i][j] != ' ')
        {
            printf("Error: Move already made.\n");
        }
        else if (board[i][j] == 'O')
        {
            printf("Error: Not your move.\n");
        }
        else
        {
            board[i][j] = 'X';
            k++;
        }
    }

    printf("Game over!\n");

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            free(board[i][j]);
        }
        free(board[i]);
    }

    free(board);

    return 0;
}