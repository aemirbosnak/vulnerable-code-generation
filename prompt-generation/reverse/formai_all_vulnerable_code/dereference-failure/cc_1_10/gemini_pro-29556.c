//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a medicine
typedef struct Medicine {
    char name[50];
    float price;
    int quantity;
} Medicine;

// Structure to represent the medical store
typedef struct MedicalStore {
    Medicine *medicines;
    int num_medicines;
} MedicalStore;

// Function to create a new medicine
Medicine *create_medicine(char *name, float price, int quantity) {
    Medicine *medicine = (Medicine *)malloc(sizeof(Medicine));
    strcpy(medicine->name, name);
    medicine->price = price;
    medicine->quantity = quantity;
    return medicine;
}

// Function to add a medicine to the medical store
void add_medicine(MedicalStore *store, Medicine *medicine) {
    store->medicines = (Medicine *)realloc(store->medicines, (store->num_medicines + 1) * sizeof(Medicine));
    store->medicines[store->num_medicines] = *medicine;
    store->num_medicines++;
}

// Function to remove a medicine from the medical store
void remove_medicine(MedicalStore *store, char *name) {
    int i;
    for (i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            break;
        }
    }

    if (i < store->num_medicines) {
        for (int j = i; j < store->num_medicines - 1; j++) {
            store->medicines[j] = store->medicines[j + 1];
        }
        store->num_medicines--;
    }
}

// Function to search for a medicine in the medical store
Medicine *search_medicine(MedicalStore *store, char *name) {
    int i;
    for (i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            return &store->medicines[i];
        }
    }

    return NULL;
}

// Function to print the medical store
void print_medical_store(MedicalStore *store) {
    int i;
    printf("Medical Store:\n");
    for (i = 0; i < store->num_medicines; i++) {
        printf("%s\t%.2f\t%d\n", store->medicines[i].name, store->medicines[i].price, store->medicines[i].quantity);
    }
}

// Main function
int main() {
    // Create a new medical store
    MedicalStore store;
    store.medicines = NULL;
    store.num_medicines = 0;

    // Add some medicines to the medical store
    add_medicine(&store, create_medicine("Paracetamol", 10.0, 100));
    add_medicine(&store, create_medicine("Ibuprofen", 15.0, 50));
    add_medicine(&store, create_medicine("Aspirin", 5.0, 200));

    // Print the medical store
    print_medical_store(&store);

    // Search for a medicine in the medical store
    Medicine *medicine = search_medicine(&store, "Ibuprofen");
    if (medicine != NULL) {
        printf("Medicine found!\n");
    } else {
        printf("Medicine not found!\n");
    }

    // Remove a medicine from the medical store
    remove_medicine(&store, "Aspirin");

    // Print the medical store
    print_medical_store(&store);

    return 0;
}