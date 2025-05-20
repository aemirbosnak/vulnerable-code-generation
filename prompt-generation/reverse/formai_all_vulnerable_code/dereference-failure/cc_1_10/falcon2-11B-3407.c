//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Struct for Product
typedef struct product {
    int id;
    char name[50];
    float price;
} product_t;

// Struct for Inventory
typedef struct inventory {
    int size;
    product_t *products;
} inventory_t;

// Function to create a new product
product_t *create_product(int id, char *name, float price) {
    product_t *new_product = malloc(sizeof(product_t));
    if (new_product == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    new_product->id = id;
    strcpy(new_product->name, name);
    new_product->price = price;

    return new_product;
}

// Function to display the product
void display_product(product_t *product) {
    printf("ID: %d\n", product->id);
    printf("Name: %s\n", product->name);
    printf("Price: %.2f\n", product->price);
}

// Function to add a product to the inventory
void add_product(inventory_t *inventory, product_t *product) {
    if (inventory->size == 0) {
        inventory->products = product;
    } else {
        inventory->products = realloc(inventory->products, (inventory->size + 1) * sizeof(product_t));
        if (inventory->products == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        inventory->products[inventory->size] = *product;
    }

    inventory->size++;
}

// Function to remove a product from the inventory
void remove_product(inventory_t *inventory, int id) {
    if (inventory->size == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    for (int i = 0; i < inventory->size; i++) {
        if (inventory->products[i].id == id) {
            inventory->products[i] = inventory->products[inventory->size - 1];
            inventory->size--;
            break;
        }
    }

    if (inventory->size == 0) {
        free(inventory->products);
        inventory->products = NULL;
    }
}

// Function to search for a product in the inventory
product_t *search_product(inventory_t *inventory, int id) {
    for (int i = 0; i < inventory->size; i++) {
        if (inventory->products[i].id == id) {
            return &inventory->products[i];
        }
    }

    return NULL;
}

// Function to get the number of products in the inventory
int get_product_count(inventory_t *inventory) {
    return inventory->size;
}

// Function to print the entire inventory
void print_inventory(inventory_t *inventory) {
    for (int i = 0; i < inventory->size; i++) {
        display_product(&inventory->products[i]);
    }
}

int main() {
    inventory_t inventory;
    inventory.size = 0;
    inventory.products = NULL;

    // Create products
    product_t *product1 = create_product(1, "Apple", 0.5);
    product_t *product2 = create_product(2, "Banana", 0.3);
    product_t *product3 = create_product(3, "Orange", 0.4);

    // Add products to the inventory
    add_product(&inventory, product1);
    add_product(&inventory, product2);
    add_product(&inventory, product3);

    // Print the inventory
    printf("Product Inventory:\n");
    print_inventory(&inventory);

    // Remove a product from the inventory
    remove_product(&inventory, 2);

    // Print the updated inventory
    printf("\nUpdated Product Inventory:\n");
    print_inventory(&inventory);

    // Search for a product in the inventory
    product_t *found_product = search_product(&inventory, 2);
    if (found_product!= NULL) {
        display_product(found_product);
    } else {
        printf("Product not found in the inventory!\n");
    }

    return 0;
}