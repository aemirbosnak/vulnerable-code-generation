//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void initialize_board(int **board, int size)
{
    board = (int *)malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++)
    {
        board[i] = 0;
    }
}

int get_neighbor_count(int **board, int x, int y)
{
    int count = 0;
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (x + dx >= 0 && x + dx < MAX_SIZE && y + dy >= 0 && y + dy < MAX_SIZE && board[x + dx][y + dy] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

void update_board(int **board, int size)
{
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            int neighbor_count = get_neighbor_count(board, x, y);
            if (neighbor_count < 2 || neighbor_count > 3)
            {
                board[x][y] = 0;
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board;
    initialize_board(board, size);

    // Seed the random number generator
    srand(time(NULL));

    // Create random patterns on the board
    for (int i = 0; i < 10; i++)
    {
        board[rand() % size][rand() % size] = 1;
    }

    // Simulate game of life for 10 generations
    for (int generation = 0; generation < 10; generation++)
    {
        update_board(board, size);
    }

    // Print the final board
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            printf("%d ", board[x][y]);
        }
        printf("\n");
    }

    return 0;
}