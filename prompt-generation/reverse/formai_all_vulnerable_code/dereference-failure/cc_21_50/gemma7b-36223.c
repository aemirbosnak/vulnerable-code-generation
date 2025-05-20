//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int main()
{
    int **board = (int **)malloc(ROWS * sizeof(int *));
    for (int r = 0; r < ROWS; r++)
    {
        board[r] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create some random living cells
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (rand() % 20 == 0)
            {
                board[r][c] = 1;
            }
        }
    }

    // Run the game for 20 generations
    for (int gen = 0; gen < 20; gen++)
    {
        // Calculate the number of living neighbors for each cell
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                int neighbors = 0;
                if (board[r-1][c] == 1) neighbors++;
                if (board[r+1][c] == 1) neighbors++;
                if (board[r][c-1] == 1) neighbors++;
                if (board[r][c+1] == 1) neighbors++;

                // Apply the Game of Life rules
                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }
    }

    // Print the final board
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < ROWS; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}