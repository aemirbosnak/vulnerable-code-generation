//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    // Create a 5x5 board
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }

    // Place some living cells
    board[2][2] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    // Simulate Game of Life
    int generations = 0;
    while (board[size - 1][size - 1] != 1)
    {
        draw_board(board, size);
        printf("Generation: %d\n", generations);

        // Calculate the next generation
        int **next_board = (int **)malloc(size * sizeof(int *));
        for (int i = 0; i < size; i++)
        {
            next_board[i] = (int *)malloc(size * sizeof(int));
        }

        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < size; c++)
            {
                int neighbors = 0;
                if (r > 0) neighbors++;
                if (r < size - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < size - 1) neighbors++;

                next_board[r][c] = board[r][c] * (neighbors == 2);
            }
        }

        // Free the previous board
        for (int i = 0; i < size; i++)
        {
            free(board[i]);
        }
        free(board);

        // Copy the next generation to the current board
        board = next_board;

        // Increment the generation count
        generations++;
    }

    // Draw the final board
    draw_board(board, size);
    printf("Generation: %d\n", generations);

    // Free the memory
    for (int i = 0; i < size; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}