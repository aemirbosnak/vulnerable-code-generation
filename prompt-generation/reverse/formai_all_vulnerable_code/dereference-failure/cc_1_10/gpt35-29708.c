//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct for individual baggage
typedef struct {
    int weight;
    char *destination;
} Baggage;

// Struct for the conveyor belt
typedef struct {
    int capacity;
    Baggage *bags[100];
} ConveyorBelt;

void addBaggage(ConveyorBelt *belt, Baggage *bag) {
    // Check if belt is full
    if (belt->capacity >= 100) {
        printf("Conveyor Belt is full!");
        return;
    }
    
    // Add baggage to the belt
    belt->bags[belt->capacity] = bag;
    belt->capacity++;
    
    printf("Added Baggage with destination: %s and weight: %d\n", bag->destination, bag->weight);
}

bool sendToPlane(ConveyorBelt *belt, char *destination) {
    // Check if the belt is empty
    if (belt->capacity == 0) {
        printf("Conveyor Belt is empty!");
        return false;
    }
    
    // Send baggage to the plane with matching destination
    for (int i = 0; i < belt->capacity; i++) {
        Baggage *currBag = belt->bags[i];
        if (strcmp(currBag->destination, destination) == 0) {
            printf("Baggage with destination: %s and weight: %d has been sent to the plane!\n", currBag->destination, currBag->weight);
            belt->bags[i] = NULL;
            belt->capacity--;
            return true;
        }
    }
    
    // No baggage with destination found on belt
    printf("No baggage with destination: %s was found on the Conveyor Belt", destination);
    return false;
}

int main(void) {
    // Create conveyor belt
    ConveyorBelt *belt = malloc(sizeof(ConveyorBelt));
    belt->capacity = 0;
    
    // Add baggage to the belt
    Baggage *bag1 = malloc(sizeof(Baggage));
    bag1->destination = "Las Vegas";
    bag1->weight = 20;
    addBaggage(belt, bag1);
    
    Baggage *bag2 = malloc(sizeof(Baggage));
    bag2->destination = "Los Angeles";
    bag2->weight = 30;
    addBaggage(belt, bag2);

    // Send baggage to planes
    sendToPlane(belt, "Las Vegas");
    sendToPlane(belt, "Los Angeles");
    sendToPlane(belt, "New York");
    
    return 0;
}