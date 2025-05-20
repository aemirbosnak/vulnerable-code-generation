//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

struct medicalStore {
    struct medicine *medicines;
    int numMedicines;
};

struct medicalStore *createMedicalStore() {
    struct medicalStore *store = malloc(sizeof(struct medicalStore));
    store->medicines = malloc(sizeof(struct medicine) * 10);
    store->numMedicines = 0;
    return store;
}

void addMedicine(struct medicalStore *store, char *name, int quantity, float price) {
    if (store->numMedicines == 10) {
        printf("Medical store is full!\n");
        return;
    }

    strcpy(store->medicines[store->numMedicines].name, name);
    store->medicines[store->numMedicines].quantity = quantity;
    store->medicines[store->numMedicines].price = price;
    store->numMedicines++;
}

void removeMedicine(struct medicalStore *store, char *name) {
    int i;

    for (i = 0; i < store->numMedicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            break;
        }
    }

    if (i == store->numMedicines) {
        printf("Medicine not found!\n");
        return;
    }

    for (; i < store->numMedicines - 1; i++) {
        store->medicines[i] = store->medicines[i + 1];
    }

    store->numMedicines--;
}

void printMedicalStore(struct medicalStore *store) {
    int i;

    printf("Medical Store:\n");
    for (i = 0; i < store->numMedicines; i++) {
        printf("%s %d %.2f\n", store->medicines[i].name, store->medicines[i].quantity, store->medicines[i].price);
    }
}

int main() {
    struct medicalStore *store = createMedicalStore();

    addMedicine(store, "Paracetamol", 10, 10.0);
    addMedicine(store, "Ibuprofen", 5, 12.0);
    addMedicine(store, "Aspirin", 7, 8.0);

    printMedicalStore(store);

    removeMedicine(store, "Ibuprofen");

    printMedicalStore(store);

    return 0;
}