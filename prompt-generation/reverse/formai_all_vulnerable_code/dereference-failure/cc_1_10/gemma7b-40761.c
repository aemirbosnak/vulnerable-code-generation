//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void draw_board(int **board)
{
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = NULL;
    board = (int **)malloc(MAX * sizeof(int *));
    for(int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    int seed = time(NULL);
    srand(seed);

    for(int t = 0; t < 10; t++)
    {
        draw_board(board);

        for(int r = 0; r < MAX; r++)
        {
            for(int c = 0; c < MAX; c++)
            {
                int neighbors = 0;
                if(board[r - 1][c] == 'O') neighbors++;
                if(board[r + 1][c] == 'O') neighbors++;
                if(board[r][c - 1] == 'O') neighbors++;
                if(board[r][c + 1] == 'O') neighbors++;

                if(board[r][c] == 'O' && neighbors < 2) board[r][c] = '.';
                else if(board[r][c] == '.' && neighbors == 3) board[r][c] = 'O';
            }
        }

        printf("Generation %d:\n", t + 1);
    }

    draw_board(board);
    free(board);

    return 0;
}