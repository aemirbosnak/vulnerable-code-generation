//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines that can be stored in the inventory
#define MAX_MEDICINES 100

// Define the structure of a medicine
typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} medicine_t;

// Define the structure of the medical store
typedef struct medical_store {
    medicine_t medicines[MAX_MEDICINES];
    int num_medicines;
} medical_store_t;

// Create a new medical store
medical_store_t* create_medical_store() {
    medical_store_t* store = (medical_store_t*)malloc(sizeof(medical_store_t));
    store->num_medicines = 0;
    return store;
}

// Add a new medicine to the medical store
void add_medicine(medical_store_t* store, char* name, float price, int quantity) {
    // Check if the medical store is full
    if (store->num_medicines >= MAX_MEDICINES) {
        printf("Error: The medical store is full.\n");
        return;
    }

    // Copy the medicine's details into the medical store's inventory
    strcpy(store->medicines[store->num_medicines].name, name);
    store->medicines[store->num_medicines].price = price;
    store->medicines[store->num_medicines].quantity = quantity;

    // Increment the number of medicines in the medical store
    store->num_medicines++;
}

// Search for a medicine in the medical store
medicine_t* search_medicine(medical_store_t* store, char* name) {
    // Iterate over the medicines in the medical store
    for (int i = 0; i < store->num_medicines; i++) {
        // Check if the medicine's name matches the given name
        if (strcmp(store->medicines[i].name, name) == 0) {
            // Return the medicine if it is found
            return &store->medicines[i];
        }
    }

    // Return NULL if the medicine is not found
    return NULL;
}

// Sell a medicine from the medical store
void sell_medicine(medical_store_t* store, char* name, int quantity) {
    // Search for the medicine in the medical store
    medicine_t* medicine = search_medicine(store, name);

    // Check if the medicine is found
    if (medicine == NULL) {
        printf("Error: The medicine is not found in the medical store.\n");
        return;
    }

    // Check if the medicine has enough quantity
    if (medicine->quantity < quantity) {
        printf("Error: The medicine does not have enough quantity.\n");
        return;
    }

    // Sell the medicine by reducing its quantity
    medicine->quantity -= quantity;
}

// Print the inventory of the medical store
void print_inventory(medical_store_t* store) {
    // Iterate over the medicines in the medical store
    for (int i = 0; i < store->num_medicines; i++) {
        // Print the medicine's details
        printf("Name: %s\n", store->medicines[i].name);
        printf("Price: %.2f\n", store->medicines[i].price);
        printf("Quantity: %d\n\n", store->medicines[i].quantity);
    }
}

// Main function
int main() {
    // Create a new medical store
    medical_store_t* store = create_medical_store();

    // Add some medicines to the medical store
    add_medicine(store, "Paracetamol", 10.0, 100);
    add_medicine(store, "Ibuprofen", 15.0, 50);
    add_medicine(store, "Aspirin", 5.0, 200);

    // Print the inventory of the medical store
    print_inventory(store);

    // Search for a medicine in the medical store
    medicine_t* medicine = search_medicine(store, "Paracetamol");

    // Check if the medicine is found
    if (medicine != NULL) {
        printf("The medicine is found.\n");
    } else {
        printf("The medicine is not found.\n");
    }

    // Sell some of the medicine from the medical store
    sell_medicine(store, "Paracetamol", 50);

    // Print the inventory of the medical store
    print_inventory(store);

    return 0;
}