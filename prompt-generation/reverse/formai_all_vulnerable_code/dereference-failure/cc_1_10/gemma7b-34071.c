//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: genius
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
    int **board = (int **)malloc(size * sizeof(int *));
    for (int r = 0; r < size; r++)
    {
        board[r] = (int *)malloc(size * sizeof(int));
    }

    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    int generations = 0;
    int game_over = 0;

    while (!game_over)
    {
        draw_board(board, size);

        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < size; c++)
            {
                int neighbors = 0;
                if (r > 0) neighbors++;
                if (r < size - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < size - 1) neighbors++;

                if (board[r][c] && neighbors < 2) board[r][c] = 0;
                else if (!board[r][c] && neighbors == 3) board[r][c] = 1;
            }
        }

        generations++;
        if (generations > 10) game_over = 1;
    }

    draw_board(board, size);
    printf("Game over after %d generations!\n", generations);

    for (int r = 0; r < size; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}