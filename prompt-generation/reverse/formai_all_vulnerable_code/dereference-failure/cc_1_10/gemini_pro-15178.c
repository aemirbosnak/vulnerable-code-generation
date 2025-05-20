//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the store
#define MAX_ITEMS 100

// Define the structure of an item in the store
typedef struct {
    char name[50];
    float price;
    int quantity;
} item_t;

// Define the structure of the medical store
typedef struct {
    item_t items[MAX_ITEMS];
    int num_items;
} medical_store_t;

// Create a new medical store
medical_store_t* create_medical_store() {
    medical_store_t* store = malloc(sizeof(medical_store_t));
    if (store == NULL) {
        return NULL;
    }

    store->num_items = 0;

    return store;
}

// Add an item to the medical store
int add_item(medical_store_t* store, item_t item) {
    if (store->num_items >= MAX_ITEMS) {
        return -1;
    }

    store->items[store->num_items++] = item;

    return 0;
}

// Search for an item in the medical store by name
item_t* search_item(medical_store_t* store, char* name) {
    for (int i = 0; i < store->num_items; i++) {
        if (strcmp(store->items[i].name, name) == 0) {
            return &store->items[i];
        }
    }

    return NULL;
}

// Delete an item from the medical store by name
int delete_item(medical_store_t* store, char* name) {
    item_t* item = search_item(store, name);
    if (item == NULL) {
        return -1;
    }

    for (int i = 0; i < store->num_items - 1; i++) {
        if (&store->items[i] == item) {
            store->items[i] = store->items[i + 1];
        }
    }

    store->num_items--;

    return 0;
}

// Print the contents of the medical store
void print_medical_store(medical_store_t* store) {
    printf("Medical Store:\n");
    for (int i = 0; i < store->num_items; i++) {
        printf("\t%s: $%.2f (%d)\n", store->items[i].name, store->items[i].price, store->items[i].quantity);
    }
}

// Free the memory allocated for the medical store
void free_medical_store(medical_store_t* store) {
    free(store);
}

// Main function
int main() {
    // Create a new medical store
    medical_store_t* store = create_medical_store();

    // Add some items to the medical store
    item_t item1 = {"Aspirin", 0.50, 100};
    add_item(store, item1);

    item_t item2 = {"Ibuprofen", 1.00, 50};
    add_item(store, item2);

    item_t item3 = {"Acetaminophen", 0.75, 75};
    add_item(store, item3);

    // Print the contents of the medical store
    print_medical_store(store);

    // Search for an item in the medical store
    item_t* item = search_item(store, "Ibuprofen");
    if (item != NULL) {
        printf("Item found: %s\n", item->name);
    } else {
        printf("Item not found.\n");
    }

    // Delete an item from the medical store
    delete_item(store, "Acetaminophen");

    // Print the contents of the medical store
    print_medical_store(store);

    // Free the memory allocated for the medical store
    free_medical_store(store);

    return 0;
}