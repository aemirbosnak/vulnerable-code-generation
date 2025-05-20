//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void drawBoard(int **board);
int checkWin(int **board);
void makeMove(int **board, int player);

int main()
{
    int **board = NULL;
    int player = 1;
    int gameWon = 0;

    board = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
        for (int j = 0; j < MAX; j++)
        {
            board[i][j] = 0;
        }
    }

    drawBoard(board);

    while (!gameWon)
    {
        makeMove(board, player);

        drawBoard(board);

        if (checkWin(board) == player)
        {
            gameWon = 1;
        }

        player *= -1;
    }

    drawBoard(board);

    printf("Game Over!\n");

    return 0;
}

void drawBoard(int **board)
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int **board)
{
    for (int i = 0; i < MAX; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0)
        {
            return board[i][0];
        }
    }

    for (int j = 0; j < MAX; j++)
    {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != 0)
        {
            return board[0][j];
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0)
    {
        return board[0][0];
    }

    return 0;
}

void makeMove(int **board, int player)
{
    int moveX;
    int moveY;

    printf("Enter move (x, y): ");
    scanf("%d %d", &moveX, &moveY);

    if (board[moveX][moveY] != 0)
    {
        printf("Invalid move!\n");
        return;
    }

    board[moveX][moveY] = player;
}