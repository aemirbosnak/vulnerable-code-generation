//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void initialize_game(int **board)
{
    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int c = 0; c < MAX_COLS; c++)
        {
            board[r][c] = 0;
        }
    }
}

void print_board(int **board)
{
    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int c = 0; c < MAX_COLS; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

int calculate_neighbor_count(int **board, int r, int c)
{
    int neighbor_count = 0;

    // Check the cell above
    if (r - 1 >= 0)
    {
        neighbor_count++;
    }

    // Check the cell below
    if (r + 1 < MAX_ROWS)
    {
        neighbor_count++;
    }

    // Check the cell to the left
    if (c - 1 >= 0)
    {
        neighbor_count++;
    }

    // Check the cell to the right
    if (c + 1 < MAX_COLS)
    {
        neighbor_count++;
    }

    return neighbor_count;
}

void update_board(int **board)
{
    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int c = 0; c < MAX_COLS; c++)
        {
            int neighbor_count = calculate_neighbor_count(board, r, c);

            if (board[r][c] == 0 && neighbor_count == 3)
            {
                board[r][c] = 1;
            }
            else if (board[r][c] == 1 && (neighbor_count < 2 || neighbor_count > 3))
            {
                board[r][c] = 0;
            }
        }
    }
}

int main()
{
    int **board = (int **)malloc(MAX_ROWS * sizeof(int *));
    for (int r = 0; r < MAX_ROWS; r++)
    {
        board[r] = (int *)malloc(MAX_COLS * sizeof(int));
    }

    initialize_game(board);

    // Seed the random number generator
    srand(time(NULL));

    // Randomly set some cells to 1
    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int c = 0; c < MAX_COLS; c++)
        {
            if (rand() % 2 == 0)
            {
                board[r][c] = 1;
            }
        }
    }

    print_board(board);

    update_board(board);

    print_board(board);

    free(board);

    return 0;
}