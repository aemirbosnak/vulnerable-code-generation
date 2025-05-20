//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines in the store
#define MAX_MEDICINES 100

// Define the structure of a medicine
typedef struct {
    char name[50];
    float price;
    int quantity;
} Medicine;

// Define the structure of the medical store
typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int num_medicines;
} MedicalStore;

// Create a new medical store
MedicalStore* create_medical_store() {
    MedicalStore* store = (MedicalStore*)malloc(sizeof(MedicalStore));
    store->num_medicines = 0;
    return store;
}

// Add a new medicine to the store
void add_medicine(MedicalStore* store, Medicine medicine) {
    if (store->num_medicines >= MAX_MEDICINES) {
        printf("Error: The medical store is full.\n");
        return;
    }
    store->medicines[store->num_medicines] = medicine;
    store->num_medicines++;
}

// Search for a medicine in the store by name
Medicine* search_medicine(MedicalStore* store, char* name) {
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            return &store->medicines[i];
        }
    }
    return NULL;
}

// Sell a medicine from the store
void sell_medicine(MedicalStore* store, char* name, int quantity) {
    Medicine* medicine = search_medicine(store, name);
    if (medicine == NULL) {
        printf("Error: The medicine is not found.\n");
        return;
    }
    if (medicine->quantity < quantity) {
        printf("Error: The quantity of the medicine is not sufficient.\n");
        return;
    }
    medicine->quantity -= quantity;
}

// Print the details of all the medicines in the store
void print_medicines(MedicalStore* store) {
    printf("The following medicines are available in the store:\n");
    for (int i = 0; i < store->num_medicines; i++) {
        printf("%s\t%.2f\t%d\n", store->medicines[i].name, store->medicines[i].price, store->medicines[i].quantity);
    }
}

// Free the memory allocated to the medical store
void free_medical_store(MedicalStore* store) {
    free(store);
}

// Main function
int main() {
    // Create a new medical store
    MedicalStore* store = create_medical_store();

    // Add some medicines to the store
    Medicine medicine1 = {"Paracetamol", 10.0, 50};
    add_medicine(store, medicine1);
    Medicine medicine2 = {"Ibuprofen", 15.0, 25};
    add_medicine(store, medicine2);
    Medicine medicine3 = {"Aspirin", 5.0, 100};
    add_medicine(store, medicine3);

    // Print the details of all the medicines in the store
    print_medicines(store);

    // Search for a medicine in the store
    Medicine* medicine = search_medicine(store, "Ibuprofen");
    if (medicine != NULL) {
        printf("The medicine %s is found.\n", medicine->name);
    } else {
        printf("The medicine is not found.\n");
    }

    // Sell a medicine from the store
    sell_medicine(store, "Paracetamol", 20);

    // Print the details of all the medicines in the store
    print_medicines(store);

    // Free the memory allocated to the medical store
    free_medical_store(store);

    return 0;
}