//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine item
typedef struct {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
    int expiry_month;
    int expiry_year;
} medicine_item;

// Define the structure of a medical store
typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    medicine_item *inventory;
    int num_items;
} medical_store;

// Create a new medical store
medical_store *create_medical_store(char *name, char *address, char *phone) {
    medical_store *store = (medical_store *)malloc(sizeof(medical_store));
    strcpy(store->name, name);
    strcpy(store->address, address);
    strcpy(store->phone, phone);
    store->inventory = NULL;
    store->num_items = 0;
    return store;
}

// Add a new medicine item to the inventory of a medical store
void add_medicine_item(medical_store *store, medicine_item *item) {
    store->inventory = (medicine_item *)realloc(store->inventory, (store->num_items + 1) * sizeof(medicine_item));
    store->inventory[store->num_items] = *item;
    store->num_items++;
}

// Search for a medicine item in the inventory of a medical store by name
medicine_item *find_medicine_item_by_name(medical_store *store, char *name) {
    for (int i = 0; i < store->num_items; i++) {
        if (strcmp(store->inventory[i].name, name) == 0) {
            return &store->inventory[i];
        }
    }
    return NULL;
}

// Print the details of a medical store
void print_medical_store(medical_store *store) {
    printf("Name: %s\n", store->name);
    printf("Address: %s\n", store->address);
    printf("Phone: %s\n", store->phone);
    printf("Inventory:\n");
    for (int i = 0; i < store->num_items; i++) {
        printf(" - %s (%s) - Quantity: %d - Price: %.2f - Expiry: %d/%d\n", store->inventory[i].name, store->inventory[i].manufacturer, store->inventory[i].quantity, store->inventory[i].price, store->inventory[i].expiry_month, store->inventory[i].expiry_year);
    }
}

// Main function
int main() {
    // Create a new medical store
    medical_store *store = create_medical_store("ABC Medical Store", "123 Main Street", "555-1212");

    // Add some medicine items to the inventory of the medical store
    medicine_item item1 = {"Paracetamol", "Johnson & Johnson", 100, 10.00, 12, 2023};
    add_medicine_item(store, &item1);
    medicine_item item2 = {"Ibuprofen", "Bayer", 50, 15.00, 6, 2024};
    add_medicine_item(store, &item2);
    medicine_item item3 = {"Amoxicillin", "GlaxoSmithKline", 25, 20.00, 3, 2025};
    add_medicine_item(store, &item3);

    // Print the details of the medical store
    print_medical_store(store);

    // Search for a medicine item in the inventory of the medical store by name
    medicine_item *item = find_medicine_item_by_name(store, "Ibuprofen");
    if (item != NULL) {
        printf("Found medicine item:\n");
        printf(" - Name: %s\n", item->name);
        printf(" - Manufacturer: %s\n", item->manufacturer);
        printf(" - Quantity: %d\n", item->quantity);
        printf(" - Price: %.2f\n", item->price);
        printf(" - Expiry: %d/%d\n", item->expiry_month, item->expiry_year);
    } else {
        printf("Medicine item not found.\n");
    }

    return 0;
}