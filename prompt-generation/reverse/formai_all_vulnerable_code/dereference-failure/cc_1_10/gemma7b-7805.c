//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void drawBoard(int **board, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
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
    for(int r = 0; r < size; r++)
    {
        board[r] = (int *)malloc(size * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Initial state of the board
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    // Game loop
    int generation = 0;
    while(1)
    {
        drawBoard(board, size);
        printf("Generation: %d\n", generation);

        // Calculate the next generation
        int **nextBoard = (int **)malloc(size * sizeof(int *));
        for(int r = 0; r < size; r++)
        {
            nextBoard[r] = (int *)malloc(size * sizeof(int));
        }

        for(int r = 0; r < size; r++)
        {
            for(int c = 0; c < size; c++)
            {
                int alive = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(board[r + dr][c + dc] && board[r + dr][c + dc] != 0)
                        {
                            alive++;
                        }
                    }
                }

                nextBoard[r][c] = alive == 3 ? 1 : 0;
            }
        }

        free(board);
        board = nextBoard;
        generation++;

        // Check if the game is over
        if(board[0][0] == 1)
        {
            drawBoard(board, size);
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}