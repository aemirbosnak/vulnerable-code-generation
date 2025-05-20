//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Define the inventory structure
typedef struct inventory {
    product products[100];
    int num_products;
} inventory;

// Create a new inventory
inventory* create_inventory() {
    inventory* inv = (inventory*)malloc(sizeof(inventory));
    inv->num_products = 0;
    return inv;
}

// Add a product to the inventory
void add_product(inventory* inv, product* p) {
    if (inv->num_products < 100) {
        inv->products[inv->num_products] = *p;
        inv->num_products++;
    } else {
        printf("Inventory is full!\n");
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
            return;
        }
    }
    printf("Product not found!\n");
}

// Update the quantity of a product in the inventory
void update_quantity(inventory* inv, char* name, int quantity) {
    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            inv->products[i].quantity = quantity;
            return;
        }
    }
    printf("Product not found!\n");
}

// Print the inventory
void print_inventory(inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("%s %d %.2f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Test the inventory system
int main() {
    // Create a new inventory
    inventory* inv = create_inventory();

    // Add some products to the inventory
    product p1 = {"Apple", 10, 1.0};
    add_product(inv, &p1);
    product p2 = {"Banana", 20, 2.0};
    add_product(inv, &p2);
    product p3 = {"Orange", 30, 3.0};
    add_product(inv, &p3);

    // Print the inventory
    print_inventory(inv);

    // Remove a product from the inventory
    remove_product(inv, "Banana");

    // Update the quantity of a product in the inventory
    update_quantity(inv, "Apple", 15);

    // Print the inventory
    print_inventory(inv);

    return 0;
}