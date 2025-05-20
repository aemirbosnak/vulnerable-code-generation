//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board
{
    int **data;
    int size;
} Board;

void initializeBoard(Board *board)
{
    board->data = malloc(board->size * sizeof(int *));
    for (int i = 0; i < board->size; i++)
    {
        board->data[i] = malloc(board->size * sizeof(int));
    }
    board->size = board->size;
}

void displayBoard(Board *board)
{
    for (int i = 0; i < board->size; i++)
    {
        for (int j = 0; j < board->size; j++)
        {
            printf("%d ", board->data[i][j]);
        }
        printf("\n");
    }
}

int isBoardFull(Board *board)
{
    for (int i = 0; i < board->size; i++)
    {
        for (int j = 0; j < board->size; j++)
        {
            if (board->data[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    Board *board = malloc(sizeof(Board));
    initializeBoard(board);

    board->data[1][1] = 2;
    board->data[2][2] = 2;

    displayBoard(board);

    if (isBoardFull(board))
    {
        printf("The board is full.\n");
    }

    free(board);

    return 0;
}