//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdlib.h>
#include <stdio.h>

void GameOfLife(int ***board, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            int alive = 0;
            for(int dr = -1; dr <= 1; dr++)
            {
                for(int dc = -1; dc <= 1; dc++)
                {
                    if(r + dr >= 0 && r + dr < size && c + dc >= 0 && c + dc < size && board[r + dr][c + dc] == 1)
                    {
                        alive++;
                    }
                }
            }

            if(board[r][c] == 1 && alive < 2)
            {
                board[r][c] = 0;
            }
            else if(board[r][c] == 0 && alive == 3)
            {
                board[r][c] = 1;
            }
        }
    }
}

int main()
{
    int size = 10;
    int ***board = malloc(size * sizeof(int **));
    for(int r = 0; r < size; r++)
    {
        board[r] = malloc(size * sizeof(int *));
        for(int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }

    board[1][1] = 1;
    board[2][2] = 1;
    board[3][2] = 1;
    board[4][3] = 1;

    GameOfLife(board, size);

    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}