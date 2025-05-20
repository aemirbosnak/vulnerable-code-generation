//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random co-ordinates for each player
void generateCoords(int *x, int *y) {
    *x = (rand() % 100) + 1; // Random x-coordinate between 1 and 100
    *y = (rand() % 100) + 1; // Random y-coordinate between 1 and 100
}

// Function to calculate distance between two co-ordinates
int calculateDistance(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2); // Manhattan distance formula
}

int main() {
    int numPlayers;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    // Dynamically allocating arrays to store player co-ordinates and distances
    int *playerX = malloc(numPlayers * sizeof(int));
    int *playerY = malloc(numPlayers * sizeof(int));
    int *distances = malloc(numPlayers * sizeof(int));

    // Generating random co-ordinates for each player
    srand(time(NULL));
    for (int i=0; i<numPlayers; i++) {
        generateCoords(&playerX[i], &playerY[i]);
        printf("Player %d: x = %d, y = %d\n", i+1, playerX[i], playerY[i]);
    }

    // Loop for multiple rounds of simulation
    int round = 0;
    while (1) {
        round++;
        printf("\nRound %d\n", round);

        // Calculating distances between each pair of players and storing in distances array
        for (int i=0; i<numPlayers-1; i++) {
            for (int j=i+1; j<numPlayers; j++) {
                int distance = calculateDistance(playerX[i], playerY[i], playerX[j], playerY[j]);
                distances[i*numPlayers+j] = distance;
                distances[j*numPlayers+i] = distance;
            }
        }

        // Printing distances between each pair of players
        for (int i=0; i<numPlayers; i++) {
            for (int j=0; j<numPlayers; j++) {
                printf("%d ", distances[i*numPlayers+j]);
            }
            printf("\n");
        }

        // Finding closest player for each player
        int *closestPlayer = malloc(numPlayers * sizeof(int));
        for (int i=0; i<numPlayers; i++) {
            int minDist = 999;
            for (int j=0; j<numPlayers; j++) {
                if (i != j && distances[i*numPlayers+j] < minDist) {
                    minDist = distances[i*numPlayers+j];
                    closestPlayer[i] = j;
                }
            }
        }

        // Printing closest player for each player
        for (int i=0; i<numPlayers; i++) {
            printf("Closest player for Player %d: Player %d\n", i+1, closestPlayer[i]+1);
        }

        // Checking if any player has reached the goal (co-ordinates: x=0, y=0)
        for (int i=0; i<numPlayers; i++) {
            if (playerX[i] == 0 && playerY[i] == 0) {
                printf("\nPlayer %d has reached the goal!\n", i+1);
                return 0;
            }
        }

        // Updating co-ordinates of each player to move towards their closest player
        for (int i=0; i<numPlayers; i++) {
            int closestX = playerX[closestPlayer[i]];
            int closestY = playerY[closestPlayer[i]];
            if (playerX[i] < closestX) {
                playerX[i] += 1;
            } else if (playerX[i] > closestX) {
                playerX[i] -= 1;
            }
            if (playerY[i] < closestY) {
                playerY[i] += 1;
            } else if (playerY[i] > closestY) {
                playerY[i] -= 1;
            }
        }
        free(closestPlayer); // Freeing memory allocated for closestPlayer array
    }
    free(playerX); // Freeing memory allocated for playerX array
    free(playerY); // Freeing memory allocated for playerY array
    free(distances); // Freeing memory allocated for distances array
    return 0;
}