//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the store
#define MAX_ITEMS 100

// Define the structure of an item in the store
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
    MedicalStore* store = malloc(sizeof(MedicalStore));
    store->num_items = 0;
    return store;
}

// Add an item to the medical store
void add_item(MedicalStore* store, Item item) {
    if (store->num_items < MAX_ITEMS) {
        store->items[store->num_items] = item;
        store->num_items++;
    } else {
        printf("The store is full.\n");
    }
}

// Get an item from the medical store by name
Item* get_item(MedicalStore* store, char* name) {
    for (int i = 0; i < store->num_items; i++) {
        if (strcmp(store->items[i].name, name) == 0) {
            return &store->items[i];
        }
    }
    return NULL;
}

// Print the items in the medical store
void print_items(MedicalStore* store) {
    for (int i = 0; i < store->num_items; i++) {
        printf("%s %d %.2f\n", store->items[i].name, store->items[i].quantity, store->items[i].price);
    }
}

// Free the memory allocated for the medical store
void free_medical_store(MedicalStore* store) {
    free(store);
}

// Main function
int main() {
    // Create a new medical store
    MedicalStore* store = create_medical_store();

    // Add some items to the medical store
    Item item1 = {"Aspirin", 10, 0.50};
    add_item(store, item1);
    Item item2 = {"Ibuprofen", 5, 1.00};
    add_item(store, item2);
    Item item3 = {"Acetaminophen", 15, 0.75};
    add_item(store, item3);

    // Print the items in the medical store
    printf("Items in the medical store:\n");
    print_items(store);

    // Get an item from the medical store by name
    Item* item = get_item(store, "Ibuprofen");
    if (item != NULL) {
        printf("Found item: %s %d %.2f\n", item->name, item->quantity, item->price);
    } else {
        printf("Item not found.\n");
    }

    // Free the memory allocated for the medical store
    free_medical_store(store);

    return 0;
}