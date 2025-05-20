//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100

typedef struct Bag {
    char *name;
    int weight;
    struct Bag *next;
} Bag;

void createBag(Bag **head) {
    *head = malloc(sizeof(Bag));
    (*head)->name = malloc(20);
    (*head)->weight = rand() % 20;
    (*head)->next = NULL;
}

void addBag(Bag **head) {
    Bag *newBag = malloc(sizeof(Bag));
    newBag->name = malloc(20);
    newBag->weight = rand() % 20;
    newBag->next = NULL;

    if (*head == NULL) {
        *head = newBag;
    } else {
        ((*head)->next = newBag);
        *head = newBag;
    }
}

void handleBags(Bag *head) {
    printf("Bags: ");
    while (head) {
        printf("%s (%d) ", head->name, head->weight);
        head = head->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Bag *head = NULL;

    for (int i = 0; i < MAX_BAGS; i++) {
        addBag(&head);
    }

    handleBags(head);

    return 0;
}