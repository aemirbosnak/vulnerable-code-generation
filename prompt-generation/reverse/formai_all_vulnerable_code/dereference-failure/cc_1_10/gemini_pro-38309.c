//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char description[200];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the inventory
void addMedicine(medicine **inventory, int *numMedicines) {
    // Allocate memory for the new medicine
    medicine *newMedicine = malloc(sizeof(medicine));

    // Get the medicine details from the user
    printf("Enter the name of the medicine: ");
    scanf("%s", newMedicine->name);
    printf("Enter the description of the medicine: ");
    scanf(" %[^\n]s", newMedicine->description);
    printf("Enter the price of the medicine: ");
    scanf("%f", &newMedicine->price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &newMedicine->quantity);

    // Add the new medicine to the inventory
    *inventory = realloc(*inventory, (*numMedicines + 1) * sizeof(medicine));
    (*inventory)[*numMedicines] = *newMedicine;
    *numMedicines += 1;
}

// Function to search for a medicine in the inventory
medicine *searchMedicine(medicine *inventory, int numMedicines, char *name) {
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return &inventory[i];
        }
    }

    return NULL;
}

// Function to sell a medicine from the inventory
void sellMedicine(medicine *inventory, int *numMedicines, char *name, int quantity) {
    medicine *medicine = searchMedicine(inventory, *numMedicines, name);

    if (medicine == NULL) {
        printf("Medicine not found.\n");
        return;
    }

    if (medicine->quantity < quantity) {
        printf("Not enough quantity of the medicine available.\n");
        return;
    }

    medicine->quantity -= quantity;
}

// Function to print the inventory of medicines
void printInventory(medicine *inventory, int numMedicines) {
    printf("Inventory of Medicines:\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%s - %s - %f - %d\n", inventory[i].name, inventory[i].description, inventory[i].price, inventory[i].quantity);
    }
}

// Main function
int main() {
    // Initialize the inventory of medicines
    medicine *inventory = NULL;
    int numMedicines = 0;

    // Add some sample medicines to the inventory
    addMedicine(&inventory, &numMedicines);
    addMedicine(&inventory, &numMedicines);
    addMedicine(&inventory, &numMedicines);

    // Print the inventory of medicines
    printInventory(inventory, numMedicines);

    // Search for a medicine in the inventory
    medicine *medicine = searchMedicine(inventory, numMedicines, "Medicine 1");

    if (medicine == NULL) {
        printf("Medicine not found.\n");
    } else {
        printf("Medicine found: %s\n", medicine->name);
    }

    // Sell a medicine from the inventory
    sellMedicine(inventory, &numMedicines, "Medicine 1", 1);

    // Print the inventory of medicines after selling a medicine
    printInventory(inventory, numMedicines);

    return 0;
}