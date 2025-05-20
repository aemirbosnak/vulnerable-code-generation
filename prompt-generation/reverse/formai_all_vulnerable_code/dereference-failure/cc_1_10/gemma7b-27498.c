//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

#define LEFT_BOUND 0
#define RIGHT_BOUND WIDTH - 1

void draw_board(int **board)
{
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            printf("%c ", board[r][c] ? '*' : ' ');
        }
        printf("\n");
    }
}

int main()
{
    int **board = malloc(HEIGHT * sizeof(int *));
    for (int r = 0; r < HEIGHT; r++)
    {
        board[r] = malloc(WIDTH * sizeof(int));
    }

    // Initialize board
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            board[r][c] = 0;
        }
    }

    // Place invader
    board[1][3] = 1;

    // Game loop
    int game_over = 0;
    while (!game_over)
    {
        // Draw board
        draw_board(board);

        // Get user input
        int move = getchar();

        // Move invader
        switch (move)
        {
            case 'w':
                board[1][3]--;
                break;
            case 's':
                board[1][3]++;
                break;
            case 'a':
                board[1][3] -= 2;
                break;
            case 'd':
                board[1][3] += 2;
                break;
            default:
                break;
        }

        // Check if game is over
        if (board[0][3] || board[HEIGHT - 1][3] || board[1][LEFT_BOUND] || board[1][RIGHT_BOUND])
        {
            game_over = 1;
        }
    }

    // Free memory
    for (int r = 0; r < HEIGHT; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}