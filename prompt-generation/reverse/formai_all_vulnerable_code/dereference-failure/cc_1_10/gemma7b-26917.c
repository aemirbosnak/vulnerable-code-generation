//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void initialize_board(int **board, int size)
{
    board = (int **)malloc(size * sizeof(int *));
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

int calculate_neighbors(int **board, int i, int j)
{
    int neighbors = 0;
    if (i > 0)
    {
        neighbors++;
    }
    if (i < MAX_SIZE - 1)
    {
        neighbors++;
    }
    if (j > 0)
    {
        neighbors++;
    }
    if (j < MAX_SIZE - 1)
    {
        neighbors++;
    }
    return neighbors;
}

void update_board(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int neighbors = calculate_neighbors(board, i, j);
            if (neighbors == 3)
            {
                board[i][j] = 1;
            }
            else if (neighbors == 2)
            {
                board[i][j] = 0;
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board;
    initialize_board(board, size);
    board[0][0] = 1;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 1;
    board[1][2] = 1;
    print_board(board, size);
    update_board(board, size);
    print_board(board, size);

    return 0;
}