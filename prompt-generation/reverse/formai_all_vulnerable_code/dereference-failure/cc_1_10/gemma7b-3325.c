//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void initializeBoard(int **board, int size)
{
    board = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
        for(int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }
}

void printBoard(int **board, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void calculateNeighbors(int **board, int i, int j)
{
    int neighbors = 0;
    for(int row = -1; row <= 1; row++)
    {
        for(int col = -1; col <= 1; col++)
        {
            if(board[i + row][j + col] != 0)
            {
                neighbors++;
            }
        }
    }
    board[i][j] = neighbors;
}

void gameOfLife(int **board, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            calculateNeighbors(board, i, j);
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(board[i][j] < 2 && board[i][j] > 3)
            {
                board[i][j] = 0;
            }
            else if(board[i][j] == 3)
            {
                board[i][j] = 1;
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board = NULL;

    initializeBoard(board, size);
    printBoard(board, size);

    gameOfLife(board, size);

    printBoard(board, size);

    return 0;
}