//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a baggage item
typedef struct baggage_item {
    char *name;
    int weight;
    struct baggage_item *next;
} baggage_item;

// Define a function to add a baggage item to the end of the list
void add_baggage_item(baggage_item **head, char *name, int weight) {
    baggage_item *new_item = malloc(sizeof(baggage_item));
    new_item->name = strdup(name);
    new_item->weight = weight;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

// Define a function to weigh a baggage item
int weigh_baggage_item(baggage_item *item) {
    return item->weight;
}

// Define a function to calculate the total weight of a baggage
int calculate_total_weight(baggage_item *head) {
    int total_weight = 0;
    baggage_item *item = head;

    while (item) {
        total_weight += weigh_baggage_item(item);
        item = item->next;
    }

    return total_weight;
}

int main() {
    baggage_item *head = NULL;

    // Add some baggage items to the list
    add_baggage_item(&head, "John Doe's suitcase", 50);
    add_baggage_item(&head, "Jane Doe's backpack", 25);
    add_baggage_item(&head, "Peter Pan's trunk", 75);

    // Calculate the total weight of the baggage
    int total_weight = calculate_total_weight(head);

    // Print the total weight
    printf("Total weight: %d", total_weight);

    return 0;
}