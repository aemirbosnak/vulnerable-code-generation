//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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
    int size = MAX;
    int **board = (int **)malloc(size * sizeof(int *));
    for(int r = 0; r < size; r++)
    {
        board[r] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Place the initial organisms
    board[5][5] = board[2][4] = board[4][2] = 1;

    // Simulate the game of life
    int generations = 0;
    while(board[size - 1][size - 1] != 1)
    {
        drawBoard(board, size);
        printf("Generation: %d\n", generations);

        // Calculate the number of neighbors for each organism
        for(int r = 0; r < size; r++)
        {
            for(int c = 0; c < size; c++)
            {
                int neighbors = 0;
                if(board[r - 1][c] == 1) neighbors++;
                if(board[r + 1][c] == 1) neighbors++;
                if(board[r][c - 1] == 1) neighbors++;
                if(board[r][c + 1] == 1) neighbors++;

                // Apply the rules of life
                if(board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                else if(board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        // Increment the number of generations
        generations++;
    }

    drawBoard(board, size);
    printf("Generation: %d\n", generations);
    printf("Game Over!\n");

    // Free the memory
    for(int r = 0; r < size; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}