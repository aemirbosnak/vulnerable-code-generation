//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board)
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(5 * sizeof(int *));
    for (int r = 0; r < 5; r++)
    {
        board[r] = (int *)malloc(5 * sizeof(int));
    }

    // Initial board setup
    board[1][1] = 1;
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;

    // Game loop
    int generations = 0;
    while (1)
    {
        draw_board(board);

        // Calculate next generation
        int **next_board = (int **)malloc(5 * sizeof(int *));
        for (int r = 0; r < 5; r++)
        {
            next_board[r] = (int *)malloc(5 * sizeof(int));
        }

        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                int num_alive = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            num_alive++;
                        }
                    }
                }

                next_board[r][c] = (num_alive == 2) || (num_alive == 3);
            }
        }

        free(board);
        board = next_board;

        generations++;
        if (generations >= 10)
        {
            break;
        }
    }

    draw_board(board);
    printf("\nNumber of generations: %d", generations);

    return 0;
}