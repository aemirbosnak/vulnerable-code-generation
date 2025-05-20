//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5
#define GHOUL_DELAY 200

int main()
{
    int i, j, nGhouls, ghosts[MAX_GHOULS], haunt[MAX_GHOULS];
    time_t tStart, tEnd;

    // Initialize the number of ghosts
    nGhouls = 0;

    // Create a haunted house
    for (i = 0; i < MAX_GHOULS; i++)
    {
        ghosts[i] = 0;
        haunt[i] = 0;
    }

    // Start the clock
    tStart = time(NULL);

    // Simulate hauntings
    for (j = 0; j < GHOUL_DELAY; j++)
    {
        // Randomly select a ghost
        i = rand() % nGhouls;

        // If the ghost is not already haunting, have it haunt the house
        if (ghosts[i] == 0)
        {
            ghosts[i] = 1;
            haunt[i] = time(NULL) + 10;
        }
    }

    // End the clock
    tEnd = time(NULL);

    // Calculate the time spent haunting
    int timeSpent = tEnd - tStart;

    // Print the time spent haunting
    printf("Time spent haunting: %d seconds\n", timeSpent);

    return 0;
}