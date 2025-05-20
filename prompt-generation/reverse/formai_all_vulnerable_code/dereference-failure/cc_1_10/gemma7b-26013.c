//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void play_game_of_life(int **board, int rows, int cols)
{
    int i, j, k, l;
    int new_board[rows][cols];

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            new_board[i][j] = 0;
        }
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            k = 0;
            l = 0;
            if (i > 0)
            {
                k++;
            }
            if (i < rows - 1)
            {
                l++;
            }
            if (j > 0)
            {
                k++;
            }
            if (j < cols - 1)
            {
                l++;
            }

            new_board[i][j] = board[i][j] * (k + l) >= 3 ? 1 : 0;
        }
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = new_board[i][j];
        }
    }
}

int main()
{
    int rows, cols;
    int **board;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    board = (int **)malloc(rows * sizeof(int *) + cols * sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        board[i] = (int *)malloc(cols * sizeof(int));
    }

    play_game_of_life(board, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}