//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store product information
typedef struct product {
    int id;
    char name[256];
    int quantity;
    float price;
} product_t;

// Function to create a new product
product_t* create_product(int id, char* name, int quantity, float price) {
    product_t* product = (product_t*)malloc(sizeof(product_t));
    product->id = id;
    strcpy(product->name, name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to print product information
void print_product(product_t* product) {
    printf("Product ID: %d\n", product->id);
    printf("Product Name: %s\n", product->name);
    printf("Product Quantity: %d\n", product->quantity);
    printf("Product Price: %.2f\n", product->price);
}

// Function to add a product to the inventory
void add_product(product_t** inventory, int* inventory_size, product_t* product) {
    *inventory = (product_t*)realloc(*inventory, (*inventory_size + 1) * sizeof(product_t));
    (*inventory)[*inventory_size] = *product;
    (*inventory_size)++;
}

// Function to remove a product from the inventory
void remove_product(product_t** inventory, int* inventory_size, int id) {
    int index = -1;
    for (int i = 0; i < *inventory_size; i++) {
        if ((*inventory)[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < *inventory_size - 1; i++) {
            (*inventory)[i] = (*inventory)[i + 1];
        }
        *inventory = (product_t*)realloc(*inventory, (*inventory_size - 1) * sizeof(product_t));
        (*inventory_size)--;
    }
}

// Function to update a product in the inventory
void update_product(product_t** inventory, int* inventory_size, int id, product_t* product) {
    int index = -1;
    for (int i = 0; i < *inventory_size; i++) {
        if ((*inventory)[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        (*inventory)[index] = *product;
    }
}

// Function to search for a product in the inventory by ID
product_t* search_product_by_id(product_t* inventory, int inventory_size, int id) {
    for (int i = 0; i < inventory_size; i++) {
        if (inventory[i].id == id) {
            return &inventory[i];
        }
    }
    return NULL;
}

// Function to search for a product in the inventory by name
product_t* search_product_by_name(product_t* inventory, int inventory_size, char* name) {
    for (int i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return &inventory[i];
        }
    }
    return NULL;
}

// Main function
int main() {
    // Create an empty inventory
    product_t* inventory = NULL;
    int inventory_size = 0;

    // Add some products to the inventory
    product_t* product1 = create_product(1, "Apple", 10, 1.0f);
    add_product(&inventory, &inventory_size, product1);
    product_t* product2 = create_product(2, "Banana", 20, 2.0f);
    add_product(&inventory, &inventory_size, product2);
    product_t* product3 = create_product(3, "Orange", 30, 3.0f);
    add_product(&inventory, &inventory_size, product3);

    // Print the inventory
    printf("Inventory:\n");
    for (int i = 0; i < inventory_size; i++) {
        print_product(&inventory[i]);
        printf("\n");
    }

    // Search for a product by ID
    product_t* product = search_product_by_id(inventory, inventory_size, 2);
    if (product != NULL) {
        printf("Product found: ");
        print_product(product);
        printf("\n");
    } else {
        printf("Product not found.\n");
    }

    // Search for a product by name
    product = search_product_by_name(inventory, inventory_size, "Orange");
    if (product != NULL) {
        printf("Product found: ");
        print_product(product);
        printf("\n");
    } else {
        printf("Product not found.\n");
    }

    // Update a product
    product->quantity = 40;
    update_product(&inventory, &inventory_size, 3, product);

    // Print the updated inventory
    printf("Updated inventory:\n");
    for (int i = 0; i < inventory_size; i++) {
        print_product(&inventory[i]);
        printf("\n");
    }

    // Remove a product
    remove_product(&inventory, &inventory_size, 2);

    // Print the updated inventory
    printf("Updated inventory:\n");
    for (int i = 0; i < inventory_size; i++) {
        print_product(&inventory[i]);
        printf("\n");
    }

    // Free the memory allocated for the inventory
    for (int i = 0; i < inventory_size; i++) {
        free(&inventory[i]);
    }
    free(inventory);

    return 0;
}