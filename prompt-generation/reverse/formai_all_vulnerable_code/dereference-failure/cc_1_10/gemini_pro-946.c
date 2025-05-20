//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct Product {
    int id;
    char *name;
    int quantity;
    double price;
} Product;

// Function to create a new product
Product *createProduct(int id, char *name, int quantity, double price) {
    Product *product = (Product *)malloc(sizeof(Product));
    product->id = id;
    product->name = strdup(name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to print a product
void printProduct(Product *product) {
    printf("Product ID: %d\n", product->id);
    printf("Product Name: %s\n", product->name);
    printf("Product Quantity: %d\n", product->quantity);
    printf("Product Price: %.2f\n\n", product->price);
}

// Function to add a product to the inventory
void addProduct(Product **inventory, int *inventorySize, Product *product) {
    *inventory = realloc(*inventory, (*inventorySize + 1) * sizeof(Product));
    (*inventory)[*inventorySize] = *product;
    (*inventorySize)++;
}

// Function to remove a product from the inventory
void removeProduct(Product **inventory, int *inventorySize, int id) {
    int i;
    for (i = 0; i < *inventorySize; i++) {
        if ((*inventory)[i].id == id) {
            break;
        }
    }
    if (i == *inventorySize) {
        printf("Product not found\n");
        return;
    }
    for (i; i < *inventorySize - 1; i++) {
        (*inventory)[i] = (*inventory)[i + 1];
    }
    (*inventorySize)--;
    *inventory = realloc(*inventory, *inventorySize * sizeof(Product));
}

// Function to search for a product in the inventory
Product *searchProduct(Product **inventory, int *inventorySize, int id) {
    int i;
    for (i = 0; i < *inventorySize; i++) {
        if ((*inventory)[i].id == id) {
            return &(*inventory)[i];
        }
    }
    return NULL;
}

// Function to print the inventory
void printInventory(Product **inventory, int *inventorySize) {
    int i;
    for (i = 0; i < *inventorySize; i++) {
        printProduct(&(*inventory)[i]);
    }
}

// Main function
int main() {
    // Create an inventory
    Product *inventory = NULL;
    int inventorySize = 0;

    // Add some products to the inventory
    addProduct(&inventory, &inventorySize, createProduct(1, "Apple", 10, 1.0));
    addProduct(&inventory, &inventorySize, createProduct(2, "Orange", 5, 1.5));
    addProduct(&inventory, &inventorySize, createProduct(3, "Banana", 15, 2.0));

    // Print the inventory
    printInventory(&inventory, &inventorySize);

    // Search for a product in the inventory
    Product *product = searchProduct(&inventory, &inventorySize, 2);
    if (product) {
        printf("Product found:\n");
        printProduct(product);
    } else {
        printf("Product not found\n");
    }

    // Remove a product from the inventory
    removeProduct(&inventory, &inventorySize, 3);

    // Print the inventory
    printInventory(&inventory, &inventorySize);

    // Free the memory allocated for the inventory
    for (int i = 0; i < inventorySize; i++) {
        free(inventory[i].name);
    }
    free(inventory);

    return 0;
}