//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 10
#define MAX_WEIGHT 50

typedef struct Bag {
    char* name;
    int weight;
    struct Bag* next;
} Bag;

Bag* insertBag(Bag* head, char* name, int weight) {
    Bag* newBag = malloc(sizeof(Bag));
    newBag->name = strdup(name);
    newBag->weight = weight;
    newBag->next = NULL;

    if (head == NULL) {
        head = newBag;
    } else {
        head->next = newBag;
    }

    return head;
}

void handleBags(Bag* head) {
    printf("Bags:");
    for (Bag* currentBag = head; currentBag; currentBag = currentBag->next) {
        printf(" - %s (%d kg)", currentBag->name, currentBag->weight);
    }

    printf("\nTotal weight:");
    int totalWeight = 0;
    for (Bag* currentBag = head; currentBag; currentBag = currentBag->next) {
        totalWeight += currentBag->weight;
    }

    printf(" %d kg\n", totalWeight);

    printf("Is the total weight within the limit of %d kg?", MAX_WEIGHT);
    if (totalWeight <= MAX_WEIGHT) {
        printf(" Yes\n");
    } else {
        printf(" No\n");
    }
}

int main() {
    Bag* head = NULL;

    insertBag(head, "John's bag", 20);
    insertBag(head, "Mary's bag", 15);
    insertBag(head, "Peter's bag", 30);

    handleBags(head);

    return 0;
}