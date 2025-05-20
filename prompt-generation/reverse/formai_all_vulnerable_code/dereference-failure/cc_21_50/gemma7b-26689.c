//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int **board = NULL;
    int rows, columns;

    // Allocate memory for the game board
    rows = 10;
    columns = 10;
    board = (int **)malloc(rows * sizeof(int *) + columns * sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        board[i] = (int *)malloc(columns * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create a random pattern of living cells
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Simulate the game of life
    int generation = 0;
    while (board[0][0] || board[0][columns - 1] || board[rows - 1][0] || board[rows - 1][columns - 1])
    {
        generation++;

        // Calculate the number of living neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                int neighbors = 0;
                if (r - 1 >= 0) neighbors++;
                if (r + 1 < rows) neighbors++;
                if (c - 1 >= 0) neighbors++;
                if (c + 1 < columns) neighbors++;

                // Apply the rules of life
                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        // Print the game board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Pause the game
        printf("Press any key to continue...");
        getchar();
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < rows; i++)
    {
        free(board[i]);
    }
    free(board);

    // Print the final game board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    printf("Number of generations: %d\n", generation);

    return 0;
}