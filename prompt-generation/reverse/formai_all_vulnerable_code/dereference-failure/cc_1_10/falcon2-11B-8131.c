//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* name;
    int weight;
    int category;
} Bag;

typedef struct {
    Bag* bags;
    int length;
} Conveyor;

Conveyor* createConveyor(int length) {
    Conveyor* conveyor = malloc(sizeof(Conveyor));
    conveyor->length = length;
    conveyor->bags = malloc(conveyor->length * sizeof(Bag));
    return conveyor;
}

void addBag(Conveyor* conveyor, char* name, int weight, int category) {
    Bag* bag = malloc(sizeof(Bag));
    bag->name = name;
    bag->weight = weight;
    bag->category = category;
    conveyor->bags[conveyor->length] = *bag;
    conveyor->length++;
}

void printConveyor(Conveyor* conveyor) {
    for (int i = 0; i < conveyor->length; i++) {
        printf("Bag %d: %s (weight: %d, category: %d)\n", i + 1, conveyor->bags[i].name, conveyor->bags[i].weight, conveyor->bags[i].category);
    }
}

int main() {
    int numBags = 5;
    Conveyor* conveyor = createConveyor(numBags);

    addBag(conveyor, "Laptop", 2, 1);
    addBag(conveyor, "Duffel Bag", 5, 2);
    addBag(conveyor, "Suitcase", 8, 3);
    addBag(conveyor, "Backpack", 3, 4);
    addBag(conveyor, "Trunk", 10, 5);

    printConveyor(conveyor);

    return 0;
}