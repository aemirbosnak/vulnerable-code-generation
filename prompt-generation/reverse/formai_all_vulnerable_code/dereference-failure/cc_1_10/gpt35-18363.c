//FormAI DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct product {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
    struct product *next;
};

/* Function to add a product to the inventory */
void addProduct(struct product **inventory, int id, char *name, int quantity, double price) {
    struct product *newProduct = (struct product*) malloc(sizeof(struct product));
    newProduct->id = id;
    strncpy(newProduct->name, name, MAX_NAME_LENGTH);
    newProduct->quantity = quantity;
    newProduct->price = price;
    newProduct->next = NULL;

    if (*inventory == NULL) {
        *inventory = newProduct;
    } else {
        struct product *cur = *inventory;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newProduct;
    }
}

/* Function to remove a product from the inventory */
void removeProduct(struct product **inventory, int id) {
    if (*inventory == NULL) {
        printf("Inventory is empty.\n");
    } else {
        struct product *cur = *inventory;
        struct product *prev = NULL;

        while (cur != NULL && cur->id != id) {
            prev = cur;
            cur = cur->next;
        }

        if (cur == NULL) {
            printf("Product with ID %d not found.\n", id);
        } else {
            if (prev == NULL) {
                *inventory = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            printf("Product with ID %d removed from inventory.\n", id);
        }
    }
}

/* Function to display the current inventory */
void displayInventory(struct product *inventory) {
    if (inventory == NULL) {
        printf("Inventory is empty.\n");
    } else {
        printf("Current Inventory:\n");
        struct product *cur = inventory;
        while (cur != NULL) {
            printf("ID: %d\tName: %s\tQuantity: %d\tPrice: %.2f\n", cur->id, cur->name, cur->quantity, cur->price);
            cur = cur->next;
        }
    }
}

int main() {
    struct product *inventory = NULL;

    addProduct(&inventory, 1, "Keyboard", 10, 19.99);
    addProduct(&inventory, 2, "Mouse", 15, 12.99);
    addProduct(&inventory, 3, "Monitor", 5, 119.99);

    displayInventory(inventory);

    removeProduct(&inventory, 2);

    displayInventory(inventory);

    return 0;
}