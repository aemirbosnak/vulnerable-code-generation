//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of a medicine
typedef struct Medicine {
    int id;
    char name[50];
    int quantity;
    float price;
} Medicine;

// Structure to store the list of medicines
typedef struct MedicineList {
    Medicine *medicines;
    int size;
} MedicineList;

// Function to create a new medicine
Medicine *createMedicine(int id, char *name, int quantity, float price) {
    Medicine *medicine = (Medicine *)malloc(sizeof(Medicine));
    medicine->id = id;
    strcpy(medicine->name, name);
    medicine->quantity = quantity;
    medicine->price = price;
    return medicine;
}

// Function to add a medicine to the list of medicines
void addMedicine(MedicineList *medicineList, Medicine *medicine) {
    medicineList->medicines = (Medicine *)realloc(medicineList->medicines, (medicineList->size + 1) * sizeof(Medicine));
    medicineList->medicines[medicineList->size] = *medicine;
    medicineList->size++;
}

// Function to search for a medicine by its ID
Medicine *searchMedicineById(MedicineList *medicineList, int id) {
    for (int i = 0; i < medicineList->size; i++) {
        if (medicineList->medicines[i].id == id) {
            return &medicineList->medicines[i];
        }
    }
    return NULL;
}

// Function to display the details of a medicine
void displayMedicine(Medicine *medicine) {
    printf("ID: %d\n", medicine->id);
    printf("Name: %s\n", medicine->name);
    printf("Quantity: %d\n", medicine->quantity);
    printf("Price: %.2f\n", medicine->price);
}

// Function to display the list of medicines
void displayMedicineList(MedicineList *medicineList) {
    for (int i = 0; i < medicineList->size; i++) {
        displayMedicine(&medicineList->medicines[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new medicine list
    MedicineList medicineList;
    medicineList.medicines = NULL;
    medicineList.size = 0;

    // Add some medicines to the list
    addMedicine(&medicineList, createMedicine(1, "Paracetamol", 100, 10.0));
    addMedicine(&medicineList, createMedicine(2, "Ibuprofen", 50, 15.0));
    addMedicine(&medicineList, createMedicine(3, "Aspirin", 25, 5.0));

    // Display the list of medicines
    displayMedicineList(&medicineList);

    // Search for a medicine by its ID
    Medicine *medicine = searchMedicineById(&medicineList, 2);

    // Display the details of the medicine
    displayMedicine(medicine);

    return 0;
}