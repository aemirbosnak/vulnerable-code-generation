//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void print_board(int **board)
{
    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for (int r = 0; r < MAX; r++)
    {
        board[r] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            board[r][c] = 0;
        }
    }

    // Set some cells to 1
    board[5][5] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Simulate the Game of Life
    for (int t = 0; t < 20; t++)
    {
        print_board(board);

        // Calculate the next generation
        for (int r = 0; r < MAX; r++)
        {
            for (int c = 0; c < MAX; c++)
            {
                int num_neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            num_neighbors++;
                        }
                    }
                }

                if (board[r][c] == 1 && num_neighbors < 2)
                {
                    board[r][c] = 0;
                }
                else if (board[r][c] == 0 && num_neighbors == 3)
                {
                    board[r][c] = 1;
                }
            }
        }
    }

    print_board(board);

    // Free the memory
    for (int r = 0; r < MAX; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}