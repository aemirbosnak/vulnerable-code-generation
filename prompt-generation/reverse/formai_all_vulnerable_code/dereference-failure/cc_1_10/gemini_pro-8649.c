//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    int id;
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
} medicine;

// Function to add a new medicine to the inventory
void addMedicine(medicine **inventory, int *size) {
    // Allocate memory for the new medicine
    *inventory = realloc(*inventory, (*size + 1) * sizeof(medicine));

    // Get the details of the new medicine
    printf("Enter medicine ID: ");
    scanf("%d", &(*inventory)[*size].id);
    printf("Enter medicine name: ");
    scanf("%s", (*inventory)[*size].name);
    printf("Enter medicine manufacturer: ");
    scanf("%s", (*inventory)[*size].manufacturer);
    printf("Enter medicine quantity: ");
    scanf("%d", &(*inventory)[*size].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &(*inventory)[*size].price);

    // Increment the size of the inventory
    (*size)++;
}

// Function to search for a medicine by its ID
medicine *searchMedicineById(medicine *inventory, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == id) {
            return &inventory[i];
        }
    }

    return NULL;
}

// Function to sell a medicine
void sellMedicine(medicine *inventory, int size, int id, int quantity) {
    // Search for the medicine by its ID
    medicine *med = searchMedicineById(inventory, size, id);

    if (med == NULL) {
        printf("Medicine not found.\n");
        return;
    }

    // Check if the requested quantity is available
    if (med->quantity < quantity) {
        printf("Insufficient quantity available.\n");
        return;
    }

    // Update the quantity of the medicine
    med->quantity -= quantity;

    // Calculate the total price of the sale
    float total_price = med->price * quantity;

    // Print the sales receipt
    printf("Sales Receipt\n");
    printf("Medicine Name: %s\n", med->name);
    printf("Quantity: %d\n", quantity);
    printf("Total Price: %.2f\n", total_price);
}

// Function to print the inventory
void printInventory(medicine *inventory, int size) {
    printf("Inventory\n");
    printf("-----------------------------------------\n");
    printf("| ID | Name | Manufacturer | Quantity | Price |\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("| %d | %s | %s | %d | %.2f |\n", inventory[i].id, inventory[i].name, inventory[i].manufacturer, inventory[i].quantity, inventory[i].price);
    }
    printf("-----------------------------------------\n");
}

// Main function
int main() {
    // Initialize the inventory
    medicine *inventory = NULL;
    int size = 0;

    // Add some sample medicines to the inventory
    addMedicine(&inventory, &size);
    addMedicine(&inventory, &size);
    addMedicine(&inventory, &size);

    // Print the inventory
    printInventory(inventory, size);

    // Search for a medicine by its ID
    int id;
    printf("Enter medicine ID to search: ");
    scanf("%d", &id);
    medicine *med = searchMedicineById(inventory, size, id);

    if (med != NULL) {
        printf("Medicine found:\n");
        printf("ID: %d\n", med->id);
        printf("Name: %s\n", med->name);
        printf("Manufacturer: %s\n", med->manufacturer);
        printf("Quantity: %d\n", med->quantity);
        printf("Price: %.2f\n", med->price);
    } else {
        printf("Medicine not found.\n");
    }

    // Sell a medicine
    int quantity;
    printf("Enter medicine ID to sell: ");
    scanf("%d", &id);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    sellMedicine(inventory, size, id, quantity);

    // Print the inventory after the sale
    printInventory(inventory, size);

    // Free the memory allocated to the inventory
    free(inventory);

    return 0;
}