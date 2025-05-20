//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: retro
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_BAGS 10

typedef struct Bag {
    char *name;
    int weight;
    struct Bag *next;
} Bag;

void addBag(Bag **head, char *name, int weight) {
    Bag *newBag = malloc(sizeof(Bag));
    newBag->name = strdup(name);
    newBag->weight = weight;
    newBag->next = NULL;

    if (*head == NULL) {
        *head = newBag;
    } else {
        (*head)->next = newBag;
    }
}

void handleBags(Bag *head) {
    printf("*** Handling Bags at the C Airport ***\n");
    printf("------------------------\n");

    while (head) {
        printf("Bag Name: %s\n", head->name);
        printf("Bag Weight: %d kg\n", head->weight);
        printf("\n");
        head = head->next;
    }

    printf("------------------------\n");
    printf("Thank you for choosing the C Airport Baggage Handling System!\n");
}

int main() {
    Bag *head = NULL;

    // Add some bags to the system
    addBag(&head, "John Doe's Bag", 20);
    addBag(&head, "Jane Doe's Bag", 15);
    addBag(&head, "Mr. Smith's Bag", 30);

    // Handle the bags
    handleBags(head);

    return 0;
}