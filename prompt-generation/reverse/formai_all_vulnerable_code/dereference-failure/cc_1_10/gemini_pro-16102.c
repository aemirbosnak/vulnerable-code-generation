//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medical item
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Define the structure of a medical store
typedef struct {
    char name[50];
    char address[100];
    Item items[100];
    int numItems;
} Store;

// Create a new medical store
Store* createStore(char* name, char* address) {
    Store* store = (Store*)malloc(sizeof(Store));
    strcpy(store->name, name);
    strcpy(store->address, address);
    store->numItems = 0;
    return store;
}

// Add a new item to a medical store
void addItem(Store* store, Item item) {
    store->items[store->numItems] = item;
    store->numItems++;
}

// Find an item in a medical store by name
Item* findItemByName(Store* store, char* name) {
    for (int i = 0; i < store->numItems; i++) {
        if (strcmp(store->items[i].name, name) == 0) {
            return &store->items[i];
        }
    }
    return NULL;
}

// Print the details of a medical store
void printStore(Store* store) {
    printf("Name: %s\n", store->name);
    printf("Address: %s\n", store->address);
    printf("Items:\n");
    for (int i = 0; i < store->numItems; i++) {
        printf("- %s (%d, %.2f)\n", store->items[i].name, store->items[i].quantity, store->items[i].price);
    }
}

// Main function
int main() {
    // Create a new medical store
    Store* store = createStore("Your Heart's Desire", "123 Main Street");

    // Add some items to the store
    Item item1 = {"Bandages", 100, 1.00};
    addItem(store, item1);
    Item item2 = {"Aspirin", 50, 0.50};
    addItem(store, item2);
    Item item3 = {"Cough Syrup", 25, 2.00};
    addItem(store, item3);

    // Print the details of the store
    printStore(store);

    // Find an item in the store by name
    Item* item = findItemByName(store, "Bandages");
    if (item != NULL) {
        printf("Found item: %s (%d, %.2f)\n", item->name, item->quantity, item->price);
    } else {
        printf("Item not found.\n");
    }

    return 0;
}