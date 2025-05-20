//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10

typedef struct Bag {
    char name[20];
    int weight;
    struct Bag* next;
} Bag;

Bag* createBag(char* name, int weight) {
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    strcpy(newBag->name, name);
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
    }
    head = newBag;
}

void handleBags(Bag* head) {
    while (head) {
        printf("Bag name: %s, Weight: %d\n", head->name, head->weight);
        head = head->next;
    }
}

int main() {
    srand(time(NULL));
    Bag* head = NULL;
    int numBags = rand() % MAX_BAGS + 1;

    for (int i = 0; i < numBags; i++) {
        addBag(head, "Bag ", rand() % 100);
    }

    handleBags(head);

    return 0;
}