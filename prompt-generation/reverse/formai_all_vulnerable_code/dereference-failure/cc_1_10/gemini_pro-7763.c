//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medical item
typedef struct medical_item {
    char name[50];
    int quantity;
    float price;
} medical_item;

// Define the structure of a medical store
typedef struct medical_store {
    char name[50];
    char address[100];
    int num_items;
    medical_item *items;
} medical_store;

// Create a new medical store
medical_store *create_medical_store(char *name, char *address) {
    medical_store *store = (medical_store *)malloc(sizeof(medical_store));
    strcpy(store->name, name);
    strcpy(store->address, address);
    store->num_items = 0;
    store->items = NULL;
    return store;
}

// Add a new item to the medical store
void add_item(medical_store *store, char *name, int quantity, float price) {
    store->items = (medical_item *)realloc(store->items, (store->num_items + 1) * sizeof(medical_item));
    strcpy(store->items[store->num_items].name, name);
    store->items[store->num_items].quantity = quantity;
    store->items[store->num_items].price = price;
    store->num_items++;
}

// Print the details of the medical store
void print_medical_store(medical_store *store) {
    printf("Medical Store Name: %s\n", store->name);
    printf("Medical Store Address: %s\n", store->address);
    printf("Number of Items in Medical Store: %d\n", store->num_items);
    for (int i = 0; i < store->num_items; i++) {
        printf("Item Name: %s\n", store->items[i].name);
        printf("Item Quantity: %d\n", store->items[i].quantity);
        printf("Item Price: %.2f\n", store->items[i].price);
    }
}

// Main function
int main() {
    // Create a new medical store
    medical_store *store = create_medical_store("ABC Medical Store", "123 Main Street");

    // Add some items to the medical store
    add_item(store, "Paracetamol", 100, 10.0);
    add_item(store, "Ibuprofen", 50, 15.0);
    add_item(store, "Aspirin", 25, 5.0);

    // Print the details of the medical store
    print_medical_store(store);

    return 0;
}