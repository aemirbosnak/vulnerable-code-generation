//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_board(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int r = 0; r < size; r++)
    {
        board[r] = (int *)malloc(size * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the board
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Simulate life
    for (int t = 0; t < 10; t++)
    {
        draw_board(board, size);

        // Calculate the next generation
        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < size; c++)
            {
                int neighbors = 0;
                if (r > 0) neighbors++;
                if (r < size - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < size - 1) neighbors++;

                if (board[r][c] && neighbors < 2) board[r][c] = 0;
                else if (!board[r][c] && neighbors == 3) board[r][c] = 1;
            }
        }
    }

    draw_board(board, size);
    free(board);

    return 0;
}