//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayHeader() {
    printf("\n|============================================|\n");
    printf("|            Alien Invasion Probulator       |\n");
    printf("|============================================|\n");
}

int main() {
    displayHeader();

    int numPlanets, numInvasions, i, j, k, invasionChance, totalInvasionCount = 0;

    printf("\nEnter the number of planets in your galaxy: ");
    scanf("%d", &numPlanets);

    int planetArray[numPlanets];

    // Initialize the planetArray to 0
    for(i = 0; i < numPlanets; i++) {
        planetArray[i] = 0;
    }

    printf("\nEnter the number of invasions you want to simulate: ");
    scanf("%d", &numInvasions);

    // Seed the random number generator using current time
    srand(time(0));

    for(j = 1; j <= numInvasions; j++) {
        invasionChance = rand()%101; //Generate a random number between 0 and 100
        totalInvasionCount += invasionChance < 30 ? 1 : 0;

        for(k = 0; k < numPlanets && invasionChance < 30; k++) {
            //If invasionChance is less than 30, then it's a successful invasion, update the planetArray
            planetArray[k]++;
        }
    }

    printf("\n===============================================");
    printf("\nResults after %d invasion simulations:\n", numInvasions);
    printf("===============================================\n");

    for(i = 0; i < numPlanets; i++) {
        printf("Planet %d was invaded %2.2f %% times.\n", i+1, (double)planetArray[i]/numInvasions*100);
    }

    printf("\nTotal number of successful invasions: %d\n", totalInvasionCount);

    return 0;
}