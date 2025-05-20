//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void initialize_board(int **board, int size)
{
    board = (int *)malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++)
    {
        board[i] = 0;
    }
}

void print_board(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i * size + j]);
        }
        printf("\n");
    }
}

void game_of_life(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int neighbors = 0;
            if (i > 0) neighbors++;
            if (i < size - 1) neighbors++;
            if (j > 0) neighbors++;
            if (j < size - 1) neighbors++;

            if (board[i * size + j] == 1 && neighbors < 2) board[i * size + j] = 0;
            if (board[i * size + j] == 0 && neighbors == 3) board[i * size + j] = 1;
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board = NULL;

    initialize_board(board, size);
    board[0][0] = 1;
    board[1][1] = 1;
    board[2][2] = 1;

    print_board(board, size);

    game_of_life(board, size);

    print_board(board, size);

    free(board);

    return 0;
}