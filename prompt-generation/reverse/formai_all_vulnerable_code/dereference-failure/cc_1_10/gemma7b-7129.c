//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%c ", board[i][j] == 0 ? '.' : 'O');
        }
        printf("\n");
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    // Initial board setup
    board[2][2] = board[1][2] = board[2][1] = 1;

    // Game loop
    int generation = 0;
    while(1)
    {
        draw_board(board, size);
        printf("Generation: %d\n", generation++);

        // Calculate next generation
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                int neighbors = 0;
                // Check neighbors
                if(board[i-1][j] == 1) neighbors++;
                if(board[i+1][j] == 1) neighbors++;
                if(board[i][j-1] == 1) neighbors++;
                if(board[i][j+1] == 1) neighbors++;

                // Apply rules
                if(board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
                if(board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            }
        }

        // Check if game is over
        if(board[size-1][size-1] == 1)
        {
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}