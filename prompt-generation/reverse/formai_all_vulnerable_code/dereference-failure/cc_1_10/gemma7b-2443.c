//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void drawBoard(int **board)
{
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int**)malloc(MAX * sizeof(int*));
    for(int r = 0; r < MAX; r++)
    {
        board[r] = (int*)malloc(MAX * sizeof(int));
    }

    // Initial board setup
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    int generations = 0;

    // Game loop
    while(1)
    {
        drawBoard(board);
        printf("Generation: %d\n", generations);

        // Calculate next generation
        int **nextBoard = (int**)malloc(MAX * sizeof(int*));
        for(int r = 0; r < MAX; r++)
        {
            nextBoard[r] = (int*)malloc(MAX * sizeof(int));
        }

        for(int r = 0; r < MAX; r++)
        {
            for(int c = 0; c < MAX; c++)
            {
                nextBoard[r][c] = calculateCell(board, r, c);
            }
        }

        free(board);
        board = nextBoard;
        generations++;

        // Check if game is over
        if(board[0][0] == 0 && board[MAX - 1][MAX - 1] == 0)
        {
            drawBoard(board);
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}

int calculateCell(int **board, int r, int c)
{
    int aliveNeighbors = 0;

    // Check neighbors
    for(int dr = -1; dr <= 1; dr++)
    {
        for(int dc = -1; dc <= 1; dc++)
        {
            if(board[r + dr][c + dc] && board[r + dr][c + dc] != -1)
            {
                aliveNeighbors++;
            }
        }
    }

    // Apply Game of Life rules
    if(board[r][c] == 1 && aliveNeighbors < 2)
    {
        return -1;
    }
    else if(board[r][c] == 0 && aliveNeighbors == 3)
    {
        return 1;
    }

    return board[r][c];
}