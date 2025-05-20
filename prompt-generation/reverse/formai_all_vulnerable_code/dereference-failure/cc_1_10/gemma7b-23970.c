//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER_OF_BAGS 10

typedef struct Bag {
    char *name;
    int weight;
    struct Bag *next;
} Bag;

Bag *createBag(char *name, int weight) {
    Bag *newBag = malloc(sizeof(Bag));
    newBag->name = name;
    newBag->weight = weight;
    newBag->next = NULL;

    return newBag;
}

void handleBaggage(Bag *bags) {
    printf("List of bags:\n");
    for (Bag *bag = bags; bag; bag = bag->next) {
        printf("Name: %s, Weight: %d\n", bag->name, bag->weight);
    }

    printf("Total weight of bags: %d\n", totalWeight(bags));

    printf("Bags with weight less than 20:**\n");
    for (Bag *bag = bags; bag; bag = bag->next) {
        if (bag->weight < 20) {
            printf("Name: %s, Weight: %d\n", bag->name, bag->weight);
        }
    }
}

int totalWeight(Bag *bags) {
    int totalWeight = 0;
    for (Bag *bag = bags; bag; bag = bag->next) {
        totalWeight += bag->weight;
    }

    return totalWeight;
}

int main() {
    Bag *bags = NULL;

    // Create a few bags
    bags = createBag("John Doe's suitcase", 30);
    bags = createBag("Jane Doe's handbag", 15);
    bags = createBag("Peter Pan's backpack", 25);

    // Handle baggage
    handleBaggage(bags);

    return 0;
}