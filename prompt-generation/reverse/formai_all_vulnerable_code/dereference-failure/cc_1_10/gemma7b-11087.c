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

// Define a function to insert a baggage item into a linked list
void insert_baggage_item(baggage_item **head, char *name, int weight) {
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

// Define a function to calculate the total weight of baggage items
int calculate_total_weight(baggage_item *head) {
    int total_weight = 0;
    while (head) {
        total_weight += head->weight;
        head = head->next;
    }
    return total_weight;
}

// Define a function to handle baggage at the airport
void handle_baggage(baggage_item **head) {
    int total_weight = calculate_total_weight(*head);
    printf("Total weight of baggage items: %d grams\n", total_weight);

    // Check if the total weight exceeds the allowed weight for the flight
    if (total_weight > 2000) {
        printf("Excess baggage weight! Please remove items to bring the total weight within the allowed limit.\n");
    } else {
        printf("Baggage handling complete.\n");
    }
}

int main() {
    baggage_item *head = NULL;

    // Insert baggage items into the linked list
    insert_baggage_item(&head, "John Doe's suitcase", 1500);
    insert_baggage_item(&head, "Jane Doe's handbag", 500);
    insert_baggage_item(&head, "Peter Pan's backpack", 200);

    // Handle baggage at the airport
    handle_baggage(&head);

    return 0;
}