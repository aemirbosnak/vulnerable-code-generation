//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store product information
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Function to add a product to the inventory
void add_product(product *inventory, int *size, char *name, int quantity, float price) {
    // Reallocate memory if necessary
    if (*size == 0) {
        inventory = realloc(inventory, sizeof(product));
    } else {
        inventory = realloc(inventory, (*size + 1) * sizeof(product));
    }

    // Add the product to the inventory
    strcpy(inventory[*size].name, name);
    inventory[*size].quantity = quantity;
    inventory[*size].price = price;

    // Increment the size of the inventory
    (*size)++;
}

// Function to remove a product from the inventory
void remove_product(product *inventory, int *size, char *name) {
    // Find the product to be removed
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the product was not found, return
    if (index == -1) {
        return;
    }

    // Remove the product from the inventory
    for (int i = index; i < *size - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    // Decrement the size of the inventory
    (*size)--;
}

// Function to update the quantity of a product in the inventory
void update_quantity(product *inventory, int *size, char *name, int quantity) {
    // Find the product to be updated
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the product was not found, return
    if (index == -1) {
        return;
    }

    // Update the quantity of the product
    inventory[index].quantity = quantity;
}

// Function to print the inventory
void print_inventory(product *inventory, int size) {
    printf("Product Inventory:\n\n");
    for (int i = 0; i < size; i++) {
        printf("%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Main function
int main() {
    // Create an inventory of products
    product *inventory = NULL;
    int size = 0;

    // Add some products to the inventory
    add_product(inventory, &size, "Apple", 10, 1.00);
    add_product(inventory, &size, "Orange", 5, 1.50);
    add_product(inventory, &size, "Banana", 15, 0.50);

    // Print the inventory
    print_inventory(inventory, size);

    // Remove a product from the inventory
    remove_product(inventory, &size, "Orange");

    // Update the quantity of a product in the inventory
    update_quantity(inventory, &size, "Apple", 20);

    // Print the updated inventory
    print_inventory(inventory, size);

    // Free the memory allocated for the inventory
    free(inventory);

    return 0;
}