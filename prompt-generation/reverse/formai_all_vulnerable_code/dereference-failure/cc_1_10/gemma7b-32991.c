//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board
{
    int **board;
    int turn;
    int winner;
} Board;

void initializeBoard(Board *board)
{
    board->board = malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board->board[i] = malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board->board[i][j] = 0;
        }
    }
    board->turn = 0;
    board->winner = 0;
}

void makeMove(Board *board, int x, int y)
{
    if (board->board[x][y] != 0)
    {
        return;
    }
    board->board[x][y] = board->turn;
    board->turn++;
}

int checkWin(Board *board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0)
        {
            return board->board[0][i];
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0)
        {
            return board->board[j][0];
        }
    }

    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0)
    {
        return board->board[0][0];
    }

    return 0;
}

int main()
{
    Board board;
    initializeBoard(&board);

    // Play the game
    makeMove(&board, 0, 0);
    makeMove(&board, 1, 1);
    makeMove(&board, 0, 1);
    makeMove(&board, 2, 0);
    makeMove(&board, 1, 0);

    // Check if there is a winner
    int winner = checkWin(&board);

    // Print the winner
    if (winner != 0)
    {
        printf("The winner is player %d.\n", winner);
    }
    else
    {
        printf("It's a draw.\n");
    }

    return 0;
}