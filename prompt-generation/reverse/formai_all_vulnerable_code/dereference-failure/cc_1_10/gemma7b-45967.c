//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell
{
    int x;
    int y;
    char state;
} Cell;

void initializeBoard(Cell **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j].x = i;
            board[i][j].y = j;
            board[i][j].state = 'o';
        }
    }
}

int isBoardFull(Cell **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j].state == ' ')
            {
                return 0;
            }
        }
    }

    return 1;
}

void makeMove(Cell **board, int player)
{
    int move = rand() % 9;

    while (board[move/BOARD_SIZE][move%BOARD_SIZE].state != ' ')
    {
        move = rand() % 9;
    }

    board[move/BOARD_SIZE][move%BOARD_SIZE].state = player;
}

int checkWin(Cell **board, int player)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i].state == player && board[1][i].state == player && board[2][i].state == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[j][0].state == player && board[j][1].state == player && board[j][2].state == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0].state == player && board[1][1].state == player && board[2][2].state == player)
    {
        return 1;
    }

    if (board[0][2].state == player && board[1][1].state == player && board[2][0].state == player)
    {
        return 1;
    }

    return 0;
}

int main()
{
    Cell **board = (Cell **)malloc(BOARD_SIZE * sizeof(Cell *));
    initializeBoard(board);

    int player = 1;
    while (!isBoardFull(board) && !checkWin(board, player))
    {
        makeMove(board, player);
        player = (player == 1) ? 2 : 1;
    }

    if (checkWin(board, player))
    {
        printf("Player %d won!", player);
    }
    else
    {
        printf("It's a draw!");
    }

    return 0;
}