//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char brand[50];
    int quantity;
    float price;
} Medicine;

typedef struct {
    Medicine *medicines;
    int count;
    int capacity;
} MedicalStore;

MedicalStore *createMedicalStore() {
    MedicalStore *store = (MedicalStore *)malloc(sizeof(MedicalStore));
    store->medicines = (Medicine *)malloc(sizeof(Medicine) * 10);
    store->count = 0;
    store->capacity = 10;
    return store;
}

void addMedicine(MedicalStore *store, Medicine medicine) {
    if (store->count == store->capacity) {
        store->capacity *= 2;
        store->medicines = (Medicine *)realloc(store->medicines, sizeof(Medicine) * store->capacity);
    }
    store->medicines[store->count++] = medicine;
}

Medicine *findMedicineByName(MedicalStore *store, char *name) {
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            return &store->medicines[i];
        }
    }
    return NULL;
}

void printMedicalStore(MedicalStore *store) {
    printf("Medical Store:\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Name | Brand | Quantity | Price | Total Value |\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");
    float totalValue = 0;
    for (int i = 0; i < store->count; i++) {
        Medicine medicine = store->medicines[i];
        printf("| %-20s | %-20s | %7d | %7.2f | %10.2f |\n", medicine.name, medicine.brand, medicine.quantity, medicine.price, medicine.quantity * medicine.price);
        totalValue += medicine.quantity * medicine.price;
    }
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Total Value: %10.2f\n", totalValue);
}

int main() {
    MedicalStore *store = createMedicalStore();
    Medicine medicine1 = {"Paracetamol", "Cipla", 100, 10.00};
    Medicine medicine2 = {"Ibuprofen", "Advil", 50, 15.00};
    Medicine medicine3 = {"Amoxicillin", "Pfizer", 20, 20.00};
    addMedicine(store, medicine1);
    addMedicine(store, medicine2);
    addMedicine(store, medicine3);
    printMedicalStore(store);
    return 0;
}