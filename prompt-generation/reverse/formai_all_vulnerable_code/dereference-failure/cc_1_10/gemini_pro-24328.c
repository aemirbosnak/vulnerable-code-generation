//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: innovative
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
    char name[50];
    char address[100];
    char phone[20];
    Item items[MAX_ITEMS];
    int num_items;
} MedicalStore;

// Create a new medical store
MedicalStore* create_medical_store(char *name, char *address, char *phone) {
    MedicalStore *store = (MedicalStore*)malloc(sizeof(MedicalStore));
    strcpy(store->name, name);
    strcpy(store->address, address);
    strcpy(store->phone, phone);
    store->num_items = 0;
    return store;
}

// Add an item to the medical store
void add_item(MedicalStore *store, Item item) {
    if (store->num_items < MAX_ITEMS) {
        store->items[store->num_items] = item;
        store->num_items++;
    } else {
        printf("Error: The medical store is full.\n");
    }
}

// Remove an item from the medical store
void remove_item(MedicalStore *store, char *name) {
    int i;
    for (i = 0; i < store->num_items; i++) {
        if (strcmp(store->items[i].name, name) == 0) {
            store->items[i] = store->items[store->num_items - 1];
            store->num_items--;
            break;
        }
    }
}

// Print the inventory of the medical store
void print_inventory(MedicalStore *store) {
    int i;
    printf("Inventory of %s:\n", store->name);
    printf("=========================================\n");
    printf("Name\t\tQuantity\tPrice\n");
    printf("-----------------------------------------\n");
    for (i = 0; i < store->num_items; i++) {
        printf("%s\t\t%d\t\t%.2f\n", store->items[i].name, store->items[i].quantity, store->items[i].price);
    }
    printf("=========================================\n");
}

// Get the total value of the inventory
float get_total_value(MedicalStore *store) {
    int i;
    float total_value = 0.0;
    for (i = 0; i < store->num_items; i++) {
        total_value += store->items[i].quantity * store->items[i].price;
    }
    return total_value;
}

// Main function
int main() {
    // Create a new medical store
    MedicalStore *store = create_medical_store("XYZ Medical Store", "123 Main Street", "555-1212");

    // Add some items to the medical store
    Item item1 = {"Aspirin", 100, 2.99};
    add_item(store, item1);
    Item item2 = {"Ibuprofen", 50, 3.99};
    add_item(store, item2);
    Item item3 = {"Acetaminophen", 75, 4.99};
    add_item(store, item3);

    // Print the inventory of the medical store
    print_inventory(store);

    // Get the total value of the inventory
    float total_value = get_total_value(store);
    printf("Total value of inventory: %.2f\n", total_value);

    // Remove an item from the medical store
    remove_item(store, "Ibuprofen");

    // Print the inventory of the medical store
    print_inventory(store);

    // Free the memory allocated for the medical store
    free(store);

    return 0;
}