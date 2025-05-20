//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_board(int **board, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

void update_board(int **board, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            int neighbors = 0;
            if(r - 1 >= 0) neighbors++;
            if(r + 1 < size) neighbors++;
            if(c - 1 >= 0) neighbors++;
            if(c + 1 < size) neighbors++;

            if(board[r][c] == 'o' && neighbors >= 2) board[r][c] = 'x';
            else if(board[r][c] == 'x' && neighbors < 2) board[r][c] = 'o';
        }
    }
}

int main()
{
    int size = 10;
    int **board = (int**)malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++) board[i] = (int*)malloc(size * sizeof(int));

    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            board[r][c] = '.';
        }
    }

    board[5][5] = 'o';
    board[5][6] = 'o';
    board[6][5] = 'o';
    board[6][6] = 'o';

    int game_round = 0;
    while(game_round < 10)
    {
        draw_board(board, size);
        update_board(board, size);
        game_round++;
    }

    draw_board(board, size);

    free(board);

    return 0;
}