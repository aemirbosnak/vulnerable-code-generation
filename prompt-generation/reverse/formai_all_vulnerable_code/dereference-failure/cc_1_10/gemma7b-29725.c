//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAG_NUMBER 10
#define MAX_BAG_WEIGHT 50

typedef struct Bag {
    char *name;
    int weight;
    struct Bag *next;
} Bag;

Bag *createBag(char *name, int weight) {
    Bag *newBag = malloc(sizeof(Bag));
    newBag->name = strdup(name);
    newBag->weight = weight;
    newBag->next = NULL;
    return newBag;
}

void handleBaggage(Bag *bags) {
    printf("List of bags:\n");
    for (Bag *bag = bags; bag; bag = bag->next) {
        printf("Name: %s, Weight: %d\n", bag->name, bag->weight);
    }

    printf("Total weight of baggage: %d\n", totalWeight(bags));

    printf("Bags with weight greater than 20:\n");
    for (Bag *bag = bags; bag; bag = bag->next) {
        if (bag->weight > 20) {
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

    bags = createBag("John Doe's suitcase", 25);
    bags = createBag("Jane Doe's handbag", 10);
    bags = createBag("Tom Smith's backpack", 30);

    handleBaggage(bags);

    return 0;
}