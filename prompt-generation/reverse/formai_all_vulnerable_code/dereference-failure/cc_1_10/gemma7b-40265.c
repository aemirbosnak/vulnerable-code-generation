//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define LIVE_CELL 1
#define DEAD_CELL 0

void initialize_board(int **board)
{
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            board[r][c] = DEAD_CELL;
        }
    }
}

void print_board(int **board)
{
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

void update_board(int **board)
{
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            int neighbors = 0;
            if (r - 1 >= 0) neighbors++;
            if (r + 1 < HEIGHT) neighbors++;
            if (c - 1 >= 0) neighbors++;
            if (c + 1 < WIDTH) neighbors++;

            if (board[r][c] == LIVE_CELL && neighbors < 2) board[r][c] = DEAD_CELL;
            if (board[r][c] == DEAD_CELL && neighbors == 3) board[r][c] = LIVE_CELL;
        }
    }
}

int main()
{
    int **board = NULL;
    board = (int **)malloc(HEIGHT * sizeof(int *) + HEIGHT);
    for (int r = 0; r < HEIGHT; r++) board[r] = (int *)malloc(WIDTH * sizeof(int) + WIDTH);

    initialize_board(board);

    // Seed the random number generator
    srand(time(NULL));

    // Create a random pattern of live and dead cells
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    print_board(board);

    update_board(board);

    print_board(board);

    free(board);

    return 0;
}