//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function to create a new product
Product* createProduct(int id, char *name, int quantity, float price) {
    Product *product = (Product*)malloc(sizeof(Product));
    product->id = id;
    strcpy(product->name, name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to display a product
void displayProduct(Product *product) {
    printf("ID: %d\n", product->id);
    printf("Name: %s\n", product->name);
    printf("Quantity: %d\n", product->quantity);
    printf("Price: %.2f\n", product->price);
}

// Function to add a product to the inventory
void addProduct(Product **inventory, int *inventorySize, Product *product) {
    *inventory = (Product*)realloc(*inventory, (*inventorySize + 1) * sizeof(Product));
    (*inventory)[*inventorySize] = *product;
    (*inventorySize)++;
}

// Function to remove a product from the inventory
void removeProduct(Product **inventory, int *inventorySize, int id) {
    int index = -1;
    for (int i = 0; i < *inventorySize; i++) {
        if ((*inventory)[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < *inventorySize - 1; i++) {
            (*inventory)[i] = (*inventory)[i + 1];
        }
        (*inventorySize)--;
    }
}

// Function to update the quantity of a product in the inventory
void updateProductQuantity(Product **inventory, int *inventorySize, int id, int quantity) {
    int index = -1;
    for (int i = 0; i < *inventorySize; i++) {
        if ((*inventory)[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        (*inventory)[index].quantity = quantity;
    }
}

// Function to search for a product in the inventory
Product* searchProduct(Product **inventory, int *inventorySize, int id) {
    for (int i = 0; i < *inventorySize; i++) {
        if ((*inventory)[i].id == id) {
            return &(*inventory)[i];
        }
    }
    return NULL;
}

// Function to display the entire inventory
void displayInventory(Product **inventory, int *inventorySize) {
    for (int i = 0; i < *inventorySize; i++) {
        displayProduct(&(*inventory)[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the inventory
    Product **inventory = (Product**)malloc(0);
    int inventorySize = 0;

    // Add some products to the inventory
    addProduct(&inventory, &inventorySize, createProduct(1, "Apple", 10, 1.0));
    addProduct(&inventory, &inventorySize, createProduct(2, "Orange", 15, 1.5));
    addProduct(&inventory, &inventorySize, createProduct(3, "Banana", 20, 2.0));

    // Display the entire inventory
    printf("Initial Inventory:\n");
    displayInventory(&inventory, &inventorySize);

    // Search for a product in the inventory
    Product *product = searchProduct(&inventory, &inventorySize, 2);
    if (product != NULL) {
        printf("Found product:\n");
        displayProduct(product);
    } else {
        printf("Product not found.\n");
    }

    // Update the quantity of a product in the inventory
    updateProductQuantity(&inventory, &inventorySize, 1, 15);

    // Display the updated inventory
    printf("Updated Inventory:\n");
    displayInventory(&inventory, &inventorySize);

    // Remove a product from the inventory
    removeProduct(&inventory, &inventorySize, 3);

    // Display the updated inventory
    printf("Final Inventory:\n");
    displayInventory(&inventory, &inventorySize);

    // Free the allocated memory
    for (int i = 0; i < inventorySize; i++) {
        free(inventory[i]);
    }
    free(inventory);

    return 0;
}