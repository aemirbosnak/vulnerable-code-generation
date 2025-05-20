//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

void draw_board(int **board)
{
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(ROW * sizeof(int *));
    for (int r = 0; r < ROW; r++)
    {
        board[r] = (int *)malloc(COL * sizeof(int));
    }

    int direction = 0; // 0: up, 1: right, 2: down, 3: left
    int x = 0;
    int y = 0;

    board[x][y] = 1; // Place the C robot at (0, 0)

    draw_board(board); // Draw the initial board

    for (int t = 0; t < 10; t++)
    {
        switch (direction)
        {
            case 0:
                y--;
                break;
            case 1:
                x++;
                break;
            case 2:
                y++;
                break;
            case 3:
                x--;
                break;
        }

        if (board[x][y] == 2) // Collision with the wall
        {
            direction = (direction + 1) % 4; // Change direction
        }

        board[x][y] = 1; // Move the C robot to the new position

        draw_board(board); // Draw the updated board
    }

    free(board);

    return 0;
}