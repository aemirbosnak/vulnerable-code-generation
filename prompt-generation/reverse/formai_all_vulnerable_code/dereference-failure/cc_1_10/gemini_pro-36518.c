//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

typedef struct {
    Medicine *medicines;
    int num_medicines;
} MedicalStore;

MedicalStore *create_medical_store() {
    MedicalStore *store = malloc(sizeof(MedicalStore));
    store->medicines = NULL;
    store->num_medicines = 0;
    return store;
}

void add_medicine(MedicalStore *store, Medicine medicine) {
    store->medicines = realloc(store->medicines, (store->num_medicines + 1) * sizeof(Medicine));
    store->medicines[store->num_medicines++] = medicine;
}

Medicine *find_medicine(MedicalStore *store, char *name) {
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            return &store->medicines[i];
        }
    }
    return NULL;
}

void print_medical_store(MedicalStore *store) {
    for (int i = 0; i < store->num_medicines; i++) {
        printf("%s %d %.2f\n", store->medicines[i].name, store->medicines[i].quantity, store->medicines[i].price);
    }
}

int main() {
    MedicalStore *store = create_medical_store();
    Medicine medicine;
    strcpy(medicine.name, "Paracetamol");
    medicine.quantity = 100;
    medicine.price = 10.0;
    add_medicine(store, medicine);
    strcpy(medicine.name, "Ibuprofen");
    medicine.quantity = 50;
    medicine.price = 15.0;
    add_medicine(store, medicine);
    Medicine *found_medicine = find_medicine(store, "Paracetamol");
    if (found_medicine != NULL) {
        printf("Found %s with quantity %d and price %.2f\n", found_medicine->name, found_medicine->quantity, found_medicine->price);
    } else {
        printf("Medicine not found\n");
    }
    print_medical_store(store);
    return 0;
}