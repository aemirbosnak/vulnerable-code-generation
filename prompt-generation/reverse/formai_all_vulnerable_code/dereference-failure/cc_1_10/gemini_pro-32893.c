//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of drugs in the inventory
#define MAX_DRUGS 100

// Define the structure of a drug
typedef struct drug {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
    
} drug;

// Define the structure of the inventory
typedef struct inventory {
    drug drugs[MAX_DRUGS];
    int num_drugs;
  
} inventory;

// Function to create a new inventory
inventory* create_inventory() {
    inventory* inv = malloc(sizeof(inventory));
    inv->num_drugs = 0;
    
    return inv;
}

// Function to add a drug to the inventory
void add_drug(inventory* inv, drug* d) {
    if (inv->num_drugs >= MAX_DRUGS) {
        printf("Error: Inventory is full.\n");
        return;
    }

    inv->drugs[inv->num_drugs] = *d;
    inv->num_drugs++;
}


// Function to search for a drug in the inventory
drug* search_drug(inventory* inv, char* name) {
    for (int i = 0; i < inv->num_drugs; i++) {
        if (strcmp(inv->drugs[i].name, name) == 0) {
            return &inv->drugs[i];
        }
    }

    return NULL;
}

// Function to update the quantity of a drug in the inventory
void update_quantity(inventory* inv, char* name, int quantity) {
    drug* d = search_drug(inv, name);
    if (d == NULL) {
        printf("Error: Drug not found.\n");
        return;
    }

    d->quantity = quantity;
   
}

// Function to print the inventory
void print_inventory(inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_drugs; i++) {
        printf("%s %s %d %.2f\n", inv->drugs[i].name, inv->drugs[i].manufacturer, inv->drugs[i].quantity, inv->drugs[i].price);
    }
}
int main() {
    // Create a new inventory
    inventory* inv = create_inventory();

    // Add some drugs to the inventory
    drug d1 = {"Panadol", "GlaxoSmithKline", 100, 10.0};
    add_drug(inv, &d1);

    drug d2 = {"Ibuprofen", "Pfizer", 50, 5.0};
    add_drug(inv, &d2);

    drug d3 = {"Aspirin", "Bayer", 25, 2.0};
    add_drug(inv, &d3);

    // Print the inventory
    print_inventory(inv);

    // Search for a drug in the inventory
    drug* d = search_drug(inv, "Ibuprofen");
    if (d != NULL) {
        printf("Found drug: %s %s %d %.2f\n", d->name, d->manufacturer, d->quantity, d->price);
    } else {
        printf("Drug not found.\n");
    }

    // Update the quantity of a drug in the inventory
    update_quantity(inv, "Panadol", 75);

    // Print the inventory again
    print_inventory(inv);

    return 0;
}