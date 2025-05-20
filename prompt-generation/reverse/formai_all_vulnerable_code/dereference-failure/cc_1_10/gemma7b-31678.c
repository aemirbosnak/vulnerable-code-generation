//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void drawBoard(int **board)
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void makeMove(int **board, int player)
{
    int move_x, move_y;

    printf("Enter move (x, y): ");
    scanf("%d %d", &move_x, &move_y);

    if(board[move_x][move_y] == player)
    {
        board[move_x][move_y] = 0;
    }
    else
    {
        printf("Invalid move!\n");
    }
}

int main()
{
    int **board = (int **)malloc(6 * sizeof(int *));
    for(int i = 0; i < 6; i++)
    {
        board[i] = (int *)malloc(6 * sizeof(int));
    }

    int player = 1;
    int game_over = 0;

    drawBoard(board);

    while(!game_over)
    {
        makeMove(board, player);

        drawBoard(board);

        if(board[5][5] == player)
        {
            game_over = 1;
        }
        else
        {
            player *= -1;
        }
    }

    printf("Game over!\n");

    return 0;
}