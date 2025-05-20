//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board)
{
    for(int r = 0; r < 5; r++)
    {
        for(int c = 0; c < 5; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(5 * sizeof(int *));
    for(int r = 0; r < 5; r++)
    {
        board[r] = (int *)malloc(5 * sizeof(int));
    }

    int game_of_life(int **board);

    board[1][1] = 1;
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;

    game_of_life(board);

    draw_board(board);

    free(board);

    return 0;
}

int game_of_life(int **board)
{
    for(int r = 0; r < 5; r++)
    {
        for(int c = 0; c < 5; c++)
        {
            int num_alive_neighbors = 0;
            if(board[r-1][c] == 1) num_alive_neighbors++;
            if(board[r+1][c] == 1) num_alive_neighbors++;
            if(board[r][c-1] == 1) num_alive_neighbors++;
            if(board[r][c+1] == 1) num_alive_neighbors++;

            if(board[r][c] == 0 && num_alive_neighbors == 3) board[r][c] = 1;
            if(board[r][c] == 1 && (num_alive_neighbors < 2 || num_alive_neighbors > 3)) board[r][c] = 0;
        }
    }

    return 0;
}