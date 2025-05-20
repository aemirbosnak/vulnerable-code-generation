//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 6
#define MAX_MOVES 10

typedef struct Move {
    int fromX;
    int fromY;
    int toX;
    int toY;
} Move;

Move moves[MAX_MOVES];

void initializeBoard(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }
}

void placePiece(int **board, int x, int y, int piece)
{
    board[x][y] = piece;
}

int validateMove(Move move, int **board, int size)
{
    if (move.fromX < 0 || move.fromX >= size || move.fromY < 0 || move.fromY >= size)
    {
        return 0;
    }

    if (move.toX < 0 || move.toX >= size || move.toY < 0 || move.toY >= size)
    {
        return 0;
    }

    if (board[move.fromX][move.fromY] == 0)
    {
        return 0;
    }

    return 1;
}

int main()
{
    int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] = {0};
    initializeBoard(board, MAX_BOARD_SIZE);

    placePiece(board, 1, 1, 1);
    placePiece(board, 2, 2, 2);
    placePiece(board, 3, 3, 3);

    Move move1 = {1, 1, 2, 2};
    if (validateMove(move1, board, MAX_BOARD_SIZE))
    {
        printf("Move 1 is valid.\n");
    }

    Move move2 = {2, 2, 3, 3};
    if (validateMove(move2, board, MAX_BOARD_SIZE))
    {
        printf("Move 2 is valid.\n");
    }

    return 0;
}