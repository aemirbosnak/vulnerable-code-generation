//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void drawBoard(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] ? '*' : '.');
        }
        printf("\n");
    }
}

void updateBoard(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int neighbours = 0;
            if (r - 1 >= 0) neighbours++;
            if (r + 1 < size) neighbours++;
            if (c - 1 >= 0) neighbours++;
            if (c + 1 < size) neighbours++;

            if (board[r][c] && neighbours < 2) board[r][c] = 0;
            if (!board[r][c] && neighbours == 3) board[r][c] = 1;
        }
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

    board[1][1] = 1;
    board[2][2] = 1;
    board[3][3] = 1;

    int generation = 0;
    while (1)
    {
        drawBoard(board, size);
        updateBoard(board, size);
        generation++;
        if (generation == 10) break;
    }

    drawBoard(board, size);
    printf("Generations: %d\n", generation);

    for (int r = 0; r < size; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}