//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
    char name[50];  // The name of the product
    int quantity;    // The quantity of the product in stock
    float price;     // The price of the product
} Product;

// Define the structure of the inventory
typedef struct {
    Product products[MAX_PRODUCTS];  // The array of products
    int num_products;                // The number of products in the inventory
} Inventory;

// Create a new inventory
Inventory *create_inventory() {
    Inventory *inventory = malloc(sizeof(Inventory));
    inventory->num_products = 0;
    return inventory;
}

// Add a product to the inventory
void add_product(Inventory *inventory, Product product) {
    if (inventory->num_products < MAX_PRODUCTS) {
        inventory->products[inventory->num_products] = product;
        inventory->num_products++;
    } else {
        printf("Error: Inventory is full.\n");
    }
}

// Remove a product from the inventory
void remove_product(Inventory *inventory, char *name) {
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
void update_quantity(Inventory *inventory, char *name, int quantity) {
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            inventory->products[i].quantity = quantity;
            break;
        }
    }
}

// Print the inventory
void print_inventory(Inventory *inventory) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < inventory->num_products; i++) {
        printf("%s: %d units, $%.2f\n", inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
}

// Free the memory allocated for the inventory
void free_inventory(Inventory *inventory) {
    free(inventory);
}

// Main function
int main() {
    // Create a new inventory
    Inventory *inventory = create_inventory();

    // Add some products to the inventory
    Product product1 = {"Apple", 10, 1.00};
    add_product(inventory, product1);
    Product product2 = {"Orange", 5, 1.50};
    add_product(inventory, product2);
    Product product3 = {"Banana", 15, 2.00};
    add_product(inventory, product3);

    // Print the inventory
    print_inventory(inventory);

    // Remove a product from the inventory
    remove_product(inventory, "Orange");

    // Update the quantity of a product in the inventory
    update_quantity(inventory, "Apple", 20);

    // Print the inventory again
    print_inventory(inventory);

    // Free the memory allocated for the inventory
    free_inventory(inventory);

    return 0;
}