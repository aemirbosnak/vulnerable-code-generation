//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void initialize_board(int **board);
void print_board(int **board);
void update_board(int **board);

int main()
{
    int **board = NULL;
    int i, j, k;

    board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    initialize_board(board);
    print_board(board);
    update_board(board);
    print_board(board);

    for (k = 0; k < MAX_SIZE; k++)
    {
        free(board[k]);
    }
    free(board);

    return 0;
}

void initialize_board(int **board)
{
    int i, j;

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }
}

void print_board(int **board)
{
    int i, j;

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void update_board(int **board)
{
    int i, j, count, alive = 0;

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            count = 0;
            if (board[i - 1][j] == 1) count++;
            if (board[i + 1][j] == 1) count++;
            if (board[i][j - 1] == 1) count++;
            if (board[i][j + 1] == 1) count++;

            if (board[i][j] == 1 && count < 2) alive = 0;
            if (board[i][j] == 0 && count == 3) alive = 1;

            board[i][j] = alive;
        }
    }
}