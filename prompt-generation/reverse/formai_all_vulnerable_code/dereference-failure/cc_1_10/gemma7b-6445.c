//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: random
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_BAGS 10

typedef struct baggage {
    char* name;
    int weight;
    struct baggage* next;
} baggage;

int main() {
    baggage* head = NULL;
    int numBags = 0;

    // Simulate baggage arrivals
    for (int i = 0; i < MAX_BAGS; i++) {
        baggage* newBag = malloc(sizeof(baggage));
        newBag->name = "Bag " + i;
        newBag->weight = rand() % 20;
        newBag->next = NULL;

        if (head == NULL) {
            head = newBag;
        } else {
            head->next = newBag;
            head = newBag;
        }
        numBags++;
    }

    // Calculate total weight
    int totalWeight = 0;
    for (baggage* currentBag = head; currentBag != NULL; currentBag = currentBag->next) {
        totalWeight += currentBag->weight;
    }

    // Print baggage list
    printf("Total number of bags: %d\n", numBags);
    printf("Total weight: %d kg\n", totalWeight);

    // Simulate baggage handling
    for (int i = 0; i < numBags; i++) {
        printf("Handling bag: %s\n", head->name);
        head = head->next;
    }

    return 0;
}