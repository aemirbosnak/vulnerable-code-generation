//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char owner[MAX_NAME_LENGTH];
    int weight; // in kg
    char status[20]; // "Arrived", "Processed", "Delivered"
} Baggage;

void initializeBaggage(Baggage *bag, int id, const char *owner, int weight) {
    bag->id = id;
    strncpy(bag->owner, owner, MAX_NAME_LENGTH);
    bag->weight = weight;
    strcpy(bag->status, "Arrived");
}

void processBaggage(Baggage *bag) {
    if (strcmp(bag->status, "Arrived") == 0) {
        strcpy(bag->status, "Processed");
        printf("Bag ID %d for %s has been processed.\n", bag->id, bag->owner);
    }
}

void deliverBaggage(Baggage *bag) {
    if (strcmp(bag->status, "Processed") == 0) {
        strcpy(bag->status, "Delivered");
        printf("Bag ID %d for %s has been delivered.\n", bag->id, bag->owner);
    }
}

void printBagInfo(Baggage *bag) {
    printf("Bag ID: %d\n", bag->id);
    printf("Owner: %s\n", bag->owner);
    printf("Weight: %d kg\n", bag->weight);
    printf("Status: %s\n\n", bag->status);
}

int main() {
    Baggage *bags[MAX_BAGS];
    int bagCount = 0;
    
    // Simulating the arrival of bags
    bags[bagCount] = (Baggage *)malloc(sizeof(Baggage));
    initializeBaggage(bags[bagCount], 1, "John Doe", 23);
    bagCount++;

    bags[bagCount] = (Baggage *)malloc(sizeof(Baggage));
    initializeBaggage(bags[bagCount], 2, "Jane Smith", 18);
    bagCount++;

    bags[bagCount] = (Baggage *)malloc(sizeof(Baggage));
    initializeBaggage(bags[bagCount], 3, "Alice Johnson", 25);
    bagCount++;

    // Processing and delivering bags
    for (int i = 0; i < bagCount; i++) {
        printBagInfo(bags[i]);
        processBaggage(bags[i]);
        deliverBaggage(bags[i]);
    }

    // Free allocated memory
    for (int i = 0; i < bagCount; i++) {
        free(bags[i]);
    }

    return 0;
}