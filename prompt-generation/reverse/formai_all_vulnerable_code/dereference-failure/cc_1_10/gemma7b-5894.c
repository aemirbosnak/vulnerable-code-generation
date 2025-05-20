//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void initialize_board(int **board, int size)
{
    board = (int *)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }
}

void print_board(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int count_alive(int **board, int x, int y)
{
    int alive_neighbors = 0;
    int size = board[0][0];

    // Check the neighbors to the left
    if (x - 1 >= 0)
    {
        alive_neighbors++;
    }

    // Check the neighbors above
    if (y - 1 >= 0)
    {
        alive_neighbors++;
    }

    // Check the neighbors to the right
    if (x + 1 < size)
    {
        alive_neighbors++;
    }

    // Check the neighbors below
    if (y + 1 < size)
    {
        alive_neighbors++;
    }

    return alive_neighbors;
}

void update_board(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int alive_neighbors = count_alive(board, i, j);

            if (alive_neighbors < 2)
            {
                board[i][j] = 0;
            }
            else if (alive_neighbors == 2)
            {
                board[i][j] = 1;
            }
            else if (alive_neighbors > 3)
            {
                board[i][j] = 0;
            }
        }
    }
}

int main()
{
    int size = MAX;
    int **board = NULL;

    initialize_board(&board, size);

    // Initial board setup
    board[0][0] = 1;
    board[1][0] = 1;
    board[2][0] = 1;
    board[3][0] = 1;
    board[0][1] = 1;
    board[1][1] = 1;
    board[2][1] = 1;

    print_board(board, size);

    update_board(board, size);

    print_board(board, size);

    return 0;
}