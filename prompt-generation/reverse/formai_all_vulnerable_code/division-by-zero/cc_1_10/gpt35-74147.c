//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 50
#define MAX_FLIGHTS 10

typedef struct {
    int id; // Unique identifier for each bag
    int flightNum; // Flight number of the bag
    int timeChecked; // Time the bag was checked in
} Baggage;

int main() {
    Baggage baggage[MAX_BAGS]; // Array to store bags
    int numBags, numFlights, totalBags = 0;

    // Input number of bags and flights
    printf("Enter the number of bags to simulate: ");
    scanf("%d", &numBags);
    printf("Enter the number of flights to simulate: ");
    scanf("%d", &numFlights);

    // Create bags with random flight numbers and check-in times
    srand(time(NULL));
    for (int i = 0; i < numBags; i++) {
        baggage[i].id = i+1;
        baggage[i].flightNum = rand() % numFlights + 1;
        baggage[i].timeChecked = rand() % 120; // Check-in time between 0-119 minutes
    }

    // Simulate baggage handling for each flight
    for (int flight = 1; flight <= numFlights; flight++) {
        int bagsLoaded = 0, bagsRejected = 0, expectedTime = -1;

        // Print flight info
        printf("\n\nSimulating flight %d baggage handling...\n\n", flight);

        // Loop through all bags and handle them if they belong to this flight
        for (int i = 0; i < numBags; i++) {
            if (baggage[i].flightNum == flight) {
                // Calculate time bag should be loaded onto plane
                if (expectedTime < baggage[i].timeChecked) {
                    expectedTime = baggage[i].timeChecked;
                }
                expectedTime += 2; // Assumes 2 minute per bag loading time

                // Check if bag will be loaded on time
                if (expectedTime <= 120) {
                    printf("Bag %d for flight %d loaded at time %d\n", baggage[i].id, flight, expectedTime);
                    bagsLoaded++;
                    totalBags++;
                } else {
                    printf("Bag %d for flight %d rejected\n", baggage[i].id, flight);
                    bagsRejected++;
                }
            }
        }

        // Print flight summary
        printf("\nSummary for flight %d:\n", flight);
        printf("%d bags loaded successfully\n", bagsLoaded);
        printf("%d bags rejected\n", bagsRejected);
    }

    // Print overall summary
    printf("\n\nOverall summary:\n");
    printf("%d bags loaded successfully\n", totalBags);
    printf("%d bags rejected\n", numBags-totalBags);

    return 0;
}