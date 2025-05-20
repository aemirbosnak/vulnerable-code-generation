//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void initializeBoard(int **board, int size)
{
    board = (int *)malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++)
    {
        board[i] = 0;
    }
}

void printBoard(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i * size + j]);
        }
        printf("\n");
    }
}

int calculateNeighbors(int **board, int i, int j)
{
    int neighbors = 0;
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if (x == 0 && y == 0) continue;
            if (i + x >= 0 && i + x < MAX_SIZE && j + y >= 0 && j + y < MAX_SIZE)
            {
                neighbors += board[i + x][j + y];
            }
        }
    }
    return neighbors;
}

void updateBoard(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int neighbors = calculateNeighbors(board, i, j);
            if (neighbors < 2) board[i][j] = 0;
            else if (neighbors == 2) board[i][j] = 1;
            else board[i][j] = 2;
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board;
    initializeBoard(board, size);

    // Example game setup
    board[0][0] = 1;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 1;
    board[2][2] = 1;

    printBoard(board, size);

    updateBoard(board, size);

    printBoard(board, size);

    return 0;
}