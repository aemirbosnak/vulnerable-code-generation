//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a medicine
typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} medicine;

// Define the structure of a medical store
typedef struct medical_store {
    medicine *medicines;
    int num_medicines;
} medical_store;

// Create a new medical store
medical_store *create_medical_store() {
    medical_store *store = malloc(sizeof(medical_store));
    store->medicines = NULL;
    store->num_medicines = 0;
    return store;
}

// Add a new medicine to the medical store
void add_medicine(medical_store *store, medicine *new_medicine) {
    store->medicines = realloc(store->medicines, (store->num_medicines + 1) * sizeof(medicine));
    store->medicines[store->num_medicines] = *new_medicine;
    store->num_medicines++;
}

// Search for a medicine in the medical store
medicine *search_medicine(medical_store *store, char *name) {
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            return &store->medicines[i];
        }
    }
    return NULL;
}

// Sell a medicine from the medical store
void sell_medicine(medical_store *store, char *name, int quantity) {
    medicine *med = search_medicine(store, name);
    if (med != NULL) {
        if (med->quantity >= quantity) {
            med->quantity -= quantity;
            printf("Medicine sold successfully!\n");
        } else {
            printf("Sorry, we don't have enough stock of this medicine.\n");
        }
    } else {
        printf("Sorry, we don't have this medicine in stock.\n");
    }
}

// Print the details of all medicines in the medical store
void print_medicines(medical_store *store) {
    printf("Here are the details of all medicines in the medical store:\n");
    for (int i = 0; i < store->num_medicines; i++) {
        printf("Name: %s\n", store->medicines[i].name);
        printf("Price: %.2f\n", store->medicines[i].price);
        printf("Quantity: %d\n\n", store->medicines[i].quantity);
    }
}

// Main function
int main() {
    // Create a new medical store
    medical_store *store = create_medical_store();

    // Add some medicines to the medical store
    medicine m1 = {"Paracetamol", 10.0, 100};
    add_medicine(store, &m1);
    medicine m2 = {"Ibuprofen", 15.0, 50};
    add_medicine(store, &m2);
    medicine m3 = {"Amoxicillin", 20.0, 25};
    add_medicine(store, &m3);

    // Search for a medicine in the medical store
    medicine *med = search_medicine(store, "Paracetamol");
    if (med != NULL) {
        printf("Medicine found!\n");
    } else {
        printf("Medicine not found.\n");
    }

    // Sell a medicine from the medical store
    sell_medicine(store, "Paracetamol", 20);

    // Print the details of all medicines in the medical store
    print_medicines(store);

    return 0;
}