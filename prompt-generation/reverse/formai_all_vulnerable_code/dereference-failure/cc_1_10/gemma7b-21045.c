//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *)), i;

    for (i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    board[2][2] = board[2][3] = board[3][2] = 1;

    draw_board(board, size);

    for (int t = 0; t < 5; t++)
    {
        for (i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int neighbors = 0;

                if (i > 0) neighbors++;
                if (i < size - 1) neighbors++;
                if (j > 0) neighbors++;
                if (j < size - 1) neighbors++;

                if (board[i][j] && neighbors < 2) board[i][j] = 0;
                else if (!board[i][j] && neighbors == 3) board[i][j] = 1;
            }
        }

        draw_board(board, size);
    }

    free(board);

    return 0;
}