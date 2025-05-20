//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 20

// Macro to generate random numbers between 0 and 1
#define RAND() ((double)rand() / (double)RAND_MAX)

// Percolation function to simulate the flow of water
void percolate(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // If the cell is not saturated and the neighbor cell has water,
            // there is a chance for the cell to get water
            if (board[i][j] == 0 && board[i][j-1] == 1)
            {
                if (RAND() < 0.5)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
}

int main()
{
    // Create a 2D array to store the water level
    int **board = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
    }

    // Initialize the water level to 0 for all cells
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Simulate the flow of water
    percolate(board, BOARD_SIZE);

    // Print the water level
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}