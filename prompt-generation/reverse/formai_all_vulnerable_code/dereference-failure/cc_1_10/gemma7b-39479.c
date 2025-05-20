//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void print_board(int **board)
{
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

void update_board(int **board)
{
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            int num_alive = 0;
            // Check the 8 neighboring cells
            if(board[r-1][c] == 1) num_alive++;
            if(board[r+1][c] == 1) num_alive++;
            if(board[r][c-1] == 1) num_alive++;
            if(board[r][c+1] == 1) num_alive++;
            if(board[r-1][c-1] == 1) num_alive++;
            if(board[r-1][c+1] == 1) num_alive++;
            if(board[r+1][c-1] == 1) num_alive++;
            if(board[r+1][c+1] == 1) num_alive++;

            // Apply the Game of Life rules
            if(board[r][c] == 1 && num_alive < 2) board[r][c] = 0;
            if(board[r][c] == 0 && num_alive == 3) board[r][c] = 1;
        }
    }
}

int main()
{
    int **board = (int**)malloc(MAX * sizeof(int*));
    for(int i = 0; i < MAX; i++)
    {
        board[i] = (int*)malloc(MAX * sizeof(int));
    }

    // Initialize the board
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            board[r][c] = 0;
        }
    }

    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Play the Game of Life
    for(int t = 0; t < 10; t++)
    {
        update_board(board);
        print_board(board);
    }

    free(board);

    return 0;
}