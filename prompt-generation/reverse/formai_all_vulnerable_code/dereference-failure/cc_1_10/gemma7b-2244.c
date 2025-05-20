//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void initializeBoard(int **board, int size)
{
    board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }
}

void printBoard(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int countAliveNeighbors(int **board, int i, int j)
{
    int aliveNeighbors = 0;
    for (int r = -1; r <= 1; r++)
    {
        for (int c = -1; c <= 1; c++)
        {
            if (board[i + r][j + c] == 1)
            {
                aliveNeighbors++;
            }
        }
    }
    return aliveNeighbors;
}

void updateBoard(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int aliveNeighbors = countAliveNeighbors(board, i, j);
            if (aliveNeighbors < 2)
            {
                board[i][j] = 0;
            }
            else if (aliveNeighbors == 2)
            {
                board[i][j] = 1;
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board;

    initializeBoard(board, size);

    board[1][1] = board[2][2] = board[3][3] = 1;

    printBoard(board, size);

    updateBoard(board, size);

    printBoard(board, size);

    return 0;
}