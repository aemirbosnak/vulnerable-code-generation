//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 100
#define MAX_NAME_LENGTH 50

typedef struct Bag {
    char name[MAX_NAME_LENGTH];
    int status;
} Bag;

typedef struct BagList {
    int size;
    int capacity;
    Bag *bags;
} BagList;

BagList *createBagList() {
    BagList *bagList = malloc(sizeof(BagList));
    bagList->size = 0;
    bagList->capacity = MAX_BAGS;
    bagList->bags = malloc(bagList->capacity * sizeof(Bag));
    return bagList;
}

void freeBagList(BagList *bagList) {
    free(bagList->bags);
    free(bagList);
}

void addBag(BagList *bagList, const char *name, int status) {
    Bag *bag = malloc(sizeof(Bag));
    strcpy(bag->name, name);
    bag->status = status;
    if (bagList->size == bagList->capacity) {
        BagList *newBagList = createBagList();
        for (int i = 0; i < bagList->size; i++) {
            newBagList->bags[i] = bagList->bags[i];
        }
        free(bagList);
        bagList = newBagList;
    }
    bagList->bags[bagList->size++] = *bag;
}

void printBagList(BagList *bagList) {
    for (int i = 0; i < bagList->size; i++) {
        printf("%s - %d\n", bagList->bags[i].name, bagList->bags[i].status);
    }
}

int main() {
    BagList *bagList = createBagList();
    addBag(bagList, "John Smith", 1);
    addBag(bagList, "Jane Doe", 2);
    addBag(bagList, "John Smith", 3);
    printBagList(bagList);
    freeBagList(bagList);
    return 0;
}