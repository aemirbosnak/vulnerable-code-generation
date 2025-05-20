//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void GameOfLife(int **board, int rows, int cols)
{
    int i, j, r, c;
    int **newBoard = malloc(rows * sizeof(int *));
    for(r = 0; r < rows; r++)
    {
        newBoard[r] = malloc(cols * sizeof(int));
    }

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            int neighbors = 0;
            for(r = -1; r <= 1; r++)
            {
                for(c = -1; c <= 1; c++)
                {
                    if(r == 0 && c == 0)
                        continue;
                    if(board[i + r][j + c] == 1)
                        neighbors++;
                }
            }

            if(board[i][j] == 1 && neighbors < 2)
                newBoard[i][j] = 0;
            else if(board[i][j] == 0 && neighbors == 2)
                newBoard[i][j] = 1;
        }
    }

    free(board);
    free(newBoard);
}

int main()
{
    int rows = 5;
    int cols = 5;
    int **board = malloc(rows * sizeof(int *));
    for(int r = 0; r < rows; r++)
    {
        board[r] = malloc(cols * sizeof(int));
    }

    board[1][1] = 1;
    board[2][2] = 1;
    board[2][3] = 1;

    GameOfLife(board, rows, cols);

    for(int r = 0; r < rows; r++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", board[r][j]);
        }
        printf("\n");
    }

    free(board);

    return 0;
}