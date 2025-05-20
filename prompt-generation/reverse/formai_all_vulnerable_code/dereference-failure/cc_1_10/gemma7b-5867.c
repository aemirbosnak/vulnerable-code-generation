//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAG_NUMBER 10
#define MAX_BAG_WEIGHT 20

typedef struct Bag {
    char *name;
    int weight;
    struct Bag *next;
} Bag;

Bag *createBag(char *name, int weight) {
    Bag *newBag = malloc(sizeof(Bag));
    newBag->name = strdup(name);
    newBag->weight = weight;
    newBag->next = NULL;

    return newBag;
}

void addBag(Bag **head, char *name, int weight) {
    Bag *newBag = createBag(name, weight);

    if (*head == NULL) {
        *head = newBag;
    } else {
        (*head)->next = newBag;
    }
}

void printBags(Bag *head) {
    while (head) {
        printf("%s (%.2f kg)\n", head->name, head->weight);
        head = head->next;
    }
}

int main() {
    Bag *bags = NULL;

    addBag(&bags, "John Doe's Bag", 15);
    addBag(&bags, "Jane Doe's Bag", 12);
    addBag(&bags, "Jack Smith's Bag", 18);

    printBags(bags);

    return 0;
}