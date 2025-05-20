//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_SIMS 1000

void initializeBoard(int **board, int size)
{
    board = (int *)malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++)
    {
        board[i] = 0;
    }
}

void simulatePercolation(int **board, int size)
{
    srand(time(NULL));
    for (int sim = 0; sim < NUM_SIMS; sim++)
    {
        int x = rand() % size;
        int y = rand() % size;

        if (board[x][y] == 0)
        {
            board[x][y] = 1;
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

int main()
{
    int **board;
    initializeBoard(board, BOARD_SIZE);
    simulatePercolation(board, BOARD_SIZE);
    printBoard(board, BOARD_SIZE);

    return 0;
}