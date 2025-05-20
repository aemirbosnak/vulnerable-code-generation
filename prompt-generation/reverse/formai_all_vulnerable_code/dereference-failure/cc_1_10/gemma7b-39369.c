//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

#define LIFE_CELL 1
#define DEAD_CELL 0

void draw_board(int **board)
{
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            printf("%c ", board[r][c] ? LIFE_CELL : DEAD_CELL);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int**)malloc(ROWS * sizeof(int*));
    for(int r = 0; r < ROWS; r++)
    {
        board[r] = (int*)malloc(COLS * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create a random board
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Simulate life
    int generations = 0;
    while(1)
    {
        draw_board(board);
        printf("Generation: %d\n", generations);

        // Calculate the next generation
        int **next_board = (int**)malloc(ROWS * sizeof(int*));
        for(int r = 0; r < ROWS; r++)
        {
            next_board[r] = (int*)malloc(COLS * sizeof(int));
        }

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                int neighbors = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(board[r + dr][c + dc] == LIFE_CELL)
                        {
                            neighbors++;
                        }
                    }
                }

                next_board[r][c] = (neighbors == 2) ? LIFE_CELL : DEAD_CELL;
            }
        }

        // Free the old board and copy the next generation
        for(int r = 0; r < ROWS; r++)
        {
            free(board[r]);
        }
        free(board);

        board = next_board;
        next_board = NULL;

        // Check if the game is over
        if(board[0][0] == DEAD_CELL)
        {
            printf("Game Over!\n");
            break;
        }

        // Increment the generation counter
        generations++;
    }

    return 0;
}