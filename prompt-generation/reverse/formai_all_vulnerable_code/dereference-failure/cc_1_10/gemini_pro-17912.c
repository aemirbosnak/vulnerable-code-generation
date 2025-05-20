//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char *name;
    int quantity;
    float price;
} item_t;

item_t items[MAX_ITEMS];

int main(void) {
    // Initialize the warehouse
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].name = NULL;
        items[i].quantity = 0;
        items[i].price = 0.0f;
    }

    // Add some items to the warehouse
    strcpy(items[0].name, "Bananas");
    items[0].quantity = 100;
    items[0].price = 0.50f;

    strcpy(items[1].name, "Apples");
    items[1].quantity = 50;
    items[1].price = 0.75f;

    strcpy(items[2].name, "Oranges");
    items[2].quantity = 25;
    items[2].price = 1.00f;

    // Print the contents of the warehouse
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name != NULL) {
            printf("  - %s: %d @ $%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }

    // Free the memory allocated for the items
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name != NULL) {
            free(items[i].name);
        }
    }

    return 0;
}