//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100

typedef struct {
    int id;
    char destination[50];
    float weight; 
} Bag;

Bag* createBag(int id, const char* destination, float weight) {
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    newBag->id = id;
    strcpy(newBag->destination, destination);
    newBag->weight = weight;
    return newBag;
}

void displayBag(Bag* bag) {
    printf("Bag ID: %d\n", bag->id);
    printf("Destination: %s\n", bag->destination);
    printf("Weight: %.2f kg\n", bag->weight);
}

typedef struct {
    Bag* bags[MAX_BAGS];
    int count;
} ConveyorBelt;

void initializeConveyorBelt(ConveyorBelt* belt) {
    belt->count = 0;
}

int addBagToBelt(ConveyorBelt* belt, Bag* bag) {
    if (belt->count < MAX_BAGS) {
        belt->bags[belt->count++] = bag;
        return 1; // Success
    }
    return 0; // Failure (Belt full)
}

void displayConveyorBelt(ConveyorBelt* belt) {
    printf("\nBags on Conveyor Belt:\n");
    for (int i = 0; i < belt->count; i++) {
        printf("Bag %d:\n", i + 1);
        displayBag(belt->bags[i]);
    }
}

void simulateBaggageHandling() {
    ConveyorBelt belt;
    initializeConveyorBelt(&belt);
    srand(time(NULL));

    // Simulating bag creation
    for (int i = 0; i < 10; i++) {
        int id = i + 1;
        char destination[50];
        sprintf(destination, "Location%d", rand() % 10 + 1);
        float weight = (float)(rand() % 300 + 1) / 10; // Weight between 0.1kg and 30kg
        
        Bag* bag = createBag(id, destination, weight);
        if (addBagToBelt(&belt, bag)) {
            printf("Bag added to the conveyor belt:\n");
            displayBag(bag);
        } else {
            printf("Could not add bag %d: Conveyor Belt full!\n", id);
            free(bag); // Free allocated memory if it couldn't be added
        }
    }

    displayConveyorBelt(&belt);

    // Freeing allocated memories
    for (int i = 0; i < belt.count; i++) {
        free(belt.bags[i]);
    }
}

int main() {
    printf("Welcome to the Airport Baggage Handling Simulation!\n");
    simulateBaggageHandling();
    printf("Simulation complete. Thank you!\n");
    return 0;
}