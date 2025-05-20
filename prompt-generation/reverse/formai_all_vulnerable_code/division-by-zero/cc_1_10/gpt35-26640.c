//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int numPlayers, gridSize;
    printf("Alien Invasion Probability Calculator\n");
    printf("How many players are playing? ");
    scanf("%d", &numPlayers);
    printf("What is the size of the game grid? ");
    scanf("%d", &gridSize);

    float playerCoords[numPlayers][2]; //2D array to store each player's coordinates
    for (int i=0; i<numPlayers; i++) {
        printf("Enter Player %d's X Coordinate (0-%d): ", (i+1), (gridSize-1));
        scanf("%f", &playerCoords[i][0]);
        printf("Enter Player %d's Y Coordinate (0-%d): ", (i+1), (gridSize-1));
        scanf("%f", &playerCoords[i][1]);
    }

    float alienCoords[2];
    alienCoords[0] = (rand() % gridSize) + 0.5; //random X coordinate for alien (with decimal)
    alienCoords[1] = (rand() % gridSize) + 0.5; //random Y coordinate for alien (with decimal)

    printf("\n(Player X Coordinate, Player Y Coordinate)\n");
    for (int i=0; i<numPlayers; i++) {
        printf("(%.1f,%.1f)\n", playerCoords[i][0], playerCoords[i][1]);
    }
    printf("\nAlien Location: (%.1f,%.1f)\n", alienCoords[0], alienCoords[1]);

    float closestDist = gridSize*2; //initialize to maximum possible distance between any two points
    for (int i=0; i<numPlayers; i++) {
        float dist = sqrt(pow((playerCoords[i][0]-alienCoords[0]), 2) + pow((playerCoords[i][1]-alienCoords[1]), 2));
        if (dist < closestDist) {
            closestDist = dist;
        }
    }

    float alienInvasionProb = ((gridSize-closestDist)/gridSize)*100;
    printf("\nAlien Invasion Probability: %.2f%%\n", alienInvasionProb);

    if (alienInvasionProb >= 50) {
        printf("ALERT: Alien Invasion Likely! Take Evacuation Precautions!\n");
    } else {
        printf("Alien Invasion Unlikely. Carry On With Normal Activities.\n");
    }

    return 0;
}