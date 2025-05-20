//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define Bingo Card Size
#define ROWS 5
#define COLS 5

// Define Bingo Card Number Generator
#define MAX_NUMBER 90

// Define Bingo Card Mark
#define MARK 'X'

// Function to Generate Bingo Card
void generateBingoCard(int **card, int rows, int cols)
{
    srand(time(NULL));
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            card[r][c] = rand() % MAX_NUMBER + 1;
        }
    }
}

// Function to Mark Bingo Card
void markBingoCard(int **card, int number)
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (card[r][c] == number)
            {
                card[r][c] = MARK;
            }
        }
    }
}

// Function to Check Bingo
int checkBingo(int **card)
{
    // Check Rows
    for (int r = 0; r < ROWS; r++)
    {
        if (card[r][0] == MARK && card[r][1] == MARK && card[r][2] == MARK && card[r][3] == MARK && card[r][4] == MARK)
        {
            return 1;
        }
    }

    // Check Columns
    for (int c = 0; c < COLS; c++)
    {
        if (card[0][c] == MARK && card[1][c] == MARK && card[2][c] == MARK && card[3][c] == MARK && card[4][c] == MARK)
        {
            return 1;
        }
    }

    // Check diagonals
    if (card[0][0] == MARK && card[1][1] == MARK && card[2][2] == MARK && card[3][3] == MARK && card[4][4] == MARK)
    {
        return 1;
    }

    return 0;
}

int main()
{
    // Create Bingo Card
    int **bingoCard = (int **)malloc(ROWS * sizeof(int *));
    for (int r = 0; r < ROWS; r++)
    {
        bingoCard[r] = (int *)malloc(COLS * sizeof(int));
    }

    // Generate Bingo Card
    generateBingoCard(bingoCard, ROWS, COLS);

    // Mark Bingo Card
    markBingoCard(bingoCard, 22);

    // Check Bingo
    if (checkBingo(bingoCard))
    {
        printf("Bingo!");
    }

    // Free Memory
    for (int r = 0; r < ROWS; r++)
    {
        free(bingoCard[r]);
    }
    free(bingoCard);

    return 0;
}