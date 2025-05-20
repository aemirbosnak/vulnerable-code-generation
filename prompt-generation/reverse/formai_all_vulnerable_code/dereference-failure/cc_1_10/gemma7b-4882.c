//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>

void paranoid_game_of_life(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int alive_neighbors = 0;
            // Paranoid check for neighbors, assuming they're all spies
            if (r - 1 >= 0)
            {
                alive_neighbors++;
                if (board[r - 1][c] == 1)
                {
                    printf("Suspected spy detected at (%d, %d).\n", r - 1, c);
                }
            }
            if (c - 1 >= 0)
            {
                alive_neighbors++;
                if (board[r][c - 1] == 1)
                {
                    printf("Suspected spy detected at (%d, %d).\n", r, c - 1);
                }
            }
            if (r + 1 < size)
            {
                alive_neighbors++;
                if (board[r + 1][c] == 1)
                {
                    printf("Suspected spy detected at (%d, %d).\n", r + 1, c);
                }
            }
            if (c + 1 < size)
            {
                alive_neighbors++;
                if (board[r][c + 1] == 1)
                {
                    printf("Suspected spy detected at (%d, %d).\n", r, c + 1);
                }
            }

            if (board[r][c] == 1 && alive_neighbors < 2)
            {
                printf("Suspected spy eliminated at (%d, %d).\n", r, c);
                board[r][c] = 0;
            }
            else if (board[r][c] == 0 && alive_neighbors == 3)
            {
                printf("New spy detected at (%d, %d).\n", r, c);
                board[r][c] = 1;
            }
        }
    }
}

int main()
{
    int size = 10;
    int **board = malloc(size * size * sizeof(int));
    for (int r = 0; r < size; r++)
    {
        board[r] = malloc(size * sizeof(int));
    }

    // Initial board setup
    board[1][1] = 1;
    board[2][2] = 1;
    board[3][3] = 1;

    paranoid_game_of_life(board, size);

    free(board);

    return 0;
}