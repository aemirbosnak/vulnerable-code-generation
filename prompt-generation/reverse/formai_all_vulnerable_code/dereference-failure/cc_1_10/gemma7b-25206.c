//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void drawBoard(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

void nextGeneration(int **board)
{
    int **nextBoard = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int r = 0; r < MAX_SIZE; r++)
    {
        nextBoard[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            int numNeighbors = 0;
            if (r - 1 >= 0) numNeighbors++;
            if (r + 1 < MAX_SIZE) numNeighbors++;
            if (c - 1 >= 0) numNeighbors++;
            if (c + 1 < MAX_SIZE) numNeighbors++;

            nextBoard[r][c] = board[r][c] + numNeighbors - 2;
        }
    }

    drawBoard(nextBoard);

    free(nextBoard);
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int r = 0; r < MAX_SIZE; r++)
    {
        board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    board[0][0] = 1;
    board[1][1] = 1;
    board[2][2] = 1;

    drawBoard(board);

    nextGeneration(board);

    drawBoard(board);

    free(board);

    return 0;
}