//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Define the structure of the inventory
typedef struct {
    Product products[MAX_PRODUCTS];
    int num_products;
} Inventory;

// Create a new inventory
Inventory* create_inventory() {
    Inventory* inventory = malloc(sizeof(Inventory));
    inventory->num_products = 0;
    return inventory;
}

// Add a product to the inventory
void add_product(Inventory* inventory, Product product) {
    if (inventory->num_products < MAX_PRODUCTS) {
        inventory->products[inventory->num_products] = product;
        inventory->num_products++;
    } else {
        printf("Inventory is full! Cannot add more products.\n");
    }
}

// Remove a product from the inventory
void remove_product(Inventory* inventory, char* name) {
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            // Found the product to remove
            for (; i < inventory->num_products - 1; i++) {
                inventory->products[i] = inventory->products[i + 1];
            }
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
            // Found the product to update
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
        printf("%s (%d units) - $%.2f\n", inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
}

// Get the total value of the inventory
float get_total_value(Inventory* inventory) {
    float total_value = 0.0;
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        total_value += inventory->products[i].quantity * inventory->products[i].price;
    }
    return total_value;
}

// Clear the inventory (delete all products)
void clear_inventory(Inventory* inventory) {
    inventory->num_products = 0;
}

// Free the memory allocated for the inventory
void free_inventory(Inventory* inventory) {
    free(inventory);
}

int main() {
    // Create a new inventory
    Inventory* inventory = create_inventory();

    // Add some products to the inventory
    Product product1 = {"Apple", 10, 0.50};
    add_product(inventory, product1);
    Product product2 = {"Orange", 15, 0.75};
    add_product(inventory, product2);
    Product product3 = {"Banana", 20, 1.00};
    add_product(inventory, product3);

    // Print the inventory
    print_inventory(inventory);

    // Get the total value of the inventory
    float total_value = get_total_value(inventory);
    printf("Total value of the inventory: $%.2f\n", total_value);

    // Update the quantity of a product in the inventory
    update_quantity(inventory, "Apple", 15);

    // Remove a product from the inventory
    remove_product(inventory, "Orange");

    // Print the inventory again
    print_inventory(inventory);

    // Clear the inventory (delete all products)
    clear_inventory(inventory);

    // Free the memory allocated for the inventory
    free_inventory(inventory);

    return 0;
}