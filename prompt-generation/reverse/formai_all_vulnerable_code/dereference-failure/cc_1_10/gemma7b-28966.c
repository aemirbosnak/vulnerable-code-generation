//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void initialize_board(int **board, int size)
{
    board = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
        for(int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }
}

void print_board(int **board, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void game_of_life(int **board, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            int neighbors = 0;
            if(i > 0) neighbors++;
            if(i < size - 1) neighbors++;
            if(j > 0) neighbors++;
            if(j < size - 1) neighbors++;

            if(board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
            else if(board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
        }
    }
}

int main()
{
    int size = MAX;
    int **board;

    initialize_board(board, size);

    // Set some initial cells to 1
    board[1][1] = 1;
    board[2][2] = 1;
    board[3][3] = 1;

    print_board(board, size);

    game_of_life(board, size);

    print_board(board, size);

    return 0;
}