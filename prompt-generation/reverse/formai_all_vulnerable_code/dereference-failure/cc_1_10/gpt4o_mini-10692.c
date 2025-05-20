//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME 100
#define INITIAL_CAPACITY 2

typedef struct {
    char *name;
    int quantity;
    float price;
} Item;

typedef struct {
    Item *items;
    int size;
    int capacity;
} Inventory;

// Function prototypes
Inventory* create_inventory();
void add_item(Inventory *inventory, const char *name, int quantity, float price);
void view_inventory(const Inventory *inventory);
void delete_item(Inventory *inventory, const char *name);
void free_inventory(Inventory *inventory);

int main() {
    Inventory *inventory = create_inventory();
    int choice;
    char name[MAX_ITEM_NAME];
    int quantity;
    float price;

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. View Inventory\n");
        printf("3. Delete Item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                add_item(inventory, name, quantity, price);
                break;
            case 2:
                view_inventory(inventory);
                break;
            case 3:
                printf("Enter item name to delete: ");
                scanf("%s", name);
                delete_item(inventory, name);
                break;
            case 4:
                free_inventory(inventory);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

Inventory* create_inventory() {
    Inventory *inventory = (Inventory *)malloc(sizeof(Inventory));
    inventory->items = (Item *)malloc(INITIAL_CAPACITY * sizeof(Item));
    inventory->size = 0;
    inventory->capacity = INITIAL_CAPACITY;
    return inventory;
}

void add_item(Inventory *inventory, const char *name, int quantity, float price) {
    if (inventory->size == inventory->capacity) {
        inventory->capacity *= 2;
        inventory->items = (Item *)realloc(inventory->items, inventory->capacity * sizeof(Item));
    }
    inventory->items[inventory->size].name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(inventory->items[inventory->size].name, name);
    inventory->items[inventory->size].quantity = quantity;
    inventory->items[inventory->size].price = price;
    inventory->size++;
    printf("Item '%s' added to inventory.\n", name);
}

void view_inventory(const Inventory *inventory) {
    if (inventory->size == 0) {
        printf("The inventory is empty.\n");
        return;
    }
    printf("\nCurrent Inventory:\n");
    printf("-------------------------------------------------\n");
    printf("| %-20s | %-8s | %-8s |\n", "Item Name", "Quantity", "Price");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < inventory->size; i++) {
        printf("| %-20s | %-8d | $%-8.2f |\n", inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
    printf("-------------------------------------------------\n");
}

void delete_item(Inventory *inventory, const char *name) {
    int found = -1;
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        free(inventory->items[found].name);
        for (int i = found; i < inventory->size - 1; i++) {
            inventory->items[i] = inventory->items[i + 1];
        }
        inventory->size--;
        printf("Item '%s' deleted from inventory.\n", name);
    } else {
        printf("Item '%s' not found in inventory.\n", name);
    }
}

void free_inventory(Inventory *inventory) {
    for (int i = 0; i < inventory->size; i++) {
        free(inventory->items[i].name);
    }
    free(inventory->items);
    free(inventory);
    printf("Inventory freed successfully.\n");
}