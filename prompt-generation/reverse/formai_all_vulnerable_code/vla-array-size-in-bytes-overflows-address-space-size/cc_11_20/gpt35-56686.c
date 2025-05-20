//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers from 1 to 75 (inclusive)
int generateNumber(int *calledNumbers)
{
    int number;
    do
    {
        number = rand() % 75 + 1;
    } while (calledNumbers[number] == 1);

    return number;
}

// Function to print the currently called numbers
void printCalledNumbers(int *calledNumbers)
{
    printf("\n\n========== Called Numbers ==========\n");

    for (int i = 1; i <= 75; i++)
    {
        if (calledNumbers[i] == 1)
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    printf("Welcome to the Bingo Simulator!\n");

    // Seed the random number generator
    srand(time(NULL));

    // Initialize calledNumbers array to all zeros
    int calledNumbers[76] = {0};

    // Initialize variables
    int numPlayers, numCardsPerPlayer;
    printf("\nEnter number of players: ");
    scanf("%d", &numPlayers);
    printf("Enter number of cards per player: ");
    scanf("%d", &numCardsPerPlayer);

    // Create arrays to store player cards
    int playerCards[numPlayers][numCardsPerPlayer][5][5];

    // Initialize player cards to all zeros
    for (int i = 0; i < numPlayers; i++)
    {
        for (int j = 0; j < numCardsPerPlayer; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    playerCards[i][j][k][l] = 0;
                }
            }
        }
    }

    // Initialize game over flag to false
    int gameOver = 0;

    // Start game loop
    while (!gameOver)
    {
        // Generate a new number and mark it as called
        int number = generateNumber(calledNumbers);
        calledNumbers[number] = 1;

        // Print the number and currently called numbers
        printf("\n\n========== Calling Number %d ==========\n", number);
        printCalledNumbers(calledNumbers);

        // Check each player's cards for the number
        for (int i = 0; i < numPlayers; i++)
        {
            for (int j = 0; j < numCardsPerPlayer; j++)
            {
                int cardFound = 0;

                // Check the player's card for the number
                for (int k = 0; k < 5; k++)
                {
                    for (int l = 0; l < 5; l++)
                    {
                        if (playerCards[i][j][k][l] == number)
                        {
                            playerCards[i][j][k][l] = -1; // Mark number as matched
                            cardFound = 1;                 // Set flag to true
                            break;                         // Exit loop
                        }
                    }
                    if (cardFound)
                    {
                        break; // Exit loop
                    }
                }

                // Check if the player has a bingo
                int bingo = 1;

                // Check rows
                for (int k = 0; k < 5; k++)
                {
                    bingo = 1;
                    for (int l = 0; l < 5; l++)
                    {
                        if (playerCards[i][j][k][l] != -1)
                        {
                            bingo = 0;
                            break;
                        }
                    }
                    if (bingo)
                    {
                        printf("\n\n!!!!!BINGO!!!!!\n\n");
                        printf("Player %d wins!\n", i + 1);
                        gameOver = 1;
                        break;
                    }
                }

                if (!gameOver)
                {
                    // Check columns
                    for (int k = 0; k < 5; k++)
                    {
                        bingo = 1;
                        for (int l = 0; l < 5; l++)
                        {
                            if (playerCards[i][j][l][k] != -1)
                            {
                                bingo = 0;
                                break;
                            }
                        }
                        if (bingo)
                        {
                            printf("\n\n!!!!!BINGO!!!!!\n\n");
                            printf("Player %d wins!\n", i + 1);
                            gameOver = 1;
                            break;
                        }
                    }
                }

                if (!gameOver)
                {
                    // Check diagonals
                    bingo = 1;
                    for (int k = 0; k < 5; k++)
                    {
                        if (playerCards[i][j][k][k] != -1)
                        {
                            bingo = 0;
                            break;
                        }
                    }
                    if (bingo)
                    {
                        printf("\n\n!!!!!BINGO!!!!!\n\n");
                        printf("Player %d wins!\n", i + 1);
                        gameOver = 1;
                        break;
                    }
                }

                if (!gameOver)
                {
                    // Check other diagonals
                    bingo = 1;
                    for (int k = 0; k < 5; k++)
                    {
                        if (playerCards[i][j][4 - k][k] != -1)
                        {
                            bingo = 0;
                            break;
                        }
                    }
                    if (bingo)
                    {
                        printf("\n\n!!!!!BINGO!!!!!\n\n");
                        printf("Player %d wins!\n", i + 1);
                        gameOver = 1;
                        break;
                    }
                }
            }
            if (gameOver)
            {
                break; // Exit loop
            }
        }

        // Check if all numbers have been called
        int allCalled = 1;
        for (int i = 1; i <= 75; i++)
        {
            if (calledNumbers[i] == 0)
            {
                allCalled = 0;
                break;
            }
        }

        // If all numbers have been called, end game
        if (allCalled)
        {
            printf("\n\n*****GAME OVER*****\n");
            printf("All numbers have been called and no one has won!\n");
            gameOver = 1;
        }
    }

    return 0;
}