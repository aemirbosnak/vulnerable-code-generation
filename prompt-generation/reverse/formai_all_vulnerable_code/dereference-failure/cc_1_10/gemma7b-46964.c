//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define DIM 20

void draw_board(int **board)
{
    for(int r = 0; r < DIM; r++)
    {
        for(int c = 0; c < DIM; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(DIM * sizeof(int *));
    for(int r = 0; r < DIM; r++)
    {
        board[r] = (int *)malloc(DIM * sizeof(int));
    }

    // Initial board setup
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Game loop
    int generation = 0;
    while(1)
    {
        draw_board(board);
        printf("Generation: %d\n", generation++);

        // Calculate next generation
        for(int r = 0; r < DIM; r++)
        {
            for(int c = 0; c < DIM; c++)
            {
                int neighbors = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(board[r + dr][c + dc] && board[r + dr][c + dc] != 0)
                        {
                            neighbors++;
                        }
                    }
                }

                if(board[r][c] == 0 && neighbors == 3)
                {
                    board[r][c] = 1;
                }
                else if(board[r][c] == 1 && (neighbors < 2 || neighbors > 3))
                {
                    board[r][c] = 0;
                }
            }
        }

        // Check if the game is over
        if(board[0][0] == 1)
        {
            draw_board(board);
            printf("Game Over!\n");
            break;
        }
    }

    free(board);
    return 0;
}