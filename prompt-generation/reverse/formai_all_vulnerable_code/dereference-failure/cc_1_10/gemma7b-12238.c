//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void print_board(int **board)
{
    for(int r = 0; r < MAX_SIZE; r++)
    {
        for(int c = 0; c < MAX_SIZE; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

void update_board(int **board)
{
    for(int r = 0; r < MAX_SIZE; r++)
    {
        for(int c = 0; c < MAX_SIZE; c++)
        {
            int alive = 0;
            // Check neighbors
            if(board[r-1][c] == 1) alive++;
            if(board[r+1][c] == 1) alive++;
            if(board[r][c-1] == 1) alive++;
            if(board[r][c+1] == 1) alive++;

            // Update cell
            if(board[r][c] == 1 && alive < 2) board[r][c] = 0;
            if(board[r][c] == 0 && alive == 3) board[r][c] = 1;
        }
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(int r = 0; r < MAX_SIZE; r++)
    {
        board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize board
    for(int r = 0; r < MAX_SIZE; r++)
    {
        for(int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = 0;
        }
    }

    board[1][1] = 1;
    board[2][2] = 1;
    board[2][3] = 1;

    // Simulate Game of Life
    int generations = 0;
    while(1)
    {
        print_board(board);
        update_board(board);
        generations++;

        if(generations == 10) break;
    }

    printf("Game of Life finished after %d generations.\n", generations);

    for(int r = 0; r < MAX_SIZE; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}