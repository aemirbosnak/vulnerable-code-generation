//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS_PER_FLIGHT 300

// Function prototypes
void initRandomSeed();
int generateRandomNumber(int min, int max);
int baggageLoadTime(int baggageWeight);

// Struct definitions
typedef struct Baggage {
    int weight;
    int loadTime;
} Baggage;

typedef struct Flight {
    int flightNum;
    int numOfBags;
    Baggage baggage[MAX_BAGS_PER_FLIGHT];
} Flight;

typedef struct ConveyorBelt {
    Baggage *baggagePtr;
    int numOfBags;
} ConveyorBelt;

// Main function
int main() {
    initRandomSeed(); // Init random seed for generating random numbers
    
    // Init airport resources
    ConveyorBelt conveyorBelt = {NULL, 0};
    Flight flight = {1234, generateRandomNumber(50, MAX_BAGS_PER_FLIGHT)};
    
    // Load baggage onto the conveyor belt
    for (int i = 0; i < flight.numOfBags; i++) {
        int baggageWeight = generateRandomNumber(5, 50);
        flight.baggage[i].weight = baggageWeight;
        flight.baggage[i].loadTime = baggageLoadTime(baggageWeight);
        
        conveyorBelt.numOfBags++;
        conveyorBelt.baggagePtr = realloc(conveyorBelt.baggagePtr, sizeof(Baggage) * conveyorBelt.numOfBags);
        if (!conveyorBelt.baggagePtr) {
            printf("Error: Failed to allocate memory for baggage.\n");
            exit(EXIT_FAILURE);
        }
        
        conveyorBelt.baggagePtr[conveyorBelt.numOfBags - 1] = flight.baggage[i];
    }
    
    // Check baggage weight limits
    bool baggageOverweight = false;
    int totalBaggageWeight = 0;
    for (int i = 0; i < flight.numOfBags; i++) {
        totalBaggageWeight += flight.baggage[i].weight;
        if (flight.baggage[i].weight > 32) {
            baggageOverweight = true;
        }
    }
    
    printf("Flight %d ready for departure with %d bags, total weight is %d kg.\n", flight.flightNum, flight.numOfBags, totalBaggageWeight);
    if (baggageOverweight) {
        printf("Warning: Some baggage exceeds the weight limit of 32 kg.\n");
    }
    
    // Simulate conveyor belt handling
    printf("Conveyor belt handling...\n");
    for (int i = 0; i < conveyorBelt.numOfBags; i++) {
        printf("Passing baggage with weight %d kg through the conveyor belt... ", conveyorBelt.baggagePtr[i].weight);
        for (int j = 0; j < conveyorBelt.baggagePtr[i].loadTime; j++) {
            printf("."); // Show progress
        }
        printf(" %d sec.\n", conveyorBelt.baggagePtr[i].loadTime);
    }
    
    // Free allocated memory
    free(conveyorBelt.baggagePtr);
    
    return 0;
}

// Function definitions

// Initializes the random number generator with the current time
void initRandomSeed() {
    srand(time(NULL));
}

// Generates a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Calculates the time needed to load a baggage onto the plane based on its weight
int baggageLoadTime(int baggageWeight) {
    if (baggageWeight <= 10) {
        return generateRandomNumber(1, 5);
    } else if (baggageWeight <= 20) {
        return generateRandomNumber(2, 10);
    } else if (baggageWeight <= 30) {
        return generateRandomNumber(5, 15);
    } else {
        return generateRandomNumber(10, 20);
    }
}