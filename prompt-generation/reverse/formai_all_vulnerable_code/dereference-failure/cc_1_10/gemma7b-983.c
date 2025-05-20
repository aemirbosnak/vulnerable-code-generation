//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 10
#define FILL_PERCENTAGE 20

int main()
{
    int **board = NULL;
    int i, j, k, x, y;
    time_t t;

    // Allocate memory for the board
    board = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
    }

    // Initialize the board
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Fill the board randomly
    t = time(NULL);
    srand(t);
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (rand() % 100 < FILL_PERCENTAGE)
            {
                board[i][j] = 1;
            }
        }
    }

    // Print the board
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < BOARD_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}