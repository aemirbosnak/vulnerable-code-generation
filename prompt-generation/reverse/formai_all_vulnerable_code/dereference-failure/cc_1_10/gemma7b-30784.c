//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 21
#define WIDTH 40

void draw(int **board, int x, int y)
{
    if (board[x][y] == 1)
    {
        printf("o ");
    }
    else
    {
        printf(". ");
    }
}

int main()
{
    int board[HEIGHT][WIDTH] = {{0}};
    int x_paddle = 10, y_paddle = HEIGHT / 2, x_ball = WIDTH / 2, y_ball = HEIGHT - 1;
    int direction = 1, score = 0, ai_score = 0;

    // AI opponent logic
    int ai_direction = 1, ai_x_paddle = WIDTH / 2, ai_y_paddle = HEIGHT / 2;

    // Game loop
    while (score < 5 && ai_score < 5)
    {
        // Draw the board
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                draw(board, x, y);
            }

            printf("\n");
        }

        // Move the ball
        x_ball += direction;

        // If the ball hits the paddle, change direction
        if (board[x_paddle][y_paddle] == 1)
        {
            direction *= -1;
        }

        // If the ball hits the wall, increment score
        if (x_ball == WIDTH - 1)
        {
            score++;
            direction = -1;
        }

        // AI move
        ai_direction = rand() % 2;
        if (ai_direction == 0)
        {
            ai_x_paddle--;
        }
        else
        {
            ai_x_paddle++;
        }

        // If the AI paddle hits the wall, increment AI score
        if (board[ai_x_paddle][ai_y_paddle] == 1)
        {
            ai_score++;
            ai_direction *= -1;
        }

        // Update the board
        board[x_ball][y_ball] = 1;
        board[x_paddle][y_paddle] = 1;
        board[ai_x_paddle][ai_y_paddle] = 1;

        // Sleep
        sleep(0.1);
    }

    // End game
    printf("Game over! Score: %d, AI Score: %d", score, ai_score);

    return 0;
}