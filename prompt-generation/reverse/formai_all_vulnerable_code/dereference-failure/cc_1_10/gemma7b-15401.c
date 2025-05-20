//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdlib.h>
#include <stdio.h>

void draw_board(int **board)
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            printf("%c ", board[r][c] + 'a');
        }
        printf("\n");
    }
}

int main()
{
    int **board = malloc(5 * sizeof(int *));
    for (int r = 0; r < 5; r++)
    {
        board[r] = malloc(5 * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            board[r][c] = 0;
        }
    }

    // Place some cells
    board[2][2] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    draw_board(board);

    // Simulate Game of Life
    int generation = 0;
    while (1)
    {
        draw_board(board);
        printf("Generation: %d\n", generation);

        // Calculate the next generation
        int **next_board = malloc(5 * sizeof(int *));
        for (int r = 0; r < 5; r++)
        {
            next_board[r] = malloc(5 * sizeof(int));
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
        generation++;

        // Check if the game is over
        if (board[2][2] == 0)
        {
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}