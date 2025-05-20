//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board, int size)
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

int main()
{
    int size = 10;
    int **board = (int**)malloc(size * sizeof(int*));
    for(int r = 0; r < size; r++)
    {
        board[r] = (int*)malloc(size * sizeof(int));
    }

    // Initialize the board
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }

    // Set some initial cells to 'O'
    board[2][2] = board[3][2] = board[3][3] = 1;

    // Game loop
    int generation = 0;
    while(1)
    {
        draw_board(board, size);
        printf("Generation: %d\n", generation++);

        // Calculate the next generation
        for(int r = 0; r < size; r++)
        {
            for(int c = 0; c < size; c++)
            {
                int neighbors = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(board[r + dr][c + dc] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                if(board[r][c] == 1 && neighbors < 2)
                {
                    board[r][c] = 0;
                }
                else if(board[r][c] == 0 && neighbors == 3)
                {
                    board[r][c] = 1;
                }
            }
        }

        // Check if the game is over
        if(board[size - 1][size - 1] == 1)
        {
            draw_board(board, size);
            printf("Game Over!\n");
            break;
        }
    }

    // Free the memory
    for(int r = 0; r < size; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}