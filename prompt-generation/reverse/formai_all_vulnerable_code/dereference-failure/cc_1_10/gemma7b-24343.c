//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10

void display_board(int **board)
{
    for(int r = 0; r < MAX_CELLS; r++)
    {
        for(int c = 0; c < MAX_CELLS; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

void update_board(int **board)
{
    for(int r = 0; r < MAX_CELLS; r++)
    {
        for(int c = 0; c < MAX_CELLS; c++)
        {
            int num_alive_neighbors = 0;
            if(board[r-1][c] == 1) num_alive_neighbors++;
            if(board[r+1][c] == 1) num_alive_neighbors++;
            if(board[r][c-1] == 1) num_alive_neighbors++;
            if(board[r][c+1] == 1) num_alive_neighbors++;

            if(board[r][c] == 1 && num_alive_neighbors < 2) board[r][c] = 0;
            else if(board[r][c] == 0 && num_alive_neighbors == 3) board[r][c] = 1;
        }
    }
}

int main()
{
    int **board = (int**)malloc(MAX_CELLS * sizeof(int*));
    for(int r = 0; r < MAX_CELLS; r++) board[r] = (int*)malloc(MAX_CELLS * sizeof(int));

    // Initial game board setup
    board[2][2] = board[3][2] = board[3][3] = 1;

    int generation = 0;
    while(1)
    {
        display_board(board);
        update_board(board);
        generation++;

        if(generation == 10) break;
    }

    display_board(board);
    printf("Game of Life - Generation: %d\n", generation);

    free(board);
    return 0;
}