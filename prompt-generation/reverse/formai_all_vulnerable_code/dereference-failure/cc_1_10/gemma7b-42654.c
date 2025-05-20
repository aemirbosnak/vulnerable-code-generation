//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPOT '-'

void drawBoard(char **board)
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

char getValidMove(char **board)
{
    int move = rand() % (BOARD_SIZE * BOARD_SIZE);
    while (board[move / BOARD_SIZE][move % BOARD_SIZE] != EMPTY_SPOT)
    {
        move = rand() % (BOARD_SIZE * BOARD_SIZE);
    }
    return move;
}

int main()
{
    char **board = (char **)malloc(BOARD_SIZE * sizeof(char *));
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        board[r] = (char *)malloc(BOARD_SIZE * sizeof(char));
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            board[r][c] = EMPTY_SPOT;
        }
    }

    char currentPlayer = PLAYER_X;
    char move;

    while (!board[move / BOARD_SIZE][move % BOARD_SIZE] == PLAYER_O && board[move / BOARD_SIZE][move % BOARD_SIZE] != PLAYER_X)
    {
        move = getValidMove(board);
        board[move / BOARD_SIZE][move % BOARD_SIZE] = currentPlayer;

        drawBoard(board);

        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    drawBoard(board);

    printf("Game Over!");

    free(board);

    return 0;
}