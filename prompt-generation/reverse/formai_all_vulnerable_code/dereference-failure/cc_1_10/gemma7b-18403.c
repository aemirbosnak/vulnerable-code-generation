//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

void draw_board(int **board)
{
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(HEIGHT * sizeof(int *));
    for (int r = 0; r < HEIGHT; r++)
    {
        board[r] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initial board setup
    board[5][5] = board[5][6] = board[6][5] = board[6][6] = 1;

    int generation = 0;

    while (1)
    {
        draw_board(board);
        printf("Generation: %d\n", generation);

        // Calculate next generation
        int **next_board = (int **)malloc(HEIGHT * sizeof(int *));
        for (int r = 0; r < HEIGHT; r++)
        {
            next_board[r] = (int *)malloc(WIDTH * sizeof(int));
        }

        for (int r = 0; r < HEIGHT; r++)
        {
            for (int c = 0; c < WIDTH; c++)
            {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] && board[r + dr][c + dc] != 0)
                        {
                            neighbors++;
                        }
                    }
                }

                next_board[r][c] = neighbors == 3 ? 1 : 0;
            }
        }

        free(board);
        board = next_board;

        generation++;

        // Check if the game is over
        if (board[0][0] == 0)
        {
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}