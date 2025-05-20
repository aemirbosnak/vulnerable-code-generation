//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

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

int count_neighbors(int **board, int i, int j)
{
    int neighbors = 0;
    int r, c;

    for (r = -1; r <= 1; r++)
    {
        for (c = -1; c <= 1; c++)
        {
            if (board[i + r][j + c] && board[i + r][j + c] != 0)
            {
                neighbors++;
            }
        }
    }

    return neighbors;
}

void update_board(int **board)
{
    int i, j;
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            int neighbors = count_neighbors(board, i, j);

            if (board[i][j] == 0 && neighbors == 3)
            {
                board[i][j] = 1;
            }
            else if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3))
            {
                board[i][j] = 0;
            }
        }
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * MAX_SIZE * sizeof(int));

    initialize_board(board);

    // Initial board setup
    board[0][0] = 1;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 1;

    print_board(board);

    update_board(board);

    print_board(board);

    free(board);

    return 0;
}