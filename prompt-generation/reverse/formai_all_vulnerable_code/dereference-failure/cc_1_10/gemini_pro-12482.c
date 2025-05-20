//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines
#define MAX_MEDICINES 100

// Define the structure of a medicine
typedef struct medicine {
    int id;
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
medical_store* create_medical_store() {
    medical_store* store = (medical_store*)malloc(sizeof(medical_store));
    store->num_medicines = 0;
    return store;
}

// Add a new medicine to the medical store
void add_medicine(medical_store* store, medicine* new_medicine) {
    if (store->num_medicines >= MAX_MEDICINES) {
        printf("Error: The medical store is full.\n");
        return;
    }

    store->medicines[store->num_medicines] = *new_medicine;
    store->num_medicines++;
}

// Find a medicine in the medical store by its ID
medicine* find_medicine_by_id(medical_store* store, int id) {
    for (int i = 0; i < store->num_medicines; i++) {
        if (store->medicines[i].id == id) {
            return &store->medicines[i];
        }
    }

    return NULL;
}

// Find a medicine in the medical store by its name
medicine* find_medicine_by_name(medical_store* store, char* name) {
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            return &store->medicines[i];
        }
    }

    return NULL;
}

// Sell a medicine from the medical store
void sell_medicine(medical_store* store, int id, int quantity) {
    medicine* medicine = find_medicine_by_id(store, id);
    if (medicine == NULL) {
        printf("Error: The medicine with the given ID does not exist.\n");
        return;
    }

    if (medicine->quantity < quantity) {
        printf("Error: The requested quantity is not available.\n");
        return;
    }

    medicine->quantity -= quantity;
}

// Print the inventory of the medical store
void print_inventory(medical_store* store) {
    printf("Inventory of the medical store:\n");
    for (int i = 0; i < store->num_medicines; i++) {
        medicine* medicine = &store->medicines[i];
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", medicine->id, medicine->name, medicine->price, medicine->quantity);
    }
}

// Main function
int main() {
    // Create a new medical store
    medical_store* store = create_medical_store();

    // Add some medicines to the medical store
    medicine medicine1 = {1, "Paracetamol", 10.0, 100};
    add_medicine(store, &medicine1);

    medicine medicine2 = {2, "Ibuprofen", 15.0, 50};
    add_medicine(store, &medicine2);

    medicine medicine3 = {3, "Aspirin", 5.0, 200};
    add_medicine(store, &medicine3);

    // Find a medicine by its ID
    medicine* medicine = find_medicine_by_id(store, 2);
    if (medicine != NULL) {
        printf("Medicine found: %s\n", medicine->name);
    } else {
        printf("Medicine not found.\n");
    }

    // Sell a medicine
    sell_medicine(store, 1, 50);

    // Print the inventory of the medical store
    print_inventory(store);

    return 0;
}