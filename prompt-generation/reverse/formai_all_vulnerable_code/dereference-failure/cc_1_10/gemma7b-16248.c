//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 5

int main()
{
    int board[NUM_ROWS][NUM_COLS] = {{0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 1},
                              {0, 0, 0, 0, 0}};

    int num_calls = 0;
    char called_numbers[NUM_ROWS][NUM_COLS] = {{0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0}};

    // Seed the random number generator
    srand(time(NULL));

    // Call the numbers
    while (!won(board, called_numbers))
    {
        int number = rand() % 25 + 1;

        // Mark the number as called
        called_numbers[number / NUM_COLS][number % NUM_COLS] = 1;

        // Print the number
        printf("%d ", number);

        num_calls++;
    }

    // Print the winner
    printf("\nWinner!");

    return 0;
}

int won(int **board, char **called_numbers)
{
    // Check for rows
    for (int r = 0; r < NUM_ROWS; r++)
    {
        for (int c = 0; c < NUM_COLS; c++)
        {
            if (board[r][c] == 1 && called_numbers[r][c] == 1)
            {
                return 1;
            }
        }
    }

    // Check for columns
    for (int c = 0; c < NUM_COLS; c++)
    {
        for (int r = 0; r < NUM_ROWS; r++)
        {
            if (board[r][c] == 1 && called_numbers[r][c] == 1)
            {
                return 1;
            }
        }
    }

    // Check for diagonals
    if (board[0][0] == 1 && called_numbers[0][0] == 1)
    {
        return 1;
    }

    if (board[0][NUM_COLS - 1] == 1 && called_numbers[0][NUM_COLS - 1] == 1)
    {
        return 1;
    }

    return 0;
}