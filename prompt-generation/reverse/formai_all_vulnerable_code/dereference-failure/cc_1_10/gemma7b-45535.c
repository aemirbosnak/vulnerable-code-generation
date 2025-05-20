//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void draw_board(int **board)
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
    for(int i = 0; i < MAX; i++)
    {
        board[i] = (int*)malloc(MAX * sizeof(int));
    }

    // Initialize the board
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create a random pattern
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Play the game
    draw_board(board);

    return 0;
}