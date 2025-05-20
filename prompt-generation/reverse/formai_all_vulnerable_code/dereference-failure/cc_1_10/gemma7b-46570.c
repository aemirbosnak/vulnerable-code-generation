//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board)
{
    for(int r = 0; r < 5; r++)
    {
        for(int c = 0; c < 5; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int**)malloc(5 * sizeof(int*));
    for(int r = 0; r < 5; r++)
    {
        board[r] = (int*)malloc(5 * sizeof(int));
    }

    board[2][2] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    draw_board(board);

    int generation = 0;
    while(1)
    {
        draw_board(board);
        printf("Generation: %d\n", generation++);

        // Game of Life rules
        for(int r = 0; r < 5; r++)
        {
            for(int c = 0; c < 5; c++)
            {
                int neighbors = 0;
                if(board[r-1][c] == 1) neighbors++;
                if(board[r+1][c] == 1) neighbors++;
                if(board[r][c-1] == 1) neighbors++;
                if(board[r][c+1] == 1) neighbors++;

                if(board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if(board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        // Check if the game is over
        if(board[0][0] == 0 && board[0][4] == 0) break;

    }

    return 0;
}