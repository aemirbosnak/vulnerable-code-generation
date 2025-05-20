//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

int main()
{
    // Create a 2D array to store the game board
    int **board = (int**)malloc(MAX_WIDTH * sizeof(int*));
    for (int i = 0; i < MAX_WIDTH; i++)
    {
        board[i] = (int*)malloc(MAX_HEIGHT * sizeof(int));
    }

    // Initialize the board with random values
    srand(time(NULL));
    for (int i = 0; i < MAX_WIDTH; i++)
    {
        for (int j = 0; j < MAX_HEIGHT; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Game loop
    int generation = 0;
    while (1)
    {
        // Calculate the next generation of cells
        for (int i = 0; i < MAX_WIDTH; i++)
        {
            for (int j = 0; j < MAX_HEIGHT; j++)
            {
                int num_neighbors = 0;
                // Check the neighbors of the current cell
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == 0 && y == 0)
                        {
                            continue;
                        }
                        if (board[i + x][j + y] == 1)
                        {
                            num_neighbors++;
                        }
                    }
                }

                // Update the cell's state
                if (board[i][j] == 0 && num_neighbors >= 3)
                {
                    board[i][j] = 1;
                }
                else if (board[i][j] == 1 && (num_neighbors < 2 || num_neighbors > 3))
                {
                    board[i][j] = 0;
                }
            }
        }

        // Print the game board
        for (int i = 0; i < MAX_WIDTH; i++)
        {
            for (int j = 0; j < MAX_HEIGHT; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Increment the generation counter
        generation++;

        // Check if the game is over
        if (generation >= 10)
        {
            break;
        }
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < MAX_WIDTH; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}