//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Define the structure of the inventory
typedef struct inventory {
    product products[MAX_PRODUCTS];
    int num_products;
} inventory;

// Function to create a new product
product* create_product(int id, char* name, int quantity, float price) {
    product* new_product = malloc(sizeof(product));
    new_product->id = id;
    strcpy(new_product->name, name);
    new_product->quantity = quantity;
    new_product->price = price;
    return new_product;
}

// Function to add a product to the inventory
void add_product(inventory* inv, product* product) {
    if (inv->num_products == MAX_PRODUCTS) {
        printf("Error: Inventory is full.\n");
        return;
    }
    inv->products[inv->num_products++] = *product;
}

// Function to remove a product from the inventory
void remove_product(inventory* inv, int id) {
    for (int i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            for (int j = i; j < inv->num_products - 1; j++) {
                inv->products[j] = inv->products[j + 1];
            }
            inv->num_products--;
            return;
        }
    }
    printf("Error: Product not found.\n");
}

// Function to update the quantity of a product in the inventory
void update_product_quantity(inventory* inv, int id, int new_quantity) {
    for (int i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            inv->products[i].quantity = new_quantity;
            return;
        }
    }
    printf("Error: Product not found.\n");
}

// Function to print the inventory
void print_inventory(inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("Product %d: %s, Quantity: %d, Price: %.2f\n", inv->products[i].id, inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Main function
int main() {
    // Create a new inventory
    inventory inv;
    inv.num_products = 0;

    // Add some products to the inventory
    add_product(&inv, create_product(1, "Apple", 10, 1.0));
    add_product(&inv, create_product(2, "Orange", 15, 1.5));
    add_product(&inv, create_product(3, "Banana", 20, 2.0));

    // Print the inventory
    print_inventory(&inv);

    // Remove a product from the inventory
    remove_product(&inv, 2);

    // Update the quantity of a product in the inventory
    update_product_quantity(&inv, 1, 15);

    // Print the inventory again
    print_inventory(&inv);

    return 0;
}