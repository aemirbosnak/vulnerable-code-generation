//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void draw_board(int **board)
{
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            printf("%c ", board[r][c] ? '*' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for(int r = 0; r < MAX; r++)
    {
        board[r] = (int *)malloc(MAX * sizeof(int));
    }

    int generation = 0;

    // Game loop
    while(1)
    {
        // Create the next generation
        int **next_board = (int **)malloc(MAX * sizeof(int *));
        for(int r = 0; r < MAX; r++)
        {
            next_board[r] = (int *)malloc(MAX * sizeof(int));
        }

        for(int r = 0; r < MAX; r++)
        {
            for(int c = 0; c < MAX; c++)
            {
                int neighbors = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(board[r + dr][c + dc] && board[r + dr][c + dc] != -1)
                        {
                            neighbors++;
                        }
                    }
                }

                next_board[r][c] = (neighbors == 2 || neighbors == 3) ? 1 : -1;
            }
        }

        // Free the previous generation
        for(int r = 0; r < MAX; r++)
        {
            free(board[r]);
        }
        free(board);

        // Update the board
        board = next_board;

        draw_board(board);

        // Increment the generation
        generation++;

        // Check if the game is over
        if(generation >= 10)
        {
            break;
        }
    }

    return 0;
}