//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medicine information
typedef struct Medicine {
    char name[50];
    char dosage[50];
    int quantity;
    float price;
} Medicine;

// Define a function to search for a medicine
void searchMedicine(Medicine *medicines, int numMedics, char *name) {
    for (int i = 0; i < numMedics; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Name: %s\n", medicines[i].name);
            printf("Dosage: %s\n", medicines[i].dosage);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %.2f\n", medicines[i].price);
            return;
        }
    }

    printf("Medicine not found.\n");
}

// Define a function to add a medicine
void addMedicine(Medicine *medicines, int *numMedics, char *name, char *dosage, int quantity, float price) {
    *numMedics++;

    medicines = (Medicine *)realloc(medicines, *numMedics * sizeof(Medicine));

    strcpy(medicines[*numMedics - 1].name, name);
    strcpy(medicines[*numMedics - 1].dosage, dosage);
    medicines[*numMedics - 1].quantity = quantity;
    medicines[*numMedics - 1].price = price;
}

// Main function
int main() {
    // Create an array of medicines
    Medicine *medicines = NULL;
    int numMedics = 0;

    // Add some medicines
    addMedicine(medicines, &numMedics, "Acetaminophen", "500mg", 10, 2.50);
    addMedicine(medicines, &numMedics, "Ibuprofen", "200mg", 5, 3.25);
    addMedicine(medicines, &numMedics, "Tylenol", "250mg", 7, 2.75);

    // Search for a medicine
    searchMedicine(medicines, numMedics, "Tylenol");

    return 0;
}