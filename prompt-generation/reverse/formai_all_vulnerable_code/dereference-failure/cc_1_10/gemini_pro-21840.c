//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the inventory system.
#define MAX_PRODUCTS 100

// Define the structure of a product.
typedef struct {
    char name[50];
    int quantity;
    float price;
} product;

// Define the structure of the inventory system.
typedef struct {
    product products[MAX_PRODUCTS];
    int num_products;
} inventory_system;

// Create a new inventory system.
inventory_system* create_inventory_system() {
    inventory_system* inventory = malloc(sizeof(inventory_system));
    inventory->num_products = 0;
    return inventory;
}

// Add a product to the inventory system.
void add_product(inventory_system* inventory, product* product) {
    inventory->products[inventory->num_products++] = *product;
}

// Remove a product from the inventory system.
void remove_product(inventory_system* inventory, char* name) {
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            inventory->products[i] = inventory->products[inventory->num_products - 1];
            inventory->num_products--;
            break;
        }
    }
}

// Get the quantity of a product in the inventory system.
int get_quantity(inventory_system* inventory, char* name) {
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            return inventory->products[i].quantity;
        }
    }
    return 0;
}

// Get the total value of the inventory system.
float get_total_value(inventory_system* inventory) {
    float total_value = 0;
    for (int i = 0; i < inventory->num_products; i++) {
        total_value += inventory->products[i].quantity * inventory->products[i].price;
    }
    return total_value;
}

// Print the inventory system.
void print_inventory_system(inventory_system* inventory) {
    for (int i = 0; i < inventory->num_products; i++) {
        printf("%s: %d, %.2f\n", inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
}

// Main function.
int main() {

    // Create a new inventory system.
    inventory_system* inventory = create_inventory_system();

    // Add some products to the inventory system.
    add_product(inventory, &(product) {"Apple", 10, 1.0});
    add_product(inventory, &(product) {"Banana", 20, 1.5});
    add_product(inventory, &(product) {"Orange", 30, 2.0});

    // Print the inventory system.
    print_inventory_system(inventory);

    // Get the quantity of a product in the inventory system.
    int quantity = get_quantity(inventory, "Apple");
    printf("The quantity of Apple in the inventory is: %d\n", quantity);

    // Get the total value of the inventory system.
    float total_value = get_total_value(inventory);
    printf("The total value of the inventory is: %.2f\n", total_value);

    // Remove a product from the inventory system.
    remove_product(inventory, "Banana");

    // Print the inventory system.
    print_inventory_system(inventory);

    return 0;
}