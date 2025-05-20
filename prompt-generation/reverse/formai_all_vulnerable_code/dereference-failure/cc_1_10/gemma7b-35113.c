//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void draw_board(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int r = 0; r < MAX_SIZE; r++)
    {
        board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = 0;
        }
    }

    // Place some initial cells
    board[2][2] = 1;
    board[3][3] = 1;
    board[4][4] = 1;

    // Simulate game of life
    int generations = 0;
    while (1)
    {
        draw_board(board);

        // Calculate next generation
        int **next_board = (int **)malloc(MAX_SIZE * sizeof(int *));
        for (int r = 0; r < MAX_SIZE; r++)
        {
            next_board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
        }

        for (int r = 0; r < MAX_SIZE; r++)
        {
            for (int c = 0; c < MAX_SIZE; c++)
            {
                int num_neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] && board[r + dr][c + dc] != 0)
                        {
                            num_neighbors++;
                        }
                    }
                }

                next_board[r][c] = (num_neighbors == 3) || (num_neighbors == 2 && board[r][c] != 0);
            }
        }

        free(board);
        board = next_board;

        generations++;

        // Check if the game continues
        if (generations >= 10)
        {
            break;
        }
    }

    draw_board(board);

    printf("\nNumber of generations: %d", generations);

    return 0;
}