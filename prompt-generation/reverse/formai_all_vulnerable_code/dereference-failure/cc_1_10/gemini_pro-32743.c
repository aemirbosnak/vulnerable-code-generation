//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines that can be stored in the system
#define MAX_MEDICINES 100

// Define the structure of a medicine
typedef struct medicine {
    char name[50];
    int quantity;
    float price;
} medicine;

// Define the structure of the medical store
typedef struct medical_store {
    medicine medicines[MAX_MEDICINES];
    int num_medicines;
} medical_store;

// Function to create a new medical store
medical_store* create_medical_store() {
    medical_store* store = (medical_store*)malloc(sizeof(medical_store));
    store->num_medicines = 0;
    return store;
}

// Function to add a new medicine to the medical store
void add_medicine(medical_store* store, char* name, int quantity, float price) {
    // Check if the medical store is full
    if (store->num_medicines >= MAX_MEDICINES) {
        printf("Error: The medical store is full.\n");
        return;
    }

    // Add the new medicine to the store
    strcpy(store->medicines[store->num_medicines].name, name);
    store->medicines[store->num_medicines].quantity = quantity;
    store->medicines[store->num_medicines].price = price;

    // Increment the number of medicines in the store
    store->num_medicines++;
}

// Function to remove a medicine from the medical store
void remove_medicine(medical_store* store, char* name) {
    // Find the index of the medicine in the store
    int index = -1;
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the medicine was found
    if (index == -1) {
        printf("Error: The medicine was not found.\n");
        return;
    }

    // Remove the medicine from the store
    for (int i = index; i < store->num_medicines - 1; i++) {
        store->medicines[i] = store->medicines[i + 1];
    }

    // Decrement the number of medicines in the store
    store->num_medicines--;
}

// Function to search for a medicine in the medical store
medicine* search_medicine(medical_store* store, char* name) {
    // Find the index of the medicine in the store
    int index = -1;
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the medicine was found
    if (index == -1) {
        return NULL;
    }

    // Return the medicine
    return &store->medicines[index];
}

// Function to print the medical store
void print_medical_store(medical_store* store) {
    printf("Medical Store:\n");
    printf("----------------\n");
    for (int i = 0; i < store->num_medicines; i++) {
        printf("%s: %d, %.2f\n", store->medicines[i].name, store->medicines[i].quantity, store->medicines[i].price);
    }
}

// Main function
int main() {
    // Create a new medical store
    medical_store* store = create_medical_store();

    // Add some medicines to the store
    add_medicine(store, "Paracetamol", 100, 10.0);
    add_medicine(store, "Ibuprofen", 50, 15.0);
    add_medicine(store, "Aspirin", 25, 5.0);

    // Print the medical store
    print_medical_store(store);

    // Search for a medicine in the store
    medicine* medicine = search_medicine(store, "Ibuprofen");

    // Check if the medicine was found
    if (medicine != NULL) {
        printf("Medicine found: %s, %d, %.2f\n", medicine->name, medicine->quantity, medicine->price);
    } else {
        printf("Medicine not found.\n");
    }

    // Remove a medicine from the store
    remove_medicine(store, "Aspirin");

    // Print the medical store
    print_medical_store(store);

    // Free the memory allocated for the medical store
    free(store);

    return 0;
}