//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board)
{
    for(int r = 0; r < 20; r++)
    {
        for(int c = 0; c < 20; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(20 * sizeof(int *));
    for(int r = 0; r < 20; r++)
    {
        board[r] = (int *)malloc(20 * sizeof(int));
    }

    // Initial board setup
    board[1][1] = 1;
    board[2][2] = 1;
    board[3][3] = 1;
    board[4][4] = 1;
    board[5][5] = 1;

    int generation = 0;
    while(1)
    {
        draw_board(board);
        printf("Generation: %d\n", generation++);

        // Game of Life logic
        for(int r = 0; r < 20; r++)
        {
            for(int c = 0; c < 20; c++)
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
        if(board[0][0] == 0) break;
    }

    draw_board(board);

    printf("Game Over!\n");

    // Free the memory
    for(int r = 0; r < 20; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}