//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

Item* createItem(char* name, int quantity) {
    Item* item = malloc(sizeof(Item));
    strcpy(item->name, name);
    item->quantity = quantity;
    item->next = NULL;
    return item;
}

void addToInventory(Item* item) {
    Item* inventory = NULL;
    if (inventory) {
        Item* currentItem = inventory;
        while (currentItem->next) {
            currentItem = currentItem->next;
        }
        currentItem->next = item;
    } else {
        inventory = item;
    }
}

void listInventory() {
    Item* inventory = NULL;
    if (inventory) {
        Item* currentItem = inventory;
        printf("Inventory:\n");
        while (currentItem) {
            printf("%s - %d\n", currentItem->name, currentItem->quantity);
            currentItem = currentItem->next;
        }
    } else {
        printf("Inventory is empty.\n");
    }
}

int main() {
    Item* inventory = NULL;

    // Create some items
    Item* sword = createItem("Sword", 1);
    addToInventory(sword);
    Item* potion = createItem("Potion", 3);
    addToInventory(potion);
    Item* armor = createItem("Armor", 2);
    addToInventory(armor);

    // List inventory
    listInventory();

    // Use items
    sword->quantity--;
    listInventory();

    return 0;
}