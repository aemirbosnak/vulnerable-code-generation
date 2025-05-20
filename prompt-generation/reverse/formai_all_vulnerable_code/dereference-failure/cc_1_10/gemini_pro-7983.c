//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct Product {
    int id;
    char *name;
    float price;
    int quantity;
} Product;

// Function to create a new product
Product* createProduct(int id, char *name, float price, int quantity) {
    Product *product = (Product *)malloc(sizeof(Product));
    product->id = id;
    product->name = strdup(name);
    product->price = price;
    product->quantity = quantity;
    return product;
}

// Function to print a product
void printProduct(Product *product) {
    printf("ID: %d\n", product->id);
    printf("Name: %s\n", product->name);
    printf("Price: %.2f\n", product->price);
    printf("Quantity: %d\n", product->quantity);
    printf("\n");
}

// Function to add a product to the inventory
void addProduct(Product **inventory, int *size, Product *product) {
    *inventory = realloc(*inventory, (*size + 1) * sizeof(Product));
    (*inventory)[*size] = *product;
    (*size)++;
}

// Function to remove a product from the inventory
void removeProduct(Product **inventory, int *size, int id) {
    int i;
    for (i = 0; i < *size; i++) {
        if ((*inventory)[i].id == id) {
            break;
        }
    }

    if (i < *size) {
        for (i; i < *size - 1; i++) {
            (*inventory)[i] = (*inventory)[i + 1];
        }
        (*size)--;
        *inventory = realloc(*inventory, *size * sizeof(Product));
    }
}

// Function to update the quantity of a product in the inventory
void updateQuantity(Product **inventory, int *size, int id, int quantity) {
    int i;
    for (i = 0; i < *size; i++) {
        if ((*inventory)[i].id == id) {
            (*inventory)[i].quantity = quantity;
            break;
        }
    }
}

// Function to search for a product in the inventory by name
Product* searchProductByName(Product **inventory, int *size, char *name) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp((*inventory)[i].name, name) == 0) {
            return &(*inventory)[i];
        }
    }
    return NULL;
}

// Function to print the inventory
void printInventory(Product **inventory, int *size) {
    int i;
    for (i = 0; i < *size; i++) {
        printProduct(&(*inventory)[i]);
    }
}

// Main function
int main() {
    // Initialize the inventory
    Product *inventory = NULL;
    int size = 0;

    // Add some products to the inventory
    addProduct(&inventory, &size, createProduct(1, "Apple", 1.0, 10));
    addProduct(&inventory, &size, createProduct(2, "Orange", 1.5, 5));
    addProduct(&inventory, &size, createProduct(3, "Banana", 2.0, 3));

    // Print the inventory
    printf("Inventory:\n");
    printInventory(&inventory, &size);

    // Search for a product by name
    Product *product = searchProductByName(&inventory, &size, "Apple");
    if (product != NULL) {
        printf("Found product:\n");
        printProduct(product);
    } else {
        printf("Product not found.\n");
    }

    // Update the quantity of a product
    updateQuantity(&inventory, &size, 2, 10);

    // Print the inventory again
    printf("Updated inventory:\n");
    printInventory(&inventory, &size);

    // Remove a product from the inventory
    removeProduct(&inventory, &size, 3);

    // Print the inventory again
    printf("Updated inventory after removing a product:\n");
    printInventory(&inventory, &size);

    // Free the memory allocated for the inventory
    int i;
    for (i = 0; i < size; i++) {
        free(inventory[i].name);
    }
    free(inventory);

    return 0;
}