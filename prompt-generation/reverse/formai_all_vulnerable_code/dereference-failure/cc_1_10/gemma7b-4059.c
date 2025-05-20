//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void display(int **board, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

void update(int **board, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            int neighbors = 0;
            for(int dr = -1; dr <= 1; dr++)
            {
                for(int dc = -1; dc <= 1; dc++)
                {
                    if(board[r + dr][c + dc] && board[r + dr][c + dc] != 'O')
                    {
                        neighbors++;
                    }
                }
            }
            if(board[r][c] == 'O' && neighbors < 2)
            {
                board[r][c] = '.';
            }
            else if(board[r][c] == '.' && neighbors == 3)
            {
                board[r][c] = 'O';
            }
        }
    }
}

int main()
{
    int size = MAX;
    int **board = (int**)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++)
    {
        board[i] = (int*)malloc(size * sizeof(int));
    }

    // Initialize the board
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            board[r][c] = '.';
        }
    }

    board[5][5] = board[10][10] = 'O';

    // Game loop
    int generation = 0;
    while(1)
    {
        display(board, size);
        update(board, size);
        generation++;
        if(generation >= 10)
        {
            break;
        }
    }

    display(board, size);

    free(board);

    return 0;
}