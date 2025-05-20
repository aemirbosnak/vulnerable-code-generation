//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void game_of_life(int **board)
{
    int i, j, k, l;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            int neighbors = 0;
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (board[i + k][j + l] == 1)
                    {
                        neighbors++;
                    }
                }
            }

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
    int board[MAX][MAX] = {{0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                              {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                              {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                              {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                           };

    game_of_life(board);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}