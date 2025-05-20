//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medical item
typedef struct medical_item {
    char name[50];
    char description[100];
    int quantity;
    float price;
} medical_item;

// Define the structure of a medical store
typedef struct medical_store {
    char name[50];
    char address[100];
    char phone[20];
    medical_item *items;
    int num_items;
} medical_store;

// Function to create a new medical item
medical_item *create_medical_item(char *name, char *description, int quantity, float price) {
    medical_item *item = malloc(sizeof(medical_item));
    strcpy(item->name, name);
    strcpy(item->description, description);
    item->quantity = quantity;
    item->price = price;
    return item;
}

// Function to create a new medical store
medical_store *create_medical_store(char *name, char *address, char *phone) {
    medical_store *store = malloc(sizeof(medical_store));
    strcpy(store->name, name);
    strcpy(store->address, address);
    strcpy(store->phone, phone);
    store->items = NULL;
    store->num_items = 0;
    return store;
}

// Function to add a new medical item to a medical store
void add_medical_item(medical_store *store, medical_item *item) {
    store->items = realloc(store->items, (store->num_items + 1) * sizeof(medical_item));
    store->items[store->num_items] = *item;
    store->num_items++;
}

// Function to print the details of a medical item
void print_medical_item(medical_item *item) {
    printf("Name: %s\n", item->name);
    printf("Description: %s\n", item->description);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: %.2f\n", item->price);
}

// Function to print the details of a medical store
void print_medical_store(medical_store *store) {
    printf("Name: %s\n", store->name);
    printf("Address: %s\n", store->address);
    printf("Phone: %s\n", store->phone);
    printf("Number of items: %d\n", store->num_items);
    for (int i = 0; i < store->num_items; i++) {
        print_medical_item(&store->items[i]);
    }
}

// Function to main
int main() {
    // Create a new medical item
    medical_item *item1 = create_medical_item("Paracetamol", "Pain reliever", 100, 10.0);

    // Create a new medical store
    medical_store *store1 = create_medical_store("Apollo Pharmacy", "123 Main Street", "1234567890");

    // Add the medical item to the medical store
    add_medical_item(store1, item1);

    // Print the details of the medical store
    print_medical_store(store1);

    return 0;
}