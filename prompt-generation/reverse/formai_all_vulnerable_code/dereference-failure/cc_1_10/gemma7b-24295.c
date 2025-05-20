//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct item {
    char name[20];
    int quantity;
    struct item* next;
} item;

void initialize_inventory(item** inventory) {
    *inventory = NULL;
}

void add_item(item** inventory, char name, int quantity) {
    item* new_item = malloc(sizeof(item));
    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    new_item->next = NULL;

    if (*inventory) {
        (*inventory)->next = new_item;
    } else {
        *inventory = new_item;
    }
}

void print_inventory(item* inventory) {
    item* current_item = inventory;
    printf("Inventory:\n");
    while (current_item) {
        printf("%s (%d) ", current_item->name, current_item->quantity);
        current_item = current_item->next;
    }
    printf("\n");
}

int main() {
    item* inventory;
    initialize_inventory(&inventory);

    add_item(&inventory, "Sword", 1);
    add_item(&inventory, "Shield", 1);
    add_item(&inventory, "Potion", 2);

    print_inventory(inventory);

    return 0;
}