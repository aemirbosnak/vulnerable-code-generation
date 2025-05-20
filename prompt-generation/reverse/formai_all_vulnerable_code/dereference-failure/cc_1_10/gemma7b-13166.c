//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: medieval
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

int countNeighbors(int **board, int x, int y)
{
    int neighbors = 0;
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (x + dx >= 0 && x + dx < MAX_SIZE && y + dy >= 0 && y + dy < MAX_SIZE && board[x + dx][y + dy] != 0)
            {
                neighbors++;
            }
        }
    }
    return neighbors;
}

int main()
{
    int size = 5;
    int **board;
    initializeBoard(board, size);

    // Place some initial living cells
    board[1][1] = 1;
    board[2][2] = 1;
    board[2][3] = 1;

    // Simulate Game of Life
    for (int t = 0; t < 10; t++)
    {
        displayBoard(board, size);

        for (int x = 0; x < size; x++)
        {
            for (int y = 0; y < size; y++)
            {
                int neighbors = countNeighbors(board, x, y);
                if (board[x][y] == 1 && neighbors < 2)
                {
                    board[x][y] = 0;
                }
                else if (board[x][y] == 0 && neighbors == 3)
                {
                    board[x][y] = 1;
                }
            }
        }
    }

    displayBoard(board, size);

    return 0;
}