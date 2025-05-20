//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void initialize_board(int **board, int size)
{
    board = (int *)malloc(size * size * sizeof(int));
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }
}

void print_board(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

int get_neighbor_count(int **board, int r, int c)
{
    int count = 0;
    for (int dr = -1; dr <= 1; dr++)
    {
        for (int dc = -1; dc <= 1; dc++)
        {
            if (board[r + dr][c + dc] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

void simulate_game(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int neighbors = get_neighbor_count(board, r, c);
            if (neighbors == 3)
            {
                board[r][c] = 1;
            }
            else if (neighbors == 2)
            {
                board[r][c] = 0;
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board;
    initialize_board(board, size);

    // Randomly initialize some cells
    board[1][1] = 1;
    board[2][2] = 1;
    board[3][3] = 1;

    print_board(board, size);

    simulate_game(board, size);

    print_board(board, size);

    return 0;
}