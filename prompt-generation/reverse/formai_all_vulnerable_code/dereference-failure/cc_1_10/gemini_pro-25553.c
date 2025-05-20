//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines in the store
#define MAX_MEDICINES 100

// Define the structure of a medicine
typedef struct medicine {
    char name[50];
    char description[100];
    int quantity;
    float price;
} medicine;

// Define the structure of the medical store
typedef struct medical_store {
    medicine medicines[MAX_MEDICINES];
    int num_medicines;
} medical_store;

// Create a new medical store
medical_store* create_medical_store() {
    medical_store* store = (medical_store*)malloc(sizeof(medical_store));
    store->num_medicines = 0;
    return store;
}

// Add a new medicine to the store
void add_medicine(medical_store* store, medicine* medicine) {
    if (store->num_medicines < MAX_MEDICINES) {
        store->medicines[store->num_medicines] = *medicine;
        store->num_medicines++;
    } else {
        printf("The store is full. Cannot add any more medicines.\n");
    }
}

// Search for a medicine in the store by name
medicine* search_medicine_by_name(medical_store* store, char* name) {
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            return &store->medicines[i];
        }
    }
    return NULL;
}

// Sell a medicine from the store
void sell_medicine(medical_store* store, char* name, int quantity) {
    medicine* medicine = search_medicine_by_name(store, name);
    if (medicine != NULL) {
        if (medicine->quantity >= quantity) {
            medicine->quantity -= quantity;
            printf("Sold %d units of %s.\n", quantity, medicine->name);
        } else {
            printf("Not enough stock of %s. Only %d units available.\n", medicine->name, medicine->quantity);
        }
    } else {
        printf("Medicine not found.\n");
    }
}

// Print the list of all medicines in the store
void print_medicines(medical_store* store) {
    printf("List of all medicines in the store:\n");
    for (int i = 0; i < store->num_medicines; i++) {
        printf("%s: %s (%d units, %.2f$)\n", store->medicines[i].name, store->medicines[i].description, store->medicines[i].quantity, store->medicines[i].price);
    }
}

// Main function
int main() {
    // Create a new medical store
    medical_store* store = create_medical_store();

    // Add some medicines to the store
    medicine medicine1 = {"Paracetamol", "Paracetamol is a pain reliever and fever reducer.", 100, 10.0};
    add_medicine(store, &medicine1);

    medicine medicine2 = {"Ibuprofen", "Ibuprofen is a non-steroidal anti-inflammatory drug (NSAID) used to relieve pain, fever, and inflammation.", 50, 15.0};
    add_medicine(store, &medicine2);

    medicine medicine3 = {"Aspirin", "Aspirin is a salicylate drug used to relieve pain, fever, and inflammation.", 25, 5.0};
    add_medicine(store, &medicine3);

    // Search for a medicine in the store
    medicine* medicine = search_medicine_by_name(store, "Ibuprofen");
    if (medicine != NULL) {
        printf("Found medicine: %s (%d units, %.2f$)\n", medicine->name, medicine->quantity, medicine->price);
    } else {
        printf("Medicine not found.\n");
    }

    // Sell a medicine from the store
    sell_medicine(store, "Paracetamol", 20);

    // Print the list of all medicines in the store
    print_medicines(store);

    return 0;
}