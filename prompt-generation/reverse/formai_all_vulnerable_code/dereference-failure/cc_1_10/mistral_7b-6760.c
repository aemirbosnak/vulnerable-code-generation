//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char flightNumber[10];
    int numBags;
    int* bagWeights;
} Flight;

typedef struct {
    int id;
    int weight;
    Flight* associatedFlight;
} Bag;

void generateFlights(Flight** flights, int numFlights) {
    *flights = malloc(numFlights * sizeof(Flight));

    for (int i = 0; i < numFlights; i++) {
        Flight* currentFlight = &((*flights)[i]);
        sprintf(currentFlight->flightNumber, "FL%02d", i + 1);
        currentFlight->numBags = rand() % 50 + 1;
        currentFlight->bagWeights = malloc(currentFlight->numBags * sizeof(int));

        for (int j = 0; j < currentFlight->numBags; j++) {
            currentFlight->bagWeights[j] = rand() % 50 + 1;
        }
    }
}

void printFlights(Flight* flights, int numFlights) {
    for (int i = 0; i < numFlights; i++) {
        Flight* currentFlight = &flights[i];
        printf("Flight %s: %d bags, total weight: %d\n", currentFlight->flightNumber, currentFlight->numBags, getTotalWeight(currentFlight));
    }
}

int getTotalWeight(Flight* flight) {
    int totalWeight = 0;

    for (int i = 0; i < flight->numBags; i++) {
        totalWeight += flight->bagWeights[i];
    }

    return totalWeight;
}

void assignBagsToFlights(Bag** bags, Flight* flights, int numBags, int numFlights) {
    for (int i = 0; i < numBags; i++) {
        Bag* currentBag = &((*bags)[i]);
        int flightIndex = rand() % numFlights;

        currentBag->id = i + 1;
        currentBag->weight = rand() % 50 + 1;
        currentBag->associatedFlight = &flights[flightIndex];
    }
}

void printBagsAndTheirFlights(Bag* bags, Flight* flights, int numBags, int numFlights) {
    for (int i = 0; i < numBags; i++) {
        Bag* currentBag = &bags[i];
        Flight* currentFlight = currentBag->associatedFlight;

        printf("Bag %d (weight: %d) on Flight %s\n", currentBag->id, currentBag->weight, currentFlight->flightNumber);
    }
}

int main() {
    srand(time(NULL));

    int numFlights = 5;
    int numBags = 50;

    Flight* flights;
    Bag* bags;

    generateFlights(&flights, numFlights);
    assignBagsToFlights(&bags, flights, numBags, numFlights);

    printf("\nGenerated Flights:\n");
    printFlights(flights, numFlights);

    printf("\nBags and their Associated Flights:\n");
    printBagsAndTheirFlights(bags, flights, numBags, numFlights);

    free(flights);
    free(bags);

    return 0;
}