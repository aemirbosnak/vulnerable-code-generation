//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a baggage item
typedef struct baggage_item {
    char *name;
    int weight;
    struct baggage_item *next;
} baggage_item;

// Function to insert a baggage item into the list
void insert_baggage(baggage_item **head, char *name, int weight) {
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

// Function to handle baggage at the airport
void handle_baggage(baggage_item **head) {
    // Print the list of baggage items
    baggage_item *current = *head;
    while (current) {
        printf("%s (%d) ", current->name, current->weight);
        current = current->next;
    }

    // Calculate the total weight of the baggage
    int total_weight = 0;
    current = *head;
    while (current) {
        total_weight += current->weight;
        current = current->next;
    }

    // Print the total weight of the baggage
    printf("\nTotal weight: %d", total_weight);
}

int main() {
    // Create a list of baggage items
    baggage_item *head = NULL;
    insert_baggage(&head, "John Doe's suitcase", 50);
    insert_baggage(&head, "Jane Doe's backpack", 20);
    insert_baggage(&head, "Tom Smith's bag", 30);

    // Handle the baggage
    handle_baggage(&head);

    return 0;
}