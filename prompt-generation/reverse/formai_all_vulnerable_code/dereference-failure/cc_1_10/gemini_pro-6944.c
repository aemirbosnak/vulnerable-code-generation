//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines in the store
#define MAX_MEDICINES 100

// Define the structure of a medicine
typedef struct Medicine {
    int id;
    char name[50];
    int quantity;
    float price;
} Medicine;

// Define the structure of the medical store
typedef struct MedicalStore {
    Medicine medicines[MAX_MEDICINES];
    int num_medicines;
} MedicalStore;

// Create a new medical store
MedicalStore* create_medical_store() {
    MedicalStore* store = (MedicalStore*) malloc(sizeof(MedicalStore));
    store->num_medicines = 0;
    return store;
}

// Add a new medicine to the store
void add_medicine(MedicalStore* store, Medicine medicine) {
    if (store->num_medicines < MAX_MEDICINES) {
        store->medicines[store->num_medicines] = medicine;
        store->num_medicines++;
    } else {
        printf("Error: The medical store is full.\n");
    }
}

// Remove a medicine from the store
void remove_medicine(MedicalStore* store, int id) {
    int i;
    for (i = 0; i < store->num_medicines; i++) {
        if (store->medicines[i].id == id) {
            store->medicines[i] = store->medicines[store->num_medicines - 1];
            store->num_medicines--;
            break;
        }
    }
    if (i == store->num_medicines) {
        printf("Error: The medicine with id %d was not found.\n", id);
    }
}

// Update the quantity of a medicine in the store
void update_medicine(MedicalStore* store, int id, int quantity) {
    int i;
    for (i = 0; i < store->num_medicines; i++) {
        if (store->medicines[i].id == id) {
            store->medicines[i].quantity = quantity;
            break;
        }
    }
    if (i == store->num_medicines) {
        printf("Error: The medicine with id %d was not found.\n", id);
    }
}

// Print the details of all medicines in the store
void print_medicines(MedicalStore* store) {
    int i;
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (i = 0; i < store->num_medicines; i++) {
        printf("%d\t%s\t\t%d\t%.2f\n", store->medicines[i].id, store->medicines[i].name, store->medicines[i].quantity, store->medicines[i].price);
    }
}

// Main function
int main() {
    // Create a new medical store
    MedicalStore* store = create_medical_store();

    // Add some medicines to the store
    Medicine medicine1 = {1, "Paracetamol", 100, 10.0};
    add_medicine(store, medicine1);
    Medicine medicine2 = {2, "Ibuprofen", 50, 15.0};
    add_medicine(store, medicine2);
    Medicine medicine3 = {3, "Aspirin", 25, 5.0};
    add_medicine(store, medicine3);

    // Print the details of all medicines in the store
    print_medicines(store);

    // Remove a medicine from the store
    remove_medicine(store, 2);

    // Update the quantity of a medicine in the store
    update_medicine(store, 1, 50);

    // Print the details of all medicines in the store
    print_medicines(store);

    // Free the memory allocated for the medical store
    free(store);

    return 0;
}