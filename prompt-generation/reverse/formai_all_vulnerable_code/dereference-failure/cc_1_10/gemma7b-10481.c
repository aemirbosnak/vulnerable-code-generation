//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
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

void printInventory(Item* item) {
    printf("Your inventory:");
    while (item) {
        printf(" - %s: %d", item->name, item->quantity);
        item = item->next;
    }
    printf("\n");
}

int main() {
    Item* inventory = NULL;

    // Create a few items
    Item* sword = createItem("Sword", 1);
    Item* potion = createItem("Potion", 3);
    Item* armor = createItem("Armor", 2);

    // Add items to the inventory
    inventory = sword;
    inventory->next = potion;
    inventory->next->next = armor;

    // Print the inventory
    printInventory(inventory);

    // Use the items
    printf("You use your sword to fight a dragon.\n");
    printf("You drink the potion and become stronger.\n");
    printf("You wear the armor and become more protected.\n");

    return 0;
}