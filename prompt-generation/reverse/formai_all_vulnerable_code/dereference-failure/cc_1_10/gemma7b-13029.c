//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: high level of detail
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BAGS 10
#define MAX_BAG_WEIGHT 20

typedef struct Bag {
    char* name;
    int weight;
    struct Bag* next;
} Bag;

Bag* createBag(char* name, int weight) {
    Bag* newBag = malloc(sizeof(Bag));
    newBag->name = strdup(name);
    newBag->weight = weight;
    newBag->next = NULL;
    return newBag;
}

void addBag(Bag* head, char* name, int weight) {
    Bag* newBag = createBag(name, weight);
    if (head == NULL) {
        head = newBag;
    } else {
        head->next = newBag;
        head = newBag;
    }
}

void handleBaggage() {
    Bag* head = NULL;
    addBag(head, "John Doe's suitcase", 15);
    addBag(head, "Jane Doe's backpack", 12);
    addBag(head, "Peter Pan's trunk", 18);

    printf("List of baggage:\n");
    for (Bag* currentBag = head; currentBag; currentBag = currentBag->next) {
        printf("%s (weight: %d)\n", currentBag->name, currentBag->weight);
    }

    printf("Total weight of baggage: %d\n", getTotalWeight(head));
    printf("Number of bags: %d\n", getNumberOfBags(head));
}

int getTotalWeight(Bag* head) {
    int totalWeight = 0;
    for (Bag* currentBag = head; currentBag; currentBag = currentBag->next) {
        totalWeight += currentBag->weight;
    }
    return totalWeight;
}

int getNumberOfBags(Bag* head) {
    int numBags = 0;
    for (Bag* currentBag = head; currentBag; currentBag = currentBag->next) {
        numBags++;
    }
    return numBags;
}

int main() {
    handleBaggage();
    return 0;
}