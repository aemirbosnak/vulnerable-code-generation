//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

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
            printf("%d ", board[i * size + j]);
        }
        printf("\n");
    }
}

int count_neighbors(int **board, int i, int j, int size)
{
    int neighbors = 0;
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if (x == 0 && y == 0)
            {
                continue;
            }
            if (board[i + x][j + y] == 1)
            {
                neighbors++;
            }
        }
    }
    return neighbors;
}

void simulate_game(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int neighbors = count_neighbors(board, i, j, size);
            if (neighbors < 2)
            {
                board[i][j] = 0;
            }
            else if (neighbors == 2)
            {
                board[i][j] = 1;
            }
            else if (neighbors > 3)
            {
                board[i][j] = 0;
            }
        }
    }
}

int main()
{
    int size = MAX;
    int **board;

    initialize_board(board, size);

    board[0][0] = 1;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 1;
    board[2][0] = 1;

    print_board(board, size);

    simulate_game(board, size);

    print_board(board, size);

    return 0;
}