//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

#define BALL_SIZE 10

void draw_board(int **board)
{
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            printf("%c ", board[r][c] ? '*' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = NULL;
    board = malloc(HEIGHT * sizeof(int *));
    for (int r = 0; r < HEIGHT; r++)
    {
        board[r] = malloc(WIDTH * sizeof(int));
    }

    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT - 1;

    int direction = 1;

    while (1)
    {
        draw_board(board);

        switch (direction)
        {
            case 1:
                ball_x++;
                break;
            case 2:
                ball_x--;
                break;
            case 3:
                ball_y--;
                break;
            case 4:
                ball_y++;
                break;
        }

        if (board[ball_y][ball_x] == 1)
        {
            direction = 0;
        }

        if (ball_x == WIDTH - 1)
        {
            direction = 2;
        }
        else if (ball_x == 0)
        {
            direction = 1;
        }
        else if (ball_y == 0)
        {
            direction = 4;
        }

        sleep(0.1);
    }

    free(board);

    return 0;
}