//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    int quantity;
    float price;
} medicine;

// Function to add a new medicine to the inventory
void add_medicine(medicine *inventory, int *size) {
    char name[50];
    int quantity;
    float price;

    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &price);

    // Allocate memory for the new medicine
    inventory = realloc(inventory, (*size + 1) * sizeof(medicine));

    // Store the medicine details in the inventory
    strcpy(inventory[*size].name, name);
    inventory[*size].quantity = quantity;
    inventory[*size].price = price;

    // Increment the size of the inventory
    (*size)++;
}

// Function to search for a medicine in the inventory
void search_medicine(medicine *inventory, int size) {
    char name[50];

    printf("Enter the name of the medicine you want to search for: ");
    scanf("%s", name);

    // Search for the medicine in the inventory
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %f\n", inventory[i].price);
            return;
        }
    }

    // Medicine not found
    printf("Medicine not found!\n");
}

// Function to sell a medicine from the inventory
void sell_medicine(medicine *inventory, int *size) {
    char name[50];
    int quantity;

    printf("Enter the name of the medicine you want to sell: ");
    scanf("%s", name);
    printf("Enter the quantity of the medicine you want to sell: ");
    scanf("%d", &quantity);

    // Search for the medicine in the inventory
    for (int i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Check if the medicine has enough quantity
            if (inventory[i].quantity >= quantity) {
                // Sell the medicine and update the inventory
                inventory[i].quantity -= quantity;
                printf("Medicine sold successfully!\n");
                return;
            } else {
                printf("Not enough quantity of the medicine in stock!\n");
                return;
            }
        }
    }

    // Medicine not found
    printf("Medicine not found!\n");
}

// Function to display the inventory
void display_inventory(medicine *inventory, int size) {
    printf("Inventory:\n");
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Main function
int main() {
    // Initialize the inventory
    medicine *inventory = NULL;
    int size = 0;

    // Add some medicines to the inventory
    add_medicine(inventory, &size);
    add_medicine(inventory, &size);
    add_medicine(inventory, &size);

    // Display the inventory
    display_inventory(inventory, size);

    // Search for a medicine in the inventory
    search_medicine(inventory, size);

    // Sell a medicine from the inventory
    sell_medicine(inventory, &size);

    // Display the inventory again
    display_inventory(inventory, size);

    // Free the memory allocated for the inventory
    free(inventory);

    return 0;
}