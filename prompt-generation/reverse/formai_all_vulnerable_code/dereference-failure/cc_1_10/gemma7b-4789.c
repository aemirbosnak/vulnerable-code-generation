//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct item {
    char name[20];
    int quantity;
    struct item* next;
} item_t;

item_t* create_item(char* name, int quantity) {
    item_t* item = malloc(sizeof(item_t));
    strcpy(item->name, name);
    item->quantity = quantity;
    item->next = NULL;
    return item;
}

void add_item(item_t* item, item_t* head) {
    if (head == NULL) {
        head = item;
    } else {
        item->next = head;
        head = item;
    }
}

int main() {
    item_t* inventory = NULL;
    item_t* item_head = NULL;

    // Create a few items
    item_t* item1 = create_item("Sword", 1);
    item_t* item2 = create_item("Shield", 1);
    item_t* item3 = create_item("Potion", 1);

    // Add items to the inventory
    add_item(item1, item_head);
    add_item(item2, item_head);
    add_item(item3, item_head);

    // List the items in the inventory
    printf("Your inventory:\n");
    for (item_t* item = item_head; item; item = item->next) {
        printf("%s (%d)\n", item->name, item->quantity);
    }

    return 0;
}