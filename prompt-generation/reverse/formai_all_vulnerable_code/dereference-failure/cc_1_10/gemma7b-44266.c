//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAG_NUMBER 100
#define MAX_BAG_WEIGHT 50

typedef struct Bag {
    char *name;
    int weight;
    struct Bag *next;
} Bag;

void create_bag(Bag **head) {
    *head = malloc(sizeof(Bag));
    (*head)->name = malloc(20);
    (*head)->weight = 0;
    (*head)->next = NULL;
}

void add_bag(Bag **head, char *name, int weight) {
    Bag *new_bag = malloc(sizeof(Bag));
    new_bag->name = malloc(20);
    new_bag->weight = weight;
    new_bag->next = NULL;

    if (*head == NULL) {
        *head = new_bag;
    } else {
        ((*head)->next = new_bag);
        *head = new_bag;
    }
}

void handle_baggage(Bag *head) {
    while (head) {
        printf("Bag name: %s, Weight: %d\n", head->name, head->weight);
        head = head->next;
    }
}

int main() {
    Bag *head = NULL;

    create_bag(&head);
    add_bag(&head, "John Doe's Bag", 25);
    add_bag(&head, "Jane Doe's Bag", 30);
    add_bag(&head, "Peter Pan's Bag", 40);

    handle_baggage(head);

    return 0;
}