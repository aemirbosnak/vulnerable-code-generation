//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void play_game(int **board)
{
    int rows = 5;
    int cols = 5;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    printf("Enter the row and column of the cell you want to toggle: ");
    int row, col;
    scanf("%d %d", &row, &col);

    if (board[row][col] == 0)
    {
        board[row][col] = 1;
    }
    else
    {
        board[row][col] = 0;
    }

    play_game(board);
}

int main()
{
    int **board = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        board[i] = (int *)malloc(5 * sizeof(int));
    }

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            board[r][c] = 0;
        }
    }

    play_game(board);

    return 0;
}