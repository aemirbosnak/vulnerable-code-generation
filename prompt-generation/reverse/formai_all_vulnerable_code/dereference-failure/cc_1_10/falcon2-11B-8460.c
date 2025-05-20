//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
    int size;
    int weight;
} Bag;

typedef struct {
    Bag *bags;
    int numBags;
} BaggageHandlingSystem;

void initializeBags(BaggageHandlingSystem *bhs) {
    int i;
    bhs->numBags = 0;
    bhs->bags = malloc(100 * sizeof(Bag));
    for (i = 0; i < 100; i++) {
        bhs->bags[i].id = i + 1;
        bhs->bags[i].name[0] = 'B';
        bhs->bags[i].name[1] = 'a';
        bhs->bags[i].name[2] = 'g';
        bhs->bags[i].name[3] = 0;
        bhs->bags[i].size = rand() % 10 + 1;
        bhs->bags[i].weight = rand() % 10 + 1;
        bhs->numBags++;
    }
}

void printBags(BaggageHandlingSystem *bhs) {
    int i;
    for (i = 0; i < bhs->numBags; i++) {
        printf("Bag %d: %s, size %d, weight %d\n", bhs->bags[i].id, bhs->bags[i].name, bhs->bags[i].size, bhs->bags[i].weight);
    }
}

void handleBag(BaggageHandlingSystem *bhs, int bagId, int direction) {
    int i;
    Bag *bag = &bhs->bags[bagId];
    if (direction == 0) {
        printf("Bag %d is arriving from %s, size %d, weight %d\n", bagId, bag->name, bag->size, bag->weight);
        bag->weight += 5;
    } else if (direction == 1) {
        printf("Bag %d is departing to %s, size %d, weight %d\n", bagId, bag->name, bag->size, bag->weight);
        bag->weight -= 5;
    }
}

int main() {
    srand(time(NULL));
    BaggageHandlingSystem bhs;
    initializeBags(&bhs);
    printBags(&bhs);
    int bagId = 3;
    handleBag(&bhs, bagId, 0);
    printBags(&bhs);
    handleBag(&bhs, bagId, 1);
    printBags(&bhs);
    return 0;
}