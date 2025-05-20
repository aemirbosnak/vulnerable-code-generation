//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void initialize_game(int **board, int size)
{
    board = (int *)malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++)
    {
        board[i] = 0;
    }
}

void play_game(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int num_alive = 0;
            if (r > 0)
            {
                num_alive += board[r - 1][c];
            }
            if (r < size - 1)
            {
                num_alive += board[r + 1][c];
            }
            if (c > 0)
            {
                num_alive += board[r][c - 1];
            }
            if (c < size - 1)
            {
                num_alive += board[r][c + 1];
            }

            if (board[r][c] == 1 && num_alive < 2)
            {
                board[r][c] = 0;
            }
            else if (board[r][c] == 0 && num_alive == 3)
            {
                board[r][c] = 1;
            }
        }
    }
}

int main()
{
    int size = 10;
    int **board;
    initialize_game(board, size);

    board[1][1] = 1;
    board[2][2] = 1;
    board[3][3] = 1;

    play_game(board, size);

    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}