//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void display(int **board, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

void calculate(int **board, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            int neighbors = 0;
            if(r > 0) neighbors++;
            if(r < size - 1) neighbors++;
            if(c > 0) neighbors++;
            if(c < size - 1) neighbors++;

            if(board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
            if(board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++) board[i] = (int *)malloc(size * sizeof(int));

    // Initialize the board
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }

    // Set some initial cells to 1
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Simulate Game of Life for 10 generations
    for(int gen = 0; gen < 10; gen++)
    {
        calculate(board, size);
        display(board, size);
    }

    // Free memory
    for(int i = 0; i < size; i++) free(board[i]);
    free(board);

    return 0;
}