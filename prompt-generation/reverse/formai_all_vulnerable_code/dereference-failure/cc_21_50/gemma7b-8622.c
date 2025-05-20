//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **board = NULL;
    int x, y;

    // Allocate memory for the game board
    board = (int **)malloc(WIDTH * sizeof(int *) + HEIGHT * sizeof(int));
    for (x = 0; x < WIDTH; x++)
    {
        board[x] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the game board
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            board[x][y] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create some random living cells
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (rand() % 20 == 0)
            {
                board[x][y] = 1;
            }
        }
    }

    // Display the game board
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            printf("%d ", board[x][y]);
        }
        printf("\n");
    }

    // Simulate the game of life
    for (x = 0; x < 10; x++)
    {
        // Calculate the number of living neighbors for each cell
        for (x = 0; x < WIDTH; x++)
        {
            for (y = 0; y < HEIGHT; y++)
            {
                int num_neighbors = 0;
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        if (board[x + dx][y + dy] == 1)
                        {
                            num_neighbors++;
                        }
                    }
                }

                // Apply the rules of life
                if (board[x][y] == 1 && num_neighbors < 2)
                {
                    board[x][y] = 0;
                }
                else if (board[x][y] == 0 && num_neighbors == 3)
                {
                    board[x][y] = 1;
                }
            }
        }

        // Display the game board
        for (x = 0; x < WIDTH; x++)
        {
            for (y = 0; y < HEIGHT; y++)
            {
                printf("%d ", board[x][y]);
            }
            printf("\n");
        }
    }

    // Free the memory allocated for the game board
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            free(board[x][y]);
        }
        free(board[x]);
    }
    free(board);

    return 0;
}