//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the baggage handling structure
typedef struct baggage {
    char *name;
    int weight;
    struct baggage *next;
} baggage;

// Function to insert a baggage item into the list
void insert_baggage(baggage **head, char *name, int weight) {
    baggage *new_node = malloc(sizeof(baggage));
    new_node->name = name;
    new_node->weight = weight;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

// Function to calculate the total weight of baggage items
int calculate_total_weight(baggage *head) {
    int total_weight = 0;
    while (head) {
        total_weight += head->weight;
        head = head->next;
    }
    return total_weight;
}

int main() {
    // Create a baggage handling list
    baggage *head = NULL;

    // Insert baggage items
    insert_baggage(&head, "John Doe's suitcase", 50);
    insert_baggage(&head, "Jane Doe's backpack", 25);
    insert_baggage(&head, "Peter Pan's hat", 10);

    // Calculate the total weight of baggage items
    int total_weight = calculate_total_weight(head);

    // Print the total weight
    printf("Total weight of baggage items: %d", total_weight);

    return 0;
}