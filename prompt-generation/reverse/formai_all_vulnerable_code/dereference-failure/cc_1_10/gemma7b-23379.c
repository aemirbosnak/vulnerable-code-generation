//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 21

#define PADDLE_SIZE 10

#define BALL_SIZE 5

#define BALL_SPEED 2

#define AI_DELAY 100

void draw_board(int **board)
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
    }

    int player_pos = 0;
    int ai_pos = BOARD_SIZE - 1;

    int ball_x = BOARD_SIZE / 2;
    int ball_y = 0;

    int ball_dx = BALL_SPEED;
    int ball_dy = BALL_SPEED;

    time_t start_time = time(NULL);

    while (time(NULL) - start_time < AI_DELAY)
    {
        draw_board(board);
        printf("Player: %d, AI: %d\n", player_pos, ai_pos);

        int move = rand() % 2;

        if (move == 0)
        {
            ai_pos--;
        }
        else
        {
            ai_pos++;
        }

        if (board[ai_pos][ball_x] == '#')
        {
            ball_dy *= -1;
        }

        ball_x += ball_dx;
        ball_y += ball_dy;

        if (ball_x < 0 || ball_x >= BOARD_SIZE)
        {
            ball_dx *= -1;
        }

        if (ball_y < 0)
        {
            ball_dy *= -1;
        }

        if (board[player_pos][ball_x] == '#')
        {
            printf("Game Over!\n");
            break;
        }

        if (board[ai_pos][ball_x] == '#')
        {
            printf("AI Won!\n");
            break;
        }
    }

    draw_board(board);
    printf("Game Over!\n");

    free(board);
    return 0;
}