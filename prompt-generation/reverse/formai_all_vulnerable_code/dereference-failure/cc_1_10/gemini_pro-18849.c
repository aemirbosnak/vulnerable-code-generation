//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the inventory
#define MAX_ITEMS 100

// Define the structure of an item in the inventory
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Define the structure of the medical store
typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} MedicalStore;

// Create a new medical store
MedicalStore* create_medical_store() {
    MedicalStore* store = (MedicalStore*)malloc(sizeof(MedicalStore));
    store->num_items = 0;
    return store;
}

// Add an item to the medical store
void add_item(MedicalStore* store, Item item) {
    if (store->num_items < MAX_ITEMS) {
        store->items[store->num_items++] = item;
    } else {
        printf("Error: The medical store is full.\n");
    }
}

// Remove an item from the medical store
void remove_item(MedicalStore* store, char* name) {
    int i;
    for (i = 0; i < store->num_items; i++) {
        if (strcmp(store->items[i].name, name) == 0) {
            break;
        }
    }
    if (i < store->num_items) {
        for (int j = i; j < store->num_items - 1; j++) {
            store->items[j] = store->items[j + 1];
        }
        store->num_items--;
    } else {
        printf("Error: The item does not exist in the medical store.\n");
    }
}

// Print the inventory of the medical store
void print_inventory(MedicalStore* store) {
    printf("Inventory of the medical store:\n");
    for (int i = 0; i < store->num_items; i++) {
        printf("%s %d %.2f\n", store->items[i].name, store->items[i].quantity, store->items[i].price);
    }
}

// Main function
int main() {
    // Create a new medical store
    MedicalStore* store = create_medical_store();

    // Add some items to the medical store
    Item item1 = {"Aspirin", 100, 1.00};
    add_item(store, item1);
    Item item2 = {"Ibuprofen", 50, 2.00};
    add_item(store, item2);
    Item item3 = {"Acetaminophen", 75, 3.00};
    add_item(store, item3);

    // Print the inventory of the medical store
    print_inventory(store);

    // Remove an item from the medical store
    remove_item(store, "Ibuprofen");

    // Print the inventory of the medical store
    print_inventory(store);

    // Free the memory allocated for the medical store
    free(store);

    return 0;
}