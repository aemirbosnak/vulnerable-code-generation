//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void initializeBoard(int **board, int size)
{
    board = (int *)malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++)
    {
        board[i] = 0;
    }
}

void displayBoard(int **board, int size)
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
    for (int r = -1; r <= 1; r++)
    {
        for (int c = -1; c <= 1; c++)
        {
            if (i + r >= 0 && i + r < MAX_SIZE && j + c >= 0 && j + c < MAX_SIZE && board[i + r][j + c] == 1)
            {
                neighbors++;
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
            if (neighbors < 2)
            {
                board[i][j] = 0;
            }
            else if (neighbors == 2)
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
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    displayBoard(board, size);
    updateBoard(board, size);
    displayBoard(board, size);

    return 0;
}