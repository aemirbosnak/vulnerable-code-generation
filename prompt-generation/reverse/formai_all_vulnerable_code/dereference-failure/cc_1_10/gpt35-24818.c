//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Global variables
int numTerminals;
int numConveyors;
int numLuggage;
int** terminalDestinations;
int** conveyorDestinations;
int* terminalLuggageCounts;
int* conveyorLuggageCounts;

// Function prototypes
int generateRandomNumber(int max);
void initializeData();
void moveLuggage();

int main()
{
    initializeData();
    
    while (true) {
        moveLuggage();
        // Print current state of system
        printf("Terminal luggage counts:\n");
        for (int i = 0; i < numTerminals; i++) {
            printf("Terminal %d: %d\n", i + 1, terminalLuggageCounts[i]);
        }
        printf("Conveyor luggage counts:\n");
        for (int i = 0; i < numConveyors; i++) {
            printf("Conveyor %d: %d\n", i + 1, conveyorLuggageCounts[i]);
        }
    }
    
    return 0;
}

// Generates a random number between 0 and max-1
int generateRandomNumber(int max)
{
    return rand() % max;
}

// Initializes all data structures
void initializeData()
{
    // Initialize random number generator
    srand(time(NULL));
    
    // Get input from user
    printf("Enter number of terminals: ");
    scanf("%d", &numTerminals);
    printf("Enter number of conveyors: ");
    scanf("%d", &numConveyors);
    printf("Enter number of luggage: ");
    scanf("%d", &numLuggage);
    
    // Initialize terminal and conveyor destination arrays
    terminalDestinations = (int**)malloc(sizeof(int*) * numTerminals);
    conveyorDestinations = (int**)malloc(sizeof(int*) * numConveyors);
    for (int i = 0; i < numTerminals; i++) {
        terminalDestinations[i] = (int*)malloc(sizeof(int) * numConveyors);
        for (int j = 0; j < numConveyors; j++) {
            terminalDestinations[i][j] = generateRandomNumber(numConveyors);
        }
    }
    for (int i = 0; i < numConveyors; i++) {
        conveyorDestinations[i] = (int*)malloc(sizeof(int) * numTerminals);
        for (int j = 0; j < numTerminals; j++) {
            conveyorDestinations[i][j] = generateRandomNumber(numTerminals);
        }
    }
    
    // Initialize terminal and conveyor luggage counts
    terminalLuggageCounts = (int*)malloc(sizeof(int) * numTerminals);
    conveyorLuggageCounts = (int*)malloc(sizeof(int) * numConveyors);
    for (int i = 0; i < numTerminals; i++) {
        terminalLuggageCounts[i] = 0;
    }
    for (int i = 0; i < numConveyors; i++) {
        conveyorLuggageCounts[i] = 0;
    }
    
    // Distribute luggage evenly between terminals
    int remainingLuggage = numLuggage;
    for (int i = 0; i < numTerminals; i++) {
        int luggageToAdd = remainingLuggage / (numTerminals - i);
        remainingLuggage -= luggageToAdd;
        terminalLuggageCounts[i] += luggageToAdd;
    }
}

// Moves luggage through system
void moveLuggage()
{
    // Move luggage from terminals to conveyors
    for (int i = 0; i < numTerminals; i++) {
        for (int j = 0; j < numConveyors; j++) {
            int destConveyor = terminalDestinations[i][j];
            int numLuggageToMove = generateRandomNumber(terminalLuggageCounts[i] + 1);
            if (numLuggageToMove > 0) {
                terminalLuggageCounts[i] -= numLuggageToMove;
                conveyorLuggageCounts[destConveyor] += numLuggageToMove;
            }
        }
    }
    
    // Move luggage from conveyors to terminals
    for (int i = 0; i < numConveyors; i++) {
        for (int j = 0; j < numTerminals; j++) {
            int destTerminal = conveyorDestinations[i][j];
            int numLuggageToMove = generateRandomNumber(conveyorLuggageCounts[i] + 1);
            if (numLuggageToMove > 0) {
                conveyorLuggageCounts[i] -= numLuggageToMove;
                terminalLuggageCounts[destTerminal] += numLuggageToMove;
            }
        }
    }
}