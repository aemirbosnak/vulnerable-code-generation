//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 20

#define LEFT_BOUND 0
#define RIGHT_BOUND MAX_WIDTH - 1

void draw_board(int **board)
{
    for (int y = 0; y < MAX_HEIGHT; y++)
    {
        for (int x = 0; x < MAX_WIDTH; x++)
        {
            printf("%c ", board[y][x] ? '*' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = malloc(MAX_HEIGHT * sizeof(int *));
    for (int y = 0; y < MAX_HEIGHT; y++)
    {
        board[y] = malloc(MAX_WIDTH * sizeof(int));
    }

    int invaders_x = RIGHT_BOUND;
    int invaders_y = 0;
    int direction = 1;

    while (!board[invaders_y][invaders_x])
    {
        draw_board(board);

        if (direction == 1)
        {
            invaders_x++;
            if (invaders_x >= RIGHT_BOUND)
            {
                direction = -1;
            }
        }
        else
        {
            invaders_x--;
            if (invaders_x <= LEFT_BOUND)
            {
                direction = 1;
            }
        }

        invaders_y++;

        sleep(1);
    }

    draw_board(board);
    printf("Game Over!\n");

    free(board);
    return 0;
}