//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct Item {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

typedef struct Inventory {
    Item *items;
    int size;
    int capacity;
} Inventory;

// Function prototypes
Inventory* createInventory(int capacity);
void addItem(Inventory *inventory, const char *name, int quantity);
void viewInventory(Inventory *inventory);
void removeItem(Inventory *inventory, const char *name);
void freeInventory(Inventory *inventory);

int main() {
    int capacity = 10;
    Inventory *inventory = createInventory(capacity);
    int choice;
    char name[MAX_NAME_LENGTH];
    int quantity;

    do {
        printf("\n=== Inventory Management ===\n");
        printf("1. Add Item\n");
        printf("2. View Inventory\n");
        printf("3. Remove Item\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline after the number input

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                addItem(inventory, name, quantity);
                break;

            case 2:
                viewInventory(inventory);
                break;

            case 3:
                printf("Enter item name to remove: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;
                removeItem(inventory, name);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    freeInventory(inventory);
    return 0;
}

Inventory* createInventory(int capacity) {
    Inventory *inventory = (Inventory *)malloc(sizeof(Inventory));
    inventory->items = (Item *)calloc(capacity, sizeof(Item));
    inventory->size = 0;
    inventory->capacity = capacity;
    return inventory;
}

void addItem(Inventory *inventory, const char *name, int quantity) {
    if (inventory->size >= inventory->capacity) {
        inventory->capacity *= 2;
        inventory->items = (Item *)realloc(inventory->items, inventory->capacity * sizeof(Item));
        if (inventory->items == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    strcpy(inventory->items[inventory->size].name, name);
    inventory->items[inventory->size].quantity = quantity;
    inventory->size++;
    printf("Item '%s' added with quantity %d\n", name, quantity);
}

void viewInventory(Inventory *inventory) {
    if (inventory->size == 0) {
        printf("The inventory is empty.\n");
        return;
    }
    printf("\n=== Inventory ===\n");
    for (int i = 0; i < inventory->size; i++) {
        printf("Item: %s, Quantity: %d\n", inventory->items[i].name, inventory->items[i].quantity);
    }
}

void removeItem(Inventory *inventory, const char *name) {
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->size - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->size--;
            printf("Item '%s' removed from inventory.\n", name);
            return;
        }
    }
    printf("Item '%s' not found in inventory.\n", name);
}

void freeInventory(Inventory *inventory) {
    free(inventory->items);
    free(inventory);
}