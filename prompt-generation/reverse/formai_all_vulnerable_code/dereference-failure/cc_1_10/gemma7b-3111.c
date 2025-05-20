//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void initialize_board(int **board, int size)
{
    board = (int *)malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++)
    {
        board[i] = 0;
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

void calculate_neighbors(int **board, int i, int j, int size)
{
    int neighbors = 0;
    for (int r = -1; r <= 1; r++)
    {
        for (int c = -1; c <= 1; c++)
        {
            if (i + r >= 0 && i + r < size && j + c >= 0 && j + c < size && board[i + r][j + c] == 1)
            {
                neighbors++;
            }
        }
    }

    board[i][j] = neighbors;
}

void game_of_life(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            calculate_neighbors(board, i, j, size);
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] < 2)
            {
                board[i][j] = 0;
            }
            else if (board[i][j] > 3)
            {
                board[i][j] = 0;
            }
            else if (board[i][j] == 2)
            {
                board[i][j] = 1;
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board = NULL;

    initialize_board(board, size);

    // Set up the initial board
    board[0][0] = 1;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 1;
    board[2][2] = 1;

    print_board(board, size);

    game_of_life(board, size);

    print_board(board, size);

    return 0;
}