//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of drugs in the store
#define MAX_DRUGS 100

// Define the structure of a drug
typedef struct drug {
    char name[50];
    int quantity;
    float price;
} drug;

// Define the structure of the medical store
typedef struct medical_store {
    drug drugs[MAX_DRUGS];
    int num_drugs;
} medical_store;

// Create a new medical store
medical_store* create_medical_store() {
    medical_store* store = (medical_store*)malloc(sizeof(medical_store));
    store->num_drugs = 0;
    return store;
}

// Add a new drug to the medical store
void add_drug(medical_store* store, char* name, int quantity, float price) {
    if (store->num_drugs == MAX_DRUGS) {
        printf("Error: The medical store is full.\n");
        return;
    }

    strcpy(store->drugs[store->num_drugs].name, name);
    store->drugs[store->num_drugs].quantity = quantity;
    store->drugs[store->num_drugs].price = price;

    store->num_drugs++;
}

// Find a drug in the medical store by name
drug* find_drug(medical_store* store, char* name) {
    for (int i = 0; i < store->num_drugs; i++) {
        if (strcmp(store->drugs[i].name, name) == 0) {
            return &store->drugs[i];
        }
    }

    return NULL;
}

// Sell a certain quantity of a drug in the medical store
void sell_drug(medical_store* store, char* name, int quantity) {
    drug* drug = find_drug(store, name);

    if (drug == NULL) {
        printf("Error: The drug %s is not available in the medical store.\n", name);
        return;
    }

    if (drug->quantity < quantity) {
        printf("Error: The quantity of the drug %s is not sufficient in the medical store.\n", name);
        return;
    }

    drug->quantity -= quantity;
}

// Print the inventory of the medical store
void print_inventory(medical_store* store) {
    printf("Inventory of the medical store:\n");
    for (int i = 0; i < store->num_drugs; i++) {
        printf("%s: %d units, %.2f$\n", store->drugs[i].name, store->drugs[i].quantity, store->drugs[i].price);
    }
}

// Main function
int main() {
    // Create a new medical store
    medical_store* store = create_medical_store();

    // Add some drugs to the medical store
    add_drug(store, "Aspirin", 100, 1.0);
    add_drug(store, "Ibuprofen", 50, 1.5);
    add_drug(store, "Paracetamol", 200, 0.5);

    // Print the inventory of the medical store
    print_inventory(store);

    // Sell some drugs from the medical store
    sell_drug(store, "Aspirin", 50);
    sell_drug(store, "Ibuprofen", 25);

    // Print the inventory of the medical store again
    print_inventory(store);

    return 0;
}