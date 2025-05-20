//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAG_WEIGHT 20

typedef struct baggage_item {
    char *name;
    int weight;
    struct baggage_item *next;
} baggage_item;

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

int calculate_total_weight(baggage_item *head) {
    int total_weight = 0;
    while (head) {
        total_weight += head->weight;
        head = head->next;
    }
    return total_weight;
}

int main() {
    baggage_item *head = NULL;

    insert_baggage(&head, "Laptop", 15);
    insert_baggage(&head, "Smartphone", 8);
    insert_baggage(&head, "Handbag", 12);
    insert_baggage(&head, "Shoes", 6);

    int total_weight = calculate_total_weight(head);

    if (total_weight <= MAX_BAG_WEIGHT) {
        printf("Total weight: %d, within limit of %d.\n", total_weight, MAX_BAG_WEIGHT);
    } else {
        printf("Total weight: %d, exceeding limit of %d.\n", total_weight, MAX_BAG_WEIGHT);
    }

    return 0;
}