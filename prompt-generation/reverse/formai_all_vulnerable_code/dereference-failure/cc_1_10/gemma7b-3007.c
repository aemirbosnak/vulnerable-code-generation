//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
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

    // Play the game
    int generation = 0;
    while (!board[size - 1][size - 1] || generation < 10)
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
                board[r][c] = neighbors > 1 ? 1 : 0;
            }
        }

        generation++;
    }

    draw_board(board, size);

    free(board);

    return 0;
}