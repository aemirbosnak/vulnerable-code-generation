//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    char brand[50];
    int quantity;
    float price;
    char expiry_date[20];
};

struct medicine_store {
    struct medicine medicines[100];
    int num_medicines;
};

struct medicine_store *create_medicine_store() {
    struct medicine_store *store = malloc(sizeof(struct medicine_store));
    store->num_medicines = 0;
    return store;
}

void add_medicine(struct medicine_store *store, struct medicine medicine) {
    store->medicines[store->num_medicines++] = medicine;
}

void print_medicine(struct medicine medicine) {
    printf("Name: %s\n", medicine.name);
    printf("Brand: %s\n", medicine.brand);
    printf("Quantity: %d\n", medicine.quantity);
    printf("Price: %f\n", medicine.price);
    printf("Expiry Date: %s\n", medicine.expiry_date);
    printf("\n");
}

void print_medicine_store(struct medicine_store *store) {
    for (int i = 0; i < store->num_medicines; i++) {
        print_medicine(store->medicines[i]);
    }
}

int main() {
    struct medicine_store *store = create_medicine_store();
    
    // Add some medicines to the store
    struct medicine medicine1 = {"Paracetamol", "Cipla", 10, 10.0, "2023-12-31"};
    add_medicine(store, medicine1);
    struct medicine medicine2 = {"Ibuprofen", "Advil", 20, 15.0, "2024-06-30"};
    add_medicine(store, medicine2);
    struct medicine medicine3 = {"Amoxicillin", "Augmentin", 30, 20.0, "2025-03-31"};
    add_medicine(store, medicine3);
    
    // Print the medicines in the store
    print_medicine_store(store);
    
    return 0;
}