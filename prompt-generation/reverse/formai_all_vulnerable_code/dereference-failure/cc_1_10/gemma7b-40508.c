//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10

typedef struct Bag {
    char name[20];
    int weight;
    struct Bag* next;
} Bag;

void addBag(Bag** head, char* name, int weight) {
    Bag* newBag = malloc(sizeof(Bag));
    strcpy(newBag->name, name);
    newBag->weight = weight;
    newBag->next = NULL;

    if (*head == NULL) {
        *head = newBag;
    } else {
        (*head)->next = newBag;
    }
}

void handleBags(Bag** head) {
    printf("List of bags:\n");
    for (Bag* currentBag = *head; currentBag; currentBag = currentBag->next) {
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

    // Add some bags
    addBag(&head, "John's Bag", 20);
    addBag(&head, "Mary's Bag", 15);
    addBag(&head, "Peter's Bag", 25);

    // Handle the bags
    handleBags(&head);

    return 0;
}