//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdlib.h>
#include <stdio.h>

#define MAX_CELLS 100

void draw_board(int **board)
{
    for (int r = 0; r < MAX_CELLS; r++)
    {
        for (int c = 0; c < MAX_CELLS; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX_CELLS * sizeof(int *));
    for (int r = 0; r < MAX_CELLS; r++)
    {
        board[r] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    // Randomly initialize the board
    for (int r = 0; r < MAX_CELLS; r++)
    {
        for (int c = 0; c < MAX_CELLS; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Simulate the Game of Life
    int generation = 0;
    while (1)
    {
        draw_board(board);
        printf("Generation: %d\n", generation);

        // Calculate the next generation
        int **next_board = (int **)malloc(MAX_CELLS * sizeof(int *));
        for (int r = 0; r < MAX_CELLS; r++)
        {
            next_board[r] = (int *)malloc(MAX_CELLS * sizeof(int));
        }

        for (int r = 0; r < MAX_CELLS; r++)
        {
            for (int c = 0; c < MAX_CELLS; c++)
            {
                int num_neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] && board[r + dr][c + dc] != board[r][c])
                        {
                            num_neighbors++;
                        }
                    }
                }

                next_board[r][c] = (num_neighbors == 3) || (num_neighbors == 2 && board[r][c] == 1);
            }
        }

        free(board);
        board = next_board;
        generation++;

        // Check if the player wants to continue
        char continue_str;
        printf("Continue? (Y/N): ");
        scanf("%c", &continue_str);

        if (continue_str != 'Y')
        {
            break;
        }
    }

    return 0;
}