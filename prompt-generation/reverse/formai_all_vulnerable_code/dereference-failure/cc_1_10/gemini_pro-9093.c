//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: interoperable
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
} product;

// Define the structure of the inventory
typedef struct {
    product products[MAX_PRODUCTS];
    int num_products;
} inventory;

// Create a new inventory
inventory* create_inventory() {
    inventory* inv = (inventory*)malloc(sizeof(inventory));
    inv->num_products = 0;
    return inv;
}

// Add a product to the inventory
void add_product(inventory* inv, product* prod) {
    if (inv->num_products < MAX_PRODUCTS) {
        inv->products[inv->num_products] = *prod;
        inv->num_products++;
    } else {
        printf("Error: Inventory is full!\n");
    }
}

// Find a product in the inventory by name
product* find_product(inventory* inv, char* name) {
    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            return &inv->products[i];
        }
    }
    return NULL;
}

// Remove a product from the inventory
void remove_product(inventory* inv, char* name) {
    int index = -1;
    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < inv->num_products - 1; i++) {
            inv->products[i] = inv->products[i + 1];
        }
        inv->num_products--;
    } else {
        printf("Error: Product not found!\n");
    }
}

// Print the inventory
void print_inventory(inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("%s: %d, $%.2f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Main function
int main() {
    // Create a new inventory
    inventory* inv = create_inventory();

    // Add some products to the inventory
    product prod1 = {"Apple", 10, 0.50};
    add_product(inv, &prod1);
    product prod2 = {"Banana", 20, 0.75};
    add_product(inv, &prod2);
    product prod3 = {"Orange", 30, 1.00};
    add_product(inv, &prod3);

    // Find a product in the inventory
    product* prod = find_product(inv, "Apple");
    if (prod != NULL) {
        printf("Found product: %s, %d, $%.2f\n", prod->name, prod->quantity, prod->price);
    } else {
        printf("Product not found!\n");
    }

    // Remove a product from the inventory
    remove_product(inv, "Banana");

    // Print the inventory
    print_inventory(inv);

    // Free the memory allocated for the inventory
    free(inv);

    return 0;
}