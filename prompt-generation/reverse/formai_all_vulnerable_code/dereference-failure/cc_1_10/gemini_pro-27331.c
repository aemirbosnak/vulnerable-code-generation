//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
} product;

// Create a new product
product *create_product(int id, char *name, float price, int quantity) {
    product *p = (product *)malloc(sizeof(product));
    p->id = id;
    strcpy(p->name, name);
    p->price = price;
    p->quantity = quantity;
    return p;
}

// Add a product to the inventory
void add_product(product **inventory, int *inventory_size, product *p) {
    *inventory = (product *)realloc(*inventory, (*inventory_size + 1) * sizeof(product));
    (*inventory)[*inventory_size] = *p;
    *inventory_size = *inventory_size + 1;
}

// Find a product by ID
product *find_product_by_id(product *inventory, int inventory_size, int id) {
    for (int i = 0; i < inventory_size; i++) {
        if (inventory[i].id == id) {
            return &inventory[i];
        }
    }
    return NULL;
}

// Find a product by name
product *find_product_by_name(product *inventory, int inventory_size, char *name) {
    for (int i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return &inventory[i];
        }
    }
    return NULL;
}

// Print the inventory
void print_inventory(product *inventory, int inventory_size) {
    printf("Product Inventory:\n");
    printf("------------------\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < inventory_size; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("------------------\n");
}

// Main function
int main() {
    // Create an empty inventory
    product *inventory = NULL;
    int inventory_size = 0;

    // Add some products to the inventory
    add_product(&inventory, &inventory_size, create_product(1, "Apple", 1.00, 10));
    add_product(&inventory, &inventory_size, create_product(2, "Orange", 1.50, 5));
    add_product(&inventory, &inventory_size, create_product(3, "Banana", 2.00, 15));

    // Print the inventory
    print_inventory(inventory, inventory_size);

    // Find a product by ID
    product *p = find_product_by_id(inventory, inventory_size, 2);
    if (p != NULL) {
        printf("Found product by ID: %d\n", p->id);
    } else {
        printf("Product not found by ID: 2\n");
    }

    // Find a product by name
    p = find_product_by_name(inventory, inventory_size, "Banana");
    if (p != NULL) {
        printf("Found product by name: %s\n", p->name);
    } else {
        printf("Product not found by name: Banana\n");
    }

    // Free the inventory
    for (int i = 0; i < inventory_size; i++) {
        free(&inventory[i]);
    }
    free(inventory);

    return 0;
}