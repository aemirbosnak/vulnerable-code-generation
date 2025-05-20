//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void draw_board(int **board)
{
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(ROWS * sizeof(int *));
    for(int r = 0; r < ROWS; r++)
    {
        board[r] = (int *)malloc(COLS * sizeof(int));
    }

    int water_pos = 0;
    board[0][0] = 1;

    int num_drops = 0;
    while(!board[ROWS - 1][COLS - 1])
    {
        num_drops++;
        int x = rand() % COLS;
        int y = rand() % ROWS;

        if(board[y][x] == 0)
        {
            board[y][x] = 1;
            water_pos++;
        }
    }

    draw_board(board);

    printf("Number of drops: %d\n", num_drops);
    printf("Water positions: %d\n", water_pos);

    for(int r = 0; r < ROWS; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}