//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void initialize_board(int **board, int size);
void print_board(int **board, int size);
void calculate_next_generation(int **board, int size);

int main()
{
    int size = MAX_SIZE;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    initialize_board(board, size);
    print_board(board, size);

    calculate_next_generation(board, size);
    print_board(board, size);

    free(board);

    return 0;
}

void initialize_board(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void calculate_next_generation(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0)
                    {
                        continue;
                    }
                    if (board[i + x][j + y] == 1)
                    {
                        neighbors++;
                    }
                }
            }

            if (board[i][j] == 1 && neighbors < 2)
            {
                board[i][j] = 0;
            }
            else if (board[i][j] == 0 && neighbors == 3)
            {
                board[i][j] = 1;
            }
        }
    }
}