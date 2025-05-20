//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: detailed
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
    if (inv->num_products < MAX_PRODUCTS) {
        strcpy(inv->products[inv->num_products].name, name);
        inv->products[inv->num_products].quantity = quantity;
        inv->products[inv->num_products].price = price;
        inv->num_products++;
    }
}

// Remove a product from the inventory
void remove_product(inventory* inv, char* name) {
    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            for (int j = i; j < inv->num_products - 1; j++) {
                inv->products[j] = inv->products[j + 1];
            }
            inv->num_products--;
            break;
        }
    }
}

// Update the quantity of a product in the inventory
void update_quantity(inventory* inv, char* name, int quantity) {
    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            inv->products[i].quantity = quantity;
            break;
        }
    }
}

// Update the price of a product in the inventory
void update_price(inventory* inv, char* name, float price) {
    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            inv->products[i].price = price;
            break;
        }
    }
}

// Print the inventory
void print_inventory(inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("%s: %d units, $%.2f each\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Get the total value of the inventory
float get_total_value(inventory* inv) {
    float total_value = 0;
    for (int i = 0; i < inv->num_products; i++) {
        total_value += inv->products[i].quantity * inv->products[i].price;
    }
    return total_value;
}

// Free the memory allocated for the inventory
void free_inventory(inventory* inv) {
    free(inv);
}

// Main function
int main() {
    // Create a new inventory
    inventory* inv = create_inventory();

    // Add some products to the inventory
    add_product(inv, "Apple", 100, 0.50);
    add_product(inv, "Orange", 50, 0.75);
    add_product(inv, "Banana", 25, 1.00);

    // Print the inventory
    print_inventory(inv);

    // Get the total value of the inventory
    float total_value = get_total_value(inv);
    printf("Total value of the inventory: $%.2f\n", total_value);

    // Update the quantity of an existing product
    update_quantity(inv, "Apple", 75);

    // Update the price of an existing product
    update_price(inv, "Orange", 0.80);

    // Print the inventory again
    print_inventory(inv);

    // Get the total value of the inventory again
    total_value = get_total_value(inv);
    printf("Total value of the inventory: $%.2f\n", total_value);

    // Free the memory allocated for the inventory
    free_inventory(inv);

    return 0;
}