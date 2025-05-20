//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Define the structure of the inventory
typedef struct inventory {
    product products[MAX_PRODUCTS];
    int num_products;
} inventory;

// Create a new inventory
inventory* create_inventory() {
    inventory* inv = malloc(sizeof(inventory));
    inv->num_products = 0;
    return inv;
}

// Add a product to the inventory
void add_product(inventory* inv, char* name, int quantity, float price) {
    // Check if the inventory is full
    if (inv->num_products == MAX_PRODUCTS) {
        printf("Error: Inventory is full.\n");
        return;
    }

    // Add the product to the inventory
    strcpy(inv->products[inv->num_products].name, name);
    inv->products[inv->num_products].quantity = quantity;
    inv->products[inv->num_products].price = price;
    inv->num_products++;
}

// Remove a product from the inventory
void remove_product(inventory* inv, char* name) {
    // Find the product in the inventory
    int index = -1;
    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the product was not found
    if (index == -1) {
        printf("Error: Product not found.\n");
        return;
    }

    // Remove the product from the inventory
    for (int i = index; i < inv->num_products - 1; i++) {
        inv->products[i] = inv->products[i + 1];
    }
    inv->num_products--;
}

// Get the quantity of a product in the inventory
int get_quantity(inventory* inv, char* name) {
    // Find the product in the inventory
    int index = -1;
    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the product was not found
    if (index == -1) {
        printf("Error: Product not found.\n");
        return -1;
    }

    // Return the quantity of the product
    return inv->products[index].quantity;
}

// Get the price of a product in the inventory
float get_price(inventory* inv, char* name) {
    // Find the product in the inventory
    int index = -1;
    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the product was not found
    if (index == -1) {
        printf("Error: Product not found.\n");
        return -1;
    }

    // Return the price of the product
    return inv->products[index].price;
}

// Print the inventory
void print_inventory(inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("  %s: %d (%f)\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Main function
int main() {
    // Create a new inventory
    inventory* inv = create_inventory();

    // Add some products to the inventory
    add_product(inv, "Apple", 10, 1.00);
    add_product(inv, "Orange", 5, 1.50);
    add_product(inv, "Banana", 15, 2.00);

    // Print the inventory
    print_inventory(inv);

    // Get the quantity of an apple
    int quantity = get_quantity(inv, "Apple");
    printf("Quantity of apples: %d\n", quantity);

    // Get the price of an orange
    float price = get_price(inv, "Orange");
    printf("Price of oranges: %f\n", price);

    // Remove an orange from the inventory
    remove_product(inv, "Orange");

    // Print the inventory
    print_inventory(inv);

    // Free the inventory
    free(inv);

    return 0;
}