//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines that can be stored
#define MAX_MEDICINES 100

// Define the structure of a medicine
typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} medicine;

// Define the structure of the medical store
typedef struct medical_store {
    medicine medicines[MAX_MEDICINES];
    int num_medicines;
} medical_store;

// Create a new medical store
medical_store *create_medical_store() {
    medical_store *store = (medical_store *)malloc(sizeof(medical_store));
    store->num_medicines = 0;
    return store;
}

// Add a new medicine to the store
void add_medicine(medical_store *store, char *name, float price, int quantity) {
    strcpy(store->medicines[store->num_medicines].name, name);
    store->medicines[store->num_medicines].price = price;
    store->medicines[store->num_medicines].quantity = quantity;
    store->num_medicines++;
}

// Search for a medicine in the store
medicine *search_medicine(medical_store *store, char *name) {
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            return &store->medicines[i];
        }
    }
    return NULL;
}

// Sell a medicine from the store
void sell_medicine(medical_store *store, char *name, int quantity) {
    medicine *medicine = search_medicine(store, name);
    if (medicine != NULL) {
        if (medicine->quantity >= quantity) {
            medicine->quantity -= quantity;
            printf("Sold %d units of %s\n", quantity, medicine->name);
        } else {
            printf("Insufficient quantity of %s\n", medicine->name);
        }
    } else {
        printf("Medicine not found\n");
    }
}

// Print the inventory of the store
void print_inventory(medical_store *store) {
    printf("Inventory:\n");
    for (int i = 0; i < store->num_medicines; i++) {
        printf("%s %.2f %d\n", store->medicines[i].name, store->medicines[i].price, store->medicines[i].quantity);
    }
}

// Free the memory allocated to the store
void free_medical_store(medical_store *store) {
    free(store);
}

// Main function
int main() {
    // Create a new medical store
    medical_store *store = create_medical_store();

    // Add some medicines to the store
    add_medicine(store, "Paracetamol", 10.0, 100);
    add_medicine(store, "Ibuprofen", 15.0, 50);
    add_medicine(store, "Aspirin", 5.0, 200);

    // Print the inventory of the store
    print_inventory(store);

    // Sell some medicines from the store
    sell_medicine(store, "Paracetamol", 50);
    sell_medicine(store, "Ibuprofen", 25);

    // Print the inventory of the store
    print_inventory(store);

    // Free the memory allocated to the store
    free_medical_store(store);

    return 0;
}