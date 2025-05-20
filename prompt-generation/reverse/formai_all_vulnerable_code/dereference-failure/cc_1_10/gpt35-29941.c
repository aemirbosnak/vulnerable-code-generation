//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing medicine data
struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Function to add a new medicine to the inventory
void add_medicine(struct Medicine* inventory, int* num_medicines) {
    // Get user input for medicine details
    char name[50];
    float price;
    int quantity;
    printf("Enter medicine name: ");
    scanf("%s", name);
    printf("Enter medicine price: ");
    scanf("%f", &price);
    printf("Enter medicine quantity: ");
    scanf("%d", &quantity);

    // Increase the number of medicines in the inventory
    (*num_medicines)++;

    // Add new medicine to the end of the list
    inventory = (struct Medicine*) realloc(inventory, (*num_medicines) * sizeof(struct Medicine));
    inventory[*num_medicines - 1].id = (*num_medicines);
    strcpy(inventory[*num_medicines - 1].name, name);
    inventory[*num_medicines - 1].price = price;
    inventory[*num_medicines - 1].quantity = quantity;

    // Display success message
    printf("Medicine added to inventory successfully!\n\n");
}

// Function to display the current inventory
void display_inventory(struct Medicine* inventory, int num_medicines) {
    // Display column headings
    printf("%-5s %-30s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");

    // Display each medicine in the inventory
    for (int i = 0; i < num_medicines; i++) {
        printf("%-5d %-30s %-10.2f %-10d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }

    // Display empty line
    printf("\n");
}

int main() {
    // Initialize the inventory with some sample data
    struct Medicine* inventory = (struct Medicine*) malloc(sizeof(struct Medicine) * 3);
    inventory[0].id = 1;
    strcpy(inventory[0].name, "Paracetamol");
    inventory[0].price = 1.50;
    inventory[0].quantity = 100;
    inventory[1].id = 2;
    strcpy(inventory[1].name, "Ibuprofen");
    inventory[1].price = 2.50;
    inventory[1].quantity = 50;
    inventory[2].id = 3;
    strcpy(inventory[2].name, "Aspirin");
    inventory[2].price = 1.00;
    inventory[2].quantity = 200;
    int num_medicines = 3;

    // Display welcome message and menu options
    printf("Welcome to the Medical Store Management System\n\n");
    int choice;
    do {
        printf("Please choose an option:\n");
        printf("1. Add new medicine\n");
        printf("2. Display inventory\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine(inventory, &num_medicines);
                break;
            case 2:
                display_inventory(inventory, num_medicines);
                break;
            case 3:
                printf("Exiting program...\n\n");
                break;
            default:
                printf("Invalid choice, please try again.\n\n");
                break;
        }
    } while (choice != 3);

    // Free memory used by inventory
    free(inventory);

    return 0;
}