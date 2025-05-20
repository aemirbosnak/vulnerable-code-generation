//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT_BOUND 0
#define RIGHT_BOUND 5

void draw_board(int **board)
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 11; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

void move_invaders(int **board, int direction)
{
    for (int i = 0; i < 11; i++)
    {
        if (board[0][i] != 'I')
            continue;

        switch (direction)
        {
            case 0:
                board[0][i] = ' ';
                board[1][i] = 'I';
                break;
            case 1:
                board[0][i] = ' ';
                board[1][i] = 'I';
                break;
            case 2:
                board[0][i] = ' ';
                board[1][i] = 'I';
                break;
        }
    }
}

int main()
{
    int **board = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        board[i] = (int *)malloc(11 * sizeof(int));
    }

    int direction = 0;
    time_t t = time(NULL);

    // Initialize the board
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 11; c++)
        {
            board[r][c] = ' ';
        }
    }

    // Place the invaders
    board[0][2] = board[0][3] = board[0][4] = 'I';

    // Game loop
    while (!board[4][5] && time(NULL) - t < 60)
    {
        draw_board(board);

        // Move the invaders
        move_invaders(board, direction);

        // Change direction randomly
        if (rand() % 3 == 0)
            direction = (direction + 1) % 3;

        // Sleep
        sleep(0.1);
    }

    draw_board(board);

    // Game over
    printf("Game over!");

    free(board);

    return 0;
}