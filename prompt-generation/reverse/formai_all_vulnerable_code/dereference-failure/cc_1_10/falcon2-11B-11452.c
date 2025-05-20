//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int numBags = 100;
int bagsArrived = 0;
int bagsToBeHandled = 0;
int bagsInTransit = 0;
int bagsHandled = 0;

// Structure to represent a bag
typedef struct {
    int id;
    int weight;
    int destination;
} Bag;

int main() {
    srand(time(NULL)); // Initialize random seed
    
    // Create bags
    Bag* bags = (Bag*) malloc(numBags * sizeof(Bag));
    for (int i = 0; i < numBags; i++) {
        bags[i].id = i + 1;
        bags[i].weight = rand() % 50 + 1; // Random weight between 1 and 50
        bags[i].destination = rand() % 5 + 1; // Random destination between 1 and 5
    }
    
    // Print initial bag status
    printf("Initial Bag Status:\n");
    for (int i = 0; i < numBags; i++) {
        printf("Bag %d: %d kg, Destination: %d\n", i + 1, bags[i].weight, bags[i].destination);
    }
    
    // Handle bags
    while (bagsInTransit < numBags) {
        // Get next bag to handle
        int bagIndex = rand() % numBags;
        
        // Move bag to handling queue
        bags[bagIndex].destination = 6; // Destination code for handling
        bagsInTransit++;
        
        // Print updated bag status
        printf("\nBag %d moved to handling queue.\n", bagIndex + 1);
    }
    
    // Print final bag status
    printf("\nFinal Bag Status:\n");
    for (int i = 0; i < numBags; i++) {
        printf("Bag %d: %d kg, Destination: %d\n", i + 1, bags[i].weight, bags[i].destination);
    }
    
    // Free allocated memory
    for (int i = 0; i < numBags; i++) {
        free(bags[i].id);
    }
    free(bags);
    
    return 0;
}