//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 10
#define MAX_BAG_WEIGHT 50

typedef struct Bag {
    char* name;
    int weight;
    struct Bag* next;
} Bag;

Bag* createBag(char* name, int weight) {
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    newBag->name = name;
    newBag->weight = weight;
    newBag->next = NULL;
    return newBag;
}

void addBag(Bag* head, char* name, int weight) {
    Bag* newBag = createBag(name, weight);
    if (head == NULL) {
        head = newBag;
    } else {
        newBag->next = head;
        head = newBag;
    }
}

void handleBags(Bag* head) {
    printf("List of bags:\n");
    for (Bag* currentBag = head; currentBag; currentBag = currentBag->next) {
        printf("Name: %s, Weight: %d\n", currentBag->name, currentBag->weight);
    }

    printf("Total weight of bags: %d\n", totalWeight(head));
}

int totalWeight(Bag* head) {
    int totalWeight = 0;
    for (Bag* currentBag = head; currentBag; currentBag = currentBag->next) {
        totalWeight += currentBag->weight;
    }
    return totalWeight;
}

int main() {
    Bag* head = NULL;

    addBag(head, "John Doe's suitcase", 40);
    addBag(head, "Jane Doe's backpack", 20);
    addBag(head, "Peter Pan's trunk", 30);

    handleBags(head);

    return 0;
}