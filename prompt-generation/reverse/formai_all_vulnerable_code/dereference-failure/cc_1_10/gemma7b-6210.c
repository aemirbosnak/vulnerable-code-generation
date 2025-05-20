//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAG_SIZE 50

typedef struct baggage_item {
    char *name;
    int weight;
    struct baggage_item *next;
} baggage_item_t;

baggage_item_t *create_baggage_item(char *name, int weight) {
    baggage_item_t *item = malloc(sizeof(baggage_item_t));
    item->name = strdup(name);
    item->weight = weight;
    item->next = NULL;
    return item;
}

void add_baggage_item(baggage_item_t *item, baggage_item_t **head) {
    if (*head == NULL) {
        *head = item;
    } else {
        (*head)->next = item;
        *head = item;
    }
}

void print_baggage(baggage_item_t *item) {
    printf("%s (%d) ", item->name, item->weight);
}

int main() {
    baggage_item_t *head = NULL;
    add_baggage_item(create_baggage_item("Laptop", 20), &head);
    add_baggage_item(create_baggage_item("Phone", 5), &head);
    add_baggage_item(create_baggage_item("Shoes", 10), &head);
    add_baggage_item(create_baggage_item("Clothes", 25), &head);

    printf("Items in the baggage:");
    print_baggage(head);
    printf("\nTotal weight:");
    int total_weight = 0;
    for (baggage_item_t *item = head; item; item = item->next) {
        total_weight += item->weight;
    }
    printf("%d", total_weight);

    return 0;
}