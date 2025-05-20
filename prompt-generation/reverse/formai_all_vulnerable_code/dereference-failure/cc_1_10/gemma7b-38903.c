//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void draw_board(int **board)
{
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

void update_board(int **board, int x, int y, char symbol)
{
    board[x][y] = symbol;
}

int main()
{
    int **board = malloc(ROWS * sizeof(int *) + ROWS);
    for(int r = 0; r < ROWS; r++)
    {
        board[r] = malloc(COLS * sizeof(int));
    }

    int x = 0, y = 0, direction = 1, speed = 1;
    char symbol = 'O';

    srand(time(NULL));

    draw_board(board);

    while(!board[x][y] && x < COLS)
    {
        update_board(board, x, y, symbol);

        switch(direction)
        {
            case 1:
                x++;
                break;
            case 2:
                y++;
                break;
            case 3:
                x--;
                break;
            case 4:
                y--;
                break;
        }

        update_board(board, x, y, symbol);

        draw_board(board);

        sleep(speed);
    }

    free(board);

    return 0;
}