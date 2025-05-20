//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: artistic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void draw_board(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] ? '*' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int size = 10;
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
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] && board[r + dr][c + dc] != board[r][c])
                        {
                            neighbors++;
                        }
                    }
                }

                board[r][c] = neighbors > 3 || neighbors < 2 ? 0 : board[r][c];
            }
        }
    }

    draw_board(board, size);

    // Free the memory
    for (int r = 0; r < size; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}