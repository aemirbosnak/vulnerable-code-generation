//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: innovative
#include <stdio.h>

#define MAX_SIZE 20

void displayBoard(int **board)
{
    for(int r = 0; r < MAX_SIZE; r++)
    {
        for(int c = 0; c < MAX_SIZE; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(int r = 0; r < MAX_SIZE; r++)
    {
        board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board with random values
    for(int r = 0; r < MAX_SIZE; r++)
    {
        for(int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Play the Game of Life for 10 generations
    for(int gen = 0; gen < 10; gen++)
    {
        displayBoard(board);

        // Calculate the next generation
        for(int r = 0; r < MAX_SIZE; r++)
        {
            for(int c = 0; c < MAX_SIZE; c++)
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
    }

    displayBoard(board);

    free(board);

    return 0;
}