//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products
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
    }
}

// Remove a product from the inventory
void remove_product(Inventory* inventory, char* name) {
    int index = -1;
    for (int i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < inventory->num_products - 1; i++) {
            inventory->products[i] = inventory->products[i + 1];
        }
        inventory->num_products--;
    }
}

// Find a product in the inventory
Product* find_product(Inventory* inventory, char* name) {
    for (int i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            return &inventory->products[i];
        }
    }
    return NULL;
}

// Print the inventory
void print_inventory(Inventory* inventory) {
    printf("Inventory:\n");
    for (int i = 0; i < inventory->num_products; i++) {
        printf("%s %d %.2f\n", inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
}

// Get the total value of the inventory
float get_total_value(Inventory* inventory) {
    float total_value = 0.0;
    for (int i = 0; i < inventory->num_products; i++) {
        total_value += inventory->products[i].quantity * inventory->products[i].price;
    }
    return total_value;
}

// Main function
int main() {
    // Create a new inventory
    Inventory* inventory = create_inventory();

    // Add some products to the inventory
    Product product1 = {"Apple", 10, 1.0};
    add_product(inventory, product1);
    Product product2 = {"Orange", 5, 1.5};
    add_product(inventory, product2);
    Product product3 = {"Banana", 15, 2.0};
    add_product(inventory, product3);

    // Print the inventory
    print_inventory(inventory);

    // Find a product in the inventory
    Product* product = find_product(inventory, "Apple");
    if (product != NULL) {
        printf("Found product: %s %d %.2f\n", product->name, product->quantity, product->price);
    } else {
        printf("Product not found\n");
    }

    // Remove a product from the inventory
    remove_product(inventory, "Orange");

    // Print the inventory
    print_inventory(inventory);

    // Get the total value of the inventory
    float total_value = get_total_value(inventory);
    printf("Total value of the inventory: %.2f\n", total_value);

    // Free the inventory
    free(inventory);

    return 0;
}