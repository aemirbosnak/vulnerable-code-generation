//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_PLAYERS = 5;
const int MAX_SIGNAL_STRENGTH = 100;

int main()
{
    srand(time(NULL)); // Seed random number generator
    
    int numPlayers = 0;
    
    // Get number of players
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);
    
    if (numPlayers > MAX_PLAYERS)
    {
        printf("Sorry, only up to %d players are allowed.\n", MAX_PLAYERS);
        return 0;
    }
    
    int signalStrengths[numPlayers];
    
    // Generate random signal strengths for each player
    for (int i = 0; i < numPlayers; i++)
    {
        signalStrengths[i] = rand() % (MAX_SIGNAL_STRENGTH + 1);
    }
    
    // Print out signal strengths for each player
    printf("\nSignal Strengths:\n");
    for (int i = 0; i < numPlayers; i++)
    {
        printf("Player %d: %d\n", i+1, signalStrengths[i]);
    }
    
    // Determine the player with the strongest signal strength
    int maxSignalStrength = 0;
    int strongestPlayer = 0;
    
    for (int i = 0; i < numPlayers; i++)
    {
        if (signalStrengths[i] > maxSignalStrength)
        {
            maxSignalStrength = signalStrengths[i];
            strongestPlayer = i+1;
        }
    }
    
    // Print out the strongest player and their signal strength
    printf("\nThe strongest player is Player %d with a signal strength of %d.\n", strongestPlayer, maxSignalStrength);
    
    return 0;
}