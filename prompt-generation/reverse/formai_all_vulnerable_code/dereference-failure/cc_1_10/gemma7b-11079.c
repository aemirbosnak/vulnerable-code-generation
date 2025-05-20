//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WEIGHT 20
#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int weight;
    struct Item* next;
} Item;

Item* createItem(char* name, int weight) {
    Item* item = (Item*)malloc(sizeof(Item));
    strcpy(item->name, name);
    item->weight = weight;
    item->next = NULL;
    return item;
}

void addItem(Item* head, char* name, int weight) {
    Item* item = createItem(name, weight);
    if (head == NULL) {
        head = item;
    } else {
        head->next = item;
        head = item;
    }
}

void handleBaggage(Item* head) {
    int totalWeight = 0;
    for (Item* item = head; item != NULL; item = item->next) {
        totalWeight += item->weight;
    }
    if (totalWeight <= MAX_WEIGHT) {
        printf("Baggage handling complete.\n");
        printf("Total weight: %d kg.\n", totalWeight);
    } else {
        printf("Overweight baggage. Please reduce the total weight.\n");
    }
}

int main() {
    Item* head = NULL;
    addItem(head, "Laptop", 15);
    addItem(head, "Shoes", 3);
    addItem(head, "Clothes", 5);
    addItem(head, "Books", 2);

    handleBaggage(head);

    return 0;
}