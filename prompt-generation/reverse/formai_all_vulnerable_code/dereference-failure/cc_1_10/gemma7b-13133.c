//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct baggage_item {
    char name[50];
    int weight;
    struct baggage_item* next;
} baggage_item;

typedef struct baggage_handler {
    baggage_item* head;
    int total_weight;
    struct baggage_handler* next;
} baggage_handler;

baggage_handler* create_handler() {
    baggage_handler* handler = malloc(sizeof(baggage_handler));
    handler->head = NULL;
    handler->total_weight = 0;
    handler->next = NULL;
    return handler;
}

void add_item(baggage_handler* handler, char* name, int weight) {
    baggage_item* item = malloc(sizeof(baggage_item));
    strcpy(item->name, name);
    item->weight = weight;
    item->next = NULL;

    if (handler->head == NULL) {
        handler->head = item;
    } else {
        handler->head->next = item;
    }

    handler->total_weight += item->weight;
}

void handle_baggage(baggage_handler* handler) {
    printf("Total weight: %d\n", handler->total_weight);
    printf("Items:\n");
    baggage_item* item = handler->head;
    while (item) {
        printf("  - %s (%.2f kg)\n", item->name, item->weight);
        item = item->next;
    }
}

int main() {
    baggage_handler* handler = create_handler();

    add_item(handler, "Laptop", 10);
    add_item(handler, "Phone", 2);
    add_item(handler, "Book", 4);
    add_item(handler, "Clothes", 6);

    handle_baggage(handler);

    return 0;
}