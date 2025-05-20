//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void display(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int r = 0; r < size; r++)
    {
        board[r] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create a random pattern
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Display the initial board
    display(board, size);

    // Simulate Game of Life for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        // Calculate the next generation
        int **next_board = (int **)malloc(size * sizeof(int *));
        for (int r = 0; r < size; r++)
        {
            next_board[r] = (int *)malloc(size * sizeof(int));
        }

        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < size; c++)
            {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                next_board[r][c] = (neighbors == 2) || (neighbors == 3) ? 1 : 0;
            }
        }

        // Display the next generation
        display(next_board, size);

        // Free the memory
        for (int r = 0; r < size; r++)
        {
            free(next_board[r]);
        }
        free(next_board);
    }

    // Free the memory
    for (int r = 0; r < size; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}