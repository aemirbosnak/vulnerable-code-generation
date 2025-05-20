//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the store
#define MAX_ITEMS 100

// Define the structure of an item in the store
typedef struct {
    int id;
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
MedicalStore *create_medical_store() {
    MedicalStore *store = (MedicalStore *)malloc(sizeof(MedicalStore));
    store->num_items = 0;
    return store;
}

// Add an item to the medical store
void add_item(MedicalStore *store, Item item) {
    store->items[store->num_items] = item;
    store->num_items++;
}

// Find an item in the medical store by its ID
Item *find_item_by_id(MedicalStore *store, int id) {
    for (int i = 0; i < store->num_items; i++) {
        if (store->items[i].id == id) {
            return &store->items[i];
        }
    }
    return NULL;
}

// Find an item in the medical store by its name
Item *find_item_by_name(MedicalStore *store, char *name) {
    for (int i = 0; i < store->num_items; i++) {
        if (strcmp(store->items[i].name, name) == 0) {
            return &store->items[i];
        }
    }
    return NULL;
}

// Print the items in the medical store
void print_items(MedicalStore *store) {
    printf("Items in the medical store:\n");
    for (int i = 0; i < store->num_items; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
            store->items[i].id, store->items[i].name, store->items[i].quantity, store->items[i].price);
    }
}

// Free the memory allocated for the medical store
void free_medical_store(MedicalStore *store) {
    free(store);
}

// Main function
int main() {
    // Create a new medical store
    MedicalStore *store = create_medical_store();

    // Add some items to the medical store
    Item item1 = {1, "Paracetamol", 100, 10.0};
    add_item(store, item1);

    Item item2 = {2, "Ibuprofen", 50, 15.0};
    add_item(store, item2);

    Item item3 = {3, "Aspirin", 25, 5.0};
    add_item(store, item3);

    // Print the items in the medical store
    print_items(store);

    // Find an item in the medical store by its ID
    Item *item = find_item_by_id(store, 2);
    if (item != NULL) {
        printf("Item found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
            item->id, item->name, item->quantity, item->price);
    } else {
        printf("Item not found.\n");
    }

    // Find an item in the medical store by its name
    item = find_item_by_name(store, "Ibuprofen");
    if (item != NULL) {
        printf("Item found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
            item->id, item->name, item->quantity, item->price);
    } else {
        printf("Item not found.\n");
    }

    // Free the memory allocated for the medical store
    free_medical_store(store);

    return 0;
}