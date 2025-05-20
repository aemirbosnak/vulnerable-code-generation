//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void draw_board(int **board)
{
    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            printf("%c ", board[r][c] == 0 ? '.' : board[r][c] == 1 ? 'O' : 'X');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    int seed = time(NULL);
    srand(seed);

    // Initialize the board
    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Game loop
    int generation = 0;
    while (1)
    {
        draw_board(board);
        printf("Generation: %d\n", generation++);

        // Calculate the next generation
        int **next_board = (int **)malloc(MAX * sizeof(int *));
        for (int i = 0; i < MAX; i++)
        {
            next_board[i] = (int *)malloc(MAX * sizeof(int));
        }

        for (int r = 0; r < MAX; r++)
        {
            for (int c = 0; c < MAX; c++)
            {
                int alive_neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            alive_neighbors++;
                        }
                    }
                }

                next_board[r][c] = board[r][c] * (alive_neighbors < 2 ? 0 : alive_neighbors > 3 ? 0 : 1);
            }
        }

        free(board);
        board = next_board;
        if (board[0][0] == 0)
        {
            break;
        }
    }

    draw_board(board);
    printf("Game Over!\n");

    free(board);
    return 0;
}