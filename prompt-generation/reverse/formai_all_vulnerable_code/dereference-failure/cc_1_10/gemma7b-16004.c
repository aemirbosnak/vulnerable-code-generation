//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void display_board(int **board)
{
    for(int r = 0; r < MAX_SIZE; r++)
    {
        for(int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(int r = 0; r < MAX_SIZE; r++)
    {
        board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for(int r = 0; r < MAX_SIZE; r++)
    {
        for(int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = 0;
        }
    }

    // Place some creatures
    board[5][5] = 1;
    board[2][2] = 2;
    board[3][3] = 3;

    // Game loop
    int generation = 0;
    while(1)
    {
        display_board(board);
        printf("Generation: %d\n", generation);

        // Calculate the next generation
        int **next_board = (int **)malloc(MAX_SIZE * sizeof(int *));
        for(int r = 0; r < MAX_SIZE; r++)
        {
            next_board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
        }

        for(int r = 0; r < MAX_SIZE; r++)
        {
            for(int c = 0; c < MAX_SIZE; c++)
            {
                int num_alive = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(board[r + dr][c + dc] == 1)
                        {
                            num_alive++;
                        }
                    }
                }

                next_board[r][c] = (num_alive == 2) || (num_alive == 3);
            }
        }

        // Free the previous board
        for(int r = 0; r < MAX_SIZE; r++)
        {
            free(board[r]);
        }
        free(board);

        // Update the board
        board = next_board;
        generation++;

        // Check if the game is over
        if(board[0][0] == 0)
        {
            break;
        }
    }

    return 0;
}