//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 10

#define BALL_SIZE 5
#define BALL_SPEED 3

void draw_board(int **board)
{
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

void move_paddle(int **board, int paddle_y, int direction)
{
    if (paddle_y < 0)
    {
        paddle_y = 0;
    }
    else if (paddle_y >= HEIGHT - PADDLE_HEIGHT)
    {
        paddle_y = HEIGHT - PADDLE_HEIGHT - 1;
    }
    else
    {
        paddle_y += direction;
    }

    board[paddle_y][0] = 'P';
}

void move_ball(int **board, int ball_x, int ball_y, int direction)
{
    ball_x += direction * BALL_SPEED;

    if (ball_x < 0)
    {
        direction = -1;
    }
    else if (ball_x >= WIDTH - BALL_SIZE)
    {
        direction = 1;
    }

    board[ball_y][ball_x] = 'B';
}

int main()
{
    int **board = (int**)malloc(HEIGHT * sizeof(int *));
    for (int r = 0; r < HEIGHT; r++)
    {
        board[r] = (int*)malloc(WIDTH * sizeof(int));
    }

    int paddle_y_player = HEIGHT / 2 - PADDLE_HEIGHT / 2;
    int paddle_y_ai = HEIGHT / 2 - PADDLE_HEIGHT / 2;

    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT / 2;

    int direction = 1;

    srand(time(NULL));

    while (1)
    {
        draw_board(board);

        move_paddle(board, paddle_y_player, direction);
        move_ball(board, ball_x, ball_y, direction);

        if (board[ball_y][ball_x] == 'P')
        {
            direction = -1;
            ball_y--;
        }
        else if (board[ball_y][ball_x] == 'A')
        {
            direction = 1;
            ball_y++;
        }

        if (ball_y == 0 || ball_y == HEIGHT - 1)
        {
            draw_board(board);
            printf("Game Over!");
            break;
        }
    }

    free(board);

    return 0;
}