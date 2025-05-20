//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define LIVING 1
#define DEAD 0

void draw_board(int **board)
{
    for(int r = 0; r < HEIGHT; r++)
    {
        for(int c = 0; c < WIDTH; c++)
        {
            printf("%c ", board[r][c] == LIVING ? 'O' : '.');
        }
        printf("\n");
    }
}

void simulate_life(int **board)
{
    int **new_board = malloc(HEIGHT * sizeof(int *) + HEIGHT);
    for(int r = 0; r < HEIGHT; r++)
    {
        new_board[r] = malloc(WIDTH * sizeof(int) + WIDTH);
    }

    for(int r = 0; r < HEIGHT; r++)
    {
        for(int c = 0; c < WIDTH; c++)
        {
            int neighbors = 0;
            if(r > 0) neighbors++;
            if(r < HEIGHT - 1) neighbors++;
            if(c > 0) neighbors++;
            if(c < WIDTH - 1) neighbors++;

            new_board[r][c] = (board[r][c] == LIVING && neighbors >= 2) || neighbors == 3 ? LIVING : DEAD;
        }
    }

    free(board);
    board = new_board;
}

int main()
{
    int **board = malloc(HEIGHT * sizeof(int *) + HEIGHT);
    for(int r = 0; r < HEIGHT; r++)
    {
        board[r] = malloc(WIDTH * sizeof(int) + WIDTH);
    }

    // Initial board setup
    board[5][5] = LIVING;
    board[5][6] = LIVING;
    board[6][5] = LIVING;
    board[6][6] = LIVING;

    // Simulation loop
    for(int t = 0; t < 10; t++)
    {
        simulate_life(board);
        draw_board(board);
        sleep(1);
    }

    free(board);
    return 0;
}