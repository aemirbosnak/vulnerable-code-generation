//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 512

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Allocate memory for the board
    int *board = (int *)malloc(BOARD_SIZE * sizeof(int));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = 0;
    }

    // Simulate percolation
    for (int iter = 0; iter < 10000; iter++)
    {
        // Randomly select two cells
        int cell1 = rand() % BOARD_SIZE;
        int cell2 = rand() % BOARD_SIZE;

        // If both cells are empty, fill the smaller one
        if (board[cell1] == 0 && board[cell2] == 0)
        {
            if (cell1 < cell2)
            {
                board[cell1] = 1;
            }
            else
            {
                board[cell2] = 1;
            }
        }
    }

    // Print the board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", board[i]);
    }

    // Free the memory
    free(board);

    return 0;
}