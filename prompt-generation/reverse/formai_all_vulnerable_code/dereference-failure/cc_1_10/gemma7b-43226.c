//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_BAG_NUMBER 100
#define MAX_BAG_WEIGHT 50

typedef struct Bag {
    int number;
    int weight;
    struct Bag* next;
} Bag;

Bag* createBag(int number, int weight) {
    Bag* newBag = malloc(sizeof(Bag));
    newBag->number = number;
    newBag->weight = weight;
    newBag->next = NULL;
    return newBag;
}

void addBag(Bag* head, int number, int weight) {
    Bag* newBag = createBag(number, weight);
    if (head == NULL) {
        head = newBag;
    } else {
        head->next = newBag;
        head = newBag;
    }
}

void handleBaggage(Bag* head) {
    while (head) {
        printf("Bag number: %d, weight: %d\n", head->number, head->weight);
        head = head->next;
    }
}

int main() {
    srand(time(NULL));
    Bag* head = NULL;

    // Create and add some bags
    addBag(head, rand() % MAX_BAG_NUMBER, rand() % MAX_BAG_WEIGHT);
    addBag(head, rand() % MAX_BAG_NUMBER, rand() % MAX_BAG_WEIGHT);
    addBag(head, rand() % MAX_BAG_NUMBER, rand() % MAX_BAG_WEIGHT);
    addBag(head, rand() % MAX_BAG_NUMBER, rand() % MAX_BAG_WEIGHT);

    // Handle baggage
    handleBaggage(head);

    return 0;
}