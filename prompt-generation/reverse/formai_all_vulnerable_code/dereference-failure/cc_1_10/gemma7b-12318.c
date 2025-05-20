//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 10
#define MAX_BAG_WEIGHT 20

typedef struct Bag {
    char *name;
    int weight;
    struct Bag *next;
} Bag;

Bag *insertBag(Bag *head, char *name, int weight) {
    Bag *newBag = (Bag *)malloc(sizeof(Bag));
    newBag->name = name;
    newBag->weight = weight;
    newBag->next = NULL;

    if (head == NULL) {
        head = newBag;
    } else {
        head->next = newBag;
    }

    return head;
}

void handleBaggage(Bag *head) {
    printf("Bags:");
    for (Bag *currBag = head; currBag; currBag = currBag->next) {
        printf(" - %s (%d)", currBag->name, currBag->weight);
    }

    printf("\nTotal weight: %d", getTotalWeight(head));
}

int getTotalWeight(Bag *head) {
    int totalWeight = 0;
    for (Bag *currBag = head; currBag; currBag = currBag->next) {
        totalWeight += currBag->weight;
    }

    return totalWeight;
}

int main() {
    Bag *head = NULL;

    insertBag(head, "John Doe's Bag", 15);
    insertBag(head, "Jane Doe's Bag", 12);
    insertBag(head, "Jack Doe's Bag", 18);

    handleBaggage(head);

    return 0;
}