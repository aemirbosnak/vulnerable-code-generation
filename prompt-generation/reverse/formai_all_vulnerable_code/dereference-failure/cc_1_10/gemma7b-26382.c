//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void initialize_board(int **board)
{
    int i, j;
    for(i = 0; i < MAX_SIZE; i++)
    {
        for(j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }
}

void print_board(int **board)
{
    int i, j;
    for(i = 0; i < MAX_SIZE; i++)
    {
        for(j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void calculate_next_state(int **board)
{
    int i, j, count;
    for(i = 0; i < MAX_SIZE; i++)
    {
        for(j = 0; j < MAX_SIZE; j++)
        {
            count = 0;
            if(board[i-1][j] == 1) count++;
            if(board[i+1][j] == 1) count++;
            if(board[i][j-1] == 1) count++;
            if(board[i][j+1] == 1) count++;
            if(board[i-1][j-1] == 1) count++;
            if(board[i-1][j+1] == 1) count++;
            if(board[i+1][j-1] == 1) count++;
            if(board[i+1][j+1] == 1) count++;
            if(count < 2) board[i][j] = 0;
            else if(count == 2) board[i][j] = 1;
            else board[i][j] = 0;
        }
    }
}

int main()
{
    int **board = NULL;
    board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    initialize_board(board);
    board[2][2] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    print_board(board);

    calculate_next_state(board);

    print_board(board);

    free(board);

    return 0;
}