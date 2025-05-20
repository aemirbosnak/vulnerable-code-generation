//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Define the product inventory structure
typedef struct product_inventory {
    int num_products;
    product *products;
} product_inventory;

// Create a new product inventory
product_inventory* create_product_inventory() {
    product_inventory *inventory = malloc(sizeof(product_inventory));
    inventory->num_products = 0;
    inventory->products = NULL;
    return inventory;
}

// Add a product to the product inventory
void add_product(product_inventory *inventory, product product) {
    // Allocate memory for the new product
    inventory->products = realloc(inventory->products, (inventory->num_products + 1) * sizeof(product));

    // Add the product to the array of products
    inventory->products[inventory->num_products] = product;

    // Increment the number of products
    inventory->num_products++;
}

// Remove a product from the product inventory
void remove_product(product_inventory *inventory, int id) {
    // Find the index of the product to be removed
    int index = -1;
    for (int i = 0; i < inventory->num_products; i++) {
        if (inventory->products[i].id == id) {
            index = i;
            break;
        }
    }

    // If the product was not found, return
    if (index == -1) {
        return;
    }

    // Shift the products after the one to be removed to the left
    for (int i = index; i < inventory->num_products - 1; i++) {
        inventory->products[i] = inventory->products[i + 1];
    }

    // Decrement the number of products
    inventory->num_products--;

    // Reallocate memory for the array of products
    inventory->products = realloc(inventory->products, inventory->num_products * sizeof(product));
}

// Get a product from the product inventory
product get_product(product_inventory *inventory, int id) {
    // Find the index of the product
    int index = -1;
    for (int i = 0; i < inventory->num_products; i++) {
        if (inventory->products[i].id == id) {
            index = i;
            break;
        }
    }

    // If the product was not found, return an empty product
    if (index == -1) {
        product empty_product = {0, "", 0, 0.0};
        return empty_product;
    }

    // Return the product
    return inventory->products[index];
}

// Print the product inventory
void print_product_inventory(product_inventory *inventory) {
    printf("Product Inventory:\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("| ID | Name | Quantity | Price |\n");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < inventory->num_products; i++) {
        product product = inventory->products[i];
        printf("| %-3d | %-20s | %-8d | %-6.2f |\n", product.id, product.name, product.quantity, product.price);
    }
    printf("--------------------------------------------------------------------------------\n");
}

// Main function
int main() {
    // Create a new product inventory
    product_inventory *inventory = create_product_inventory();

    // Add some products to the product inventory
    product product1 = {1, "Apple", 100, 0.5};
    add_product(inventory, product1);

    product product2 = {2, "Orange", 50, 0.75};
    add_product(inventory, product2);

    product product3 = {3, "Banana", 75, 1.0};
    add_product(inventory, product3);

    // Print the product inventory
    print_product_inventory(inventory);

    // Get a product from the product inventory
    product product4 = get_product(inventory, 2);

    // Print the product
    printf("Product 2:\n");
    printf("ID: %d\n", product4.id);
    printf("Name: %s\n", product4.name);
    printf("Quantity: %d\n", product4.quantity);
    printf("Price: %.2f\n", product4.price);

    // Remove a product from the product inventory
    remove_product(inventory, 2);

    // Print the product inventory
    print_product_inventory(inventory);

    // Free the memory allocated for the product inventory
    free(inventory->products);
    free(inventory);

    return 0;
}