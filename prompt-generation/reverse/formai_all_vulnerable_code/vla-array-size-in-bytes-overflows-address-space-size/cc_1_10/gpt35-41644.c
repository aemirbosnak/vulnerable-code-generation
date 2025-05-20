//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 128 // Buffer size for input

int main()
{
    srand(time(NULL)); // Seed for random number generator
    int numPlayers, numRounds;
    char name[BUFFER_SIZE];
    
    printf("Welcome to Multiplayer DSP!\n");
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);
    
    printf("Enter the number of rounds: ");
    scanf("%d", &numRounds);
    
    // Create a 2D array to store each player's data
    int playerData[numPlayers][numRounds];
    
    // Get each player's name and store it in an array
    char playerNames[numPlayers][BUFFER_SIZE];
    for (int i = 0; i < numPlayers; i++)
    {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", name);
        strcpy(playerNames[i], name);
    }
    
    // Generate random data for each player in each round
    for (int i = 0; i < numPlayers; i++)
    {
        for (int j = 0; j < numRounds; j++)
        {
            playerData[i][j] = rand() % 100;
        }
    }
    
    // Display each player's name and data for each round
    printf("\nPlayer data:\n");
    for (int i = 0; i < numPlayers; i++)
    {
        printf("%s: ", playerNames[i]);
        for (int j = 0; j < numRounds; j++)
        {
            printf("%d ", playerData[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}