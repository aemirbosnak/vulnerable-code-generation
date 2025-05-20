//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 10

#define BALL_SIZE 5

void draw_board(int **board)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%c ", board[y][x] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(HEIGHT * sizeof(int *));
    for (int y = 0; y < HEIGHT; y++)
    {
        board[y] = (int *)malloc(WIDTH * sizeof(int));
    }

    int paddle_x = WIDTH / 2 - PADDLE_WIDTH / 2;
    int paddle_y = HEIGHT - PADDLE_HEIGHT - 1;

    int ball_x = WIDTH / 2 - BALL_SIZE / 2;
    int ball_y = HEIGHT - BALL_SIZE - 1;

    int direction = 1;

    time_t start = time(NULL);
    while (!board[ball_y][ball_x] && time(NULL) - start < 60)
    {
        draw_board(board);

        // Ball movement
        ball_x += direction * 2;
        if (ball_x >= WIDTH - BALL_SIZE || ball_x <= 0)
        {
            direction *= -1;
        }

        // Paddle movement
        if (ball_y == paddle_y)
        {
            if (ball_x < paddle_x)
            {
                paddle_x--;
            }
            else if (ball_x > paddle_x)
            {
                paddle_x++;
            }
        }

        // Update board
        board[ball_y][ball_x] = 1;

        sleep(0.1);
    }

    draw_board(board);
    printf("Game Over!");

    free(board);

    return 0;
}