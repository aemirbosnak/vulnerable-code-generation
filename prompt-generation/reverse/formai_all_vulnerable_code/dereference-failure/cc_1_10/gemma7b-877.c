//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 9

void generateBingoCard(int **card, int numPlayers);
void printBingoCard(int **card);
int checkBingo(int **card);

int main()
{
    int numPlayers = 2;
    int **bingoCards = NULL;

    // Allocate memory for bingo cards
    bingoCards = (int **)malloc(numPlayers * sizeof(int *));
    for (int i = 0; i < numPlayers; i++)
    {
        bingoCards[i] = (int *)malloc(MAX_NUM * sizeof(int));
    }

    // Generate bingo cards
    generateBingoCard(bingoCards, numPlayers);

    // Print bingo cards
    for (int i = 0; i < numPlayers; i++)
    {
        printBingoCard(bingoCards[i]);
    }

    // Check for bingo
    for (int i = 0; i < numPlayers; i++)
    {
        if (checkBingo(bingoCards[i]) == 1)
        {
            printf("Player %d has won!", i + 1);
            break;
        }
    }

    // Free memory
    for (int i = 0; i < numPlayers; i++)
    {
        free(bingoCards[i]);
    }
    free(bingoCards);

    return 0;
}

void generateBingoCard(int **card, int numPlayers)
{
    for (int i = 0; i < numPlayers; i++)
    {
        for (int j = 0; j < MAX_NUM; j++)
        {
            card[i][j] = rand() % MAX_NUM + 1;
        }
    }
}

void printBingoCard(int **card)
{
    for (int i = 0; i < MAX_NUM; i++)
    {
        for (int j = 0; j < MAX_NUM; j++)
        {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int checkBingo(int **card)
{
    for (int i = 0; i < MAX_NUM; i++)
    {
        // Check rows
        for (int j = 0; j < MAX_NUM; j++)
        {
            if (card[0][j] == card[i][j] && card[0][j] != 0)
            {
                return 1;
            }
        }

        // Check columns
        for (int j = 0; j < MAX_NUM; j++)
        {
            if (card[j][0] == card[j][i] && card[j][0] != 0)
            {
                return 1;
            }
        }

        // Check diagonal
        if (card[0][0] == card[i][i] && card[0][0] != 0)
        {
            return 1;
        }
    }

    return 0;
}