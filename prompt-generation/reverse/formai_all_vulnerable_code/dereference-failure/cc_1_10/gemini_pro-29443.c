//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store product information
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Function to create a new product
product create_product(int id, char *name, int quantity, float price) {
    product new_product;
    new_product.id = id;
    strcpy(new_product.name, name);
    new_product.quantity = quantity;
    new_product.price = price;
    return new_product;
}

// Function to add a new product to the inventory
void add_product(product *inventory, int *size, product new_product) {
    inventory[*size] = new_product;
    *size = *size + 1;
}

// Function to search for a product by ID
product *search_product_by_id(product *inventory, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == id) {
            return &inventory[i];
        }
    }
    return NULL;
}

// Function to search for a product by name
product *search_product_by_name(product *inventory, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return &inventory[i];
        }
    }
    return NULL;
}

// Function to update the quantity of a product
void update_product_quantity(product *inventory, int size, int id, int new_quantity) {
    product *product_to_update = search_product_by_id(inventory, size, id);
    if (product_to_update != NULL) {
        product_to_update->quantity = new_quantity;
    }
}

// Function to delete a product from the inventory
void delete_product(product *inventory, int *size, int id) {
    int index_to_delete = -1;
    for (int i = 0; i < *size; i++) {
        if (inventory[i].id == id) {
            index_to_delete = i;
            break;
        }
    }
    if (index_to_delete != -1) {
        for (int i = index_to_delete; i < *size - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        *size = *size - 1;
    }
}

// Function to print the inventory
void print_inventory(product *inventory, int size) {
    for (int i = 0; i < size; i++) {
        printf("Product ID: %d\n", inventory[i].id);
        printf("Product Name: %s\n", inventory[i].name);
        printf("Product Quantity: %d\n", inventory[i].quantity);
        printf("Product Price: %.2f\n\n", inventory[i].price);
    }
}

int main() {
    // Create an empty inventory
    product *inventory = malloc(0 * sizeof(product));
    int size = 0;

    // Add some products to the inventory
    product product1 = create_product(1, "Apple", 10, 1.0);
    add_product(inventory, &size, product1);
    product product2 = create_product(2, "Orange", 15, 1.5);
    add_product(inventory, &size, product2);
    product product3 = create_product(3, "Banana", 20, 2.0);
    add_product(inventory, &size, product3);

    // Search for a product by ID
    product *product_by_id = search_product_by_id(inventory, size, 2);
    if (product_by_id != NULL) {
        printf("Product found by ID: %s\n", product_by_id->name);
    } else {
        printf("Product not found by ID: 2\n");
    }

    // Search for a product by name
    product *product_by_name = search_product_by_name(inventory, size, "Banana");
    if (product_by_name != NULL) {
        printf("Product found by name: %s\n", product_by_name->name);
    } else {
        printf("Product not found by name: Banana\n");
    }

    // Update the quantity of a product
    update_product_quantity(inventory, size, 1, 15);
    product_by_id = search_product_by_id(inventory, size, 1);
    if (product_by_id != NULL) {
        printf("Product quantity updated: %s, new quantity: %d\n", product_by_id->name, product_by_id->quantity);
    }

    // Delete a product from the inventory
    delete_product(inventory, &size, 3);
    product_by_name = search_product_by_name(inventory, size, "Banana");
    if (product_by_name == NULL) {
        printf("Product deleted: Banana\n");
    }

    // Print the inventory
    print_inventory(inventory, size);

    // Free the memory allocated for the inventory
    free(inventory);

    return 0;
}