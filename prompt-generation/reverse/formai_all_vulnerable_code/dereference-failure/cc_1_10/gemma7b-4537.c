//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

void initializeBingoCard(int **card, int rows, int cols)
{
    *card = malloc(rows * cols * sizeof(int));
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            card[r][c] = 0;
        }
    }
}

void markBingoCard(int **card, int num)
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (card[r][c] == num)
            {
                card[r][c] = -1;
            }
        }
    }
}

int checkBingo(int **card)
{
    // Horizontal win
    for (int r = 0; r < 5; r++)
    {
        if (card[r][0] == -1 && card[r][1] == -1 && card[r][2] == -1 && card[r][3] == -1 && card[r][4] == -1)
        {
            return 1;
        }
    }

    // Vertical win
    for (int c = 0; c < 5; c++)
    {
        if (card[0][c] == -1 && card[1][c] == -1 && card[2][c] == -1 && card[3][c] == -1 && card[4][c] == -1)
        {
            return 1;
        }
    }

    // Diagonal win
    if (card[0][0] == -1 && card[1][1] == -1 && card[2][2] == -1 && card[3][3] == -1 && card[4][4] == -1)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int **bingoCard = NULL;
    initializeBingoCard(&bingoCard, 5, 5);

    // Generate numbers for bingo
    int num = 1;
    for (int i = 0; i < 25; i++)
    {
        markBingoCard(bingoCard, num);
        num++;
    }

    // Check if there is a winner
    if (checkBingo(bingoCard))
    {
        printf("Winner!");
    }
    else
    {
        printf("No winner");
    }

    return 0;
}