//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

void display_board(int **board)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void update_board(int **board)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            int num_neighbors = 0;
            if (board[i - 1][j] == 'O') num_neighbors++;
            if (board[i + 1][j] == 'O') num_neighbors++;
            if (board[i][j - 1] == 'O') num_neighbors++;
            if (board[i][j + 1] == 'O') num_neighbors++;

            if (board[i][j] == 'O' && num_neighbors < 2) board[i][j] = 'S';
            else if (board[i][j] == 'S' && num_neighbors >= 2) board[i][j] = 'O';
        }
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    board[0][0] = 'O';
    board[0][1] = 'O';
    board[1][0] = 'O';
    board[1][1] = 'O';
    board[2][2] = 'O';

    display_board(board);
    update_board(board);
    display_board(board);

    free(board);

    return 0;
}