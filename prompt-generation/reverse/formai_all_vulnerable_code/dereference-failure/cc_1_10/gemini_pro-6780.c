//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A heartfelt thank you for using my C Product Inventory System! I am honored to be of assistance. 

// Define the maximum number of products that can be stored in the system.
#define MAX_PRODUCTS 100

// Define the structure of a product.
typedef struct product {
    char name[50];
    int quantity;
    double price;
} product;

// Define the structure of the inventory system.
typedef struct inventory_system {
    product products[MAX_PRODUCTS];
    int num_products;
} inventory_system;

// Create a new inventory system.
inventory_system* create_inventory_system() {
    inventory_system* system = malloc(sizeof(inventory_system));
    system->num_products = 0;
    return system;
}

// Add a product to the inventory system.
void add_product(inventory_system* system, char* name, int quantity, double price) {
    strcpy(system->products[system->num_products].name, name);
    system->products[system->num_products].quantity = quantity;
    system->products[system->num_products].price = price;
    system->num_products++;
}

// Remove a product from the inventory system.
void remove_product(inventory_system* system, char* name) {
    int i;
    for (i = 0; i < system->num_products; i++) {
        if (strcmp(system->products[i].name, name) == 0) {
            system->products[i] = system->products[system->num_products - 1];
            system->num_products--;
            break;
        }
    }
}

// Update the quantity of a product in the inventory system.
void update_quantity(inventory_system* system, char* name, int quantity) {
    int i;
    for (i = 0; i < system->num_products; i++) {
        if (strcmp(system->products[i].name, name) == 0) {
            system->products[i].quantity = quantity;
            break;
        }
    }
}

// Update the price of a product in the inventory system.
void update_price(inventory_system* system, char* name, double price) {
    int i;
    for (i = 0; i < system->num_products; i++) {
        if (strcmp(system->products[i].name, name) == 0) {
            system->products[i].price = price;
            break;
        }
    }
}

// Print the inventory system.
void print_inventory_system(inventory_system* system) {
    int i;
    printf("Thank you for choosing our inventory system. Here is a list of products and their details:\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("| Name | Quantity | Price |");
    printf("---------------------------------------------------------------------------------\n");
    for (i = 0; i < system->num_products; i++) {
        printf("| %-20s | %-8d | %-6.2f |", system->products[i].name, system->products[i].quantity, system->products[i].price);
        printf("\n---------------------------------------------------------------------------------\n");
    }
}

// Free the memory allocated for the inventory system.
void free_inventory_system(inventory_system* system) {
    free(system);
}

// Main function.
int main() {
    // Create an inventory system.
    inventory_system* system = create_inventory_system();

    // Add some products to the inventory system.
    add_product(system, "Apple", 10, 1.00);
    add_product(system, "Orange", 20, 1.50);
    add_product(system, "Banana", 15, 1.25);
    add_product(system, "Grape", 25, 2.00);
    add_product(system, "Strawberry", 18, 1.75);

    // Print the inventory system.
    print_inventory_system(system);

    // Remove a product from the inventory system.
    remove_product(system, "Apple");

    // Update the quantity of a product in the inventory system.
    update_quantity(system, "Orange", 30);

    // Update the price of a product in the inventory system.
    update_price(system, "Banana", 1.40);

    // Print the inventory system again.
    print_inventory_system(system);

    // Free the memory allocated for the inventory system.
    free_inventory_system(system);

    return 0;
}