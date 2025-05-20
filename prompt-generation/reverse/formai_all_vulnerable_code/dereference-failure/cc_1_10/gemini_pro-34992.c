//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines that can be stored
#define MAX_MEDICINES 100

// Define the structure of a medicine
typedef struct medicine {
    char name[50];
    char manufacturer[50];
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

// Add a new medicine to the medical store
void add_medicine(medical_store* store, medicine* new_medicine) {
    store->medicines[store->num_medicines] = *new_medicine;
    store->num_medicines++;
}

// Search for a medicine in the medical store by name
medicine* search_medicine_by_name(medical_store* store, char* name) {
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            return &store->medicines[i];
        }
    }
    return NULL;
}

// Search for a medicine in the medical store by manufacturer
medicine* search_medicine_by_manufacturer(medical_store* store, char* manufacturer) {
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].manufacturer, manufacturer) == 0) {
            return &store->medicines[i];
        }
    }
    return NULL;
}

// Print the details of all medicines in the medical store
void print_all_medicines(medical_store* store) {
    for (int i = 0; i < store->num_medicines; i++) {
        printf("Medicine %d:\n", i + 1);
        printf("Name: %s\n", store->medicines[i].name);
        printf("Manufacturer: %s\n", store->medicines[i].manufacturer);
        printf("Quantity: %d\n", store->medicines[i].quantity);
        printf("Price: %.2f\n\n", store->medicines[i].price);
    }
}

// Main function
int main() {
    // Create a new medical store
    medical_store* store = create_medical_store();

    // Add some medicines to the medical store
    medicine medicine1 = {"Paracetamol", "GlaxoSmithKline", 100, 10.00};
    add_medicine(store, &medicine1);
    medicine medicine2 = {"Ibuprofen", "Pfizer", 50, 15.00};
    add_medicine(store, &medicine2);
    medicine medicine3 = {"Aspirin", "Bayer", 25, 5.00};
    add_medicine(store, &medicine3);

    // Search for a medicine in the medical store by name
    medicine* medicine = search_medicine_by_name(store, "Paracetamol");
    if (medicine != NULL) {
        printf("Medicine found:\n");
        printf("Name: %s\n", medicine->name);
        printf("Manufacturer: %s\n", medicine->manufacturer);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n\n", medicine->price);
    } else {
        printf("Medicine not found.\n");
    }

    // Search for a medicine in the medical store by manufacturer
    medicine = search_medicine_by_manufacturer(store, "Pfizer");
    if (medicine != NULL) {
        printf("Medicine found:\n");
        printf("Name: %s\n", medicine->name);
        printf("Manufacturer: %s\n", medicine->manufacturer);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n\n", medicine->price);
    } else {
        printf("Medicine not found.\n");
    }

    // Print the details of all medicines in the medical store
    print_all_medicines(store);

    return 0;
}