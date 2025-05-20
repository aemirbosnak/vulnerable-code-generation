//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

// Define the structure of the inventory
typedef struct Inventory {
    Product products[MAX_PRODUCTS];
    int num_products;
} Inventory;

// Create a new inventory
Inventory* create_inventory() {
    Inventory* inventory = (Inventory*)malloc(sizeof(Inventory));
    inventory->num_products = 0;
    return inventory;
}

// Add a product to the inventory
void add_product(Inventory* inventory, Product product) {
    if (inventory->num_products < MAX_PRODUCTS) {
        inventory->products[inventory->num_products] = product;
        inventory->num_products++;
    } else {
        printf("Error: Inventory is full.\n");
    }
}

// Remove a product from the inventory
void remove_product(Inventory* inventory, char* name) {
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            inventory->products[i] = inventory->products[inventory->num_products - 1];
            inventory->num_products--;
            break;
        }
    }
}

// Update the quantity of a product in the inventory
void update_quantity(Inventory* inventory, char* name, int quantity) {
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            inventory->products[i].quantity = quantity;
            break;
        }
    }
}

// Print the inventory
void print_inventory(Inventory* inventory) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < inventory->num_products; i++) {
        printf("%s %d %f\n", inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
}

// Get the total value of the inventory
float get_total_value(Inventory* inventory) {
    float total_value = 0;
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        total_value += inventory->products[i].quantity * inventory->products[i].price;
    }
    return total_value;
}

// Main function
int main() {
    // Create a new inventory
    Inventory* inventory = create_inventory();

    // Add some products to the inventory
    Product product1 = {"Aspirin", 100, 0.50};
    Product product2 = {"Ibuprofen", 50, 1.00};
    Product product3 = {"Acetaminophen", 200, 0.75};
    add_product(inventory, product1);
    add_product(inventory, product2);
    add_product(inventory, product3);

    // Print the inventory
    print_inventory(inventory);

    // Get the total value of the inventory
    float total_value = get_total_value(inventory);
    printf("Total value of the inventory: %f\n", total_value);

    // Remove a product from the inventory
    remove_product(inventory, "Ibuprofen");

    // Update the quantity of a product in the inventory
    update_quantity(inventory, "Aspirin", 200);

    // Print the inventory
    print_inventory(inventory);

    // Free the memory allocated for the inventory
    free(inventory);

    return 0;
}