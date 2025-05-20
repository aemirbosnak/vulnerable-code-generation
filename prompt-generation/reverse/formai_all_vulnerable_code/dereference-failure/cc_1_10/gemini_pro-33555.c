//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
// Inventory Management System in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct Product {
    int id;
    char name[50];
    int quantity;
    double price;
} Product;

// Function to create a new product
Product* createProduct(int id, char* name, int quantity, double price) {
    Product* product = (Product*) malloc(sizeof(Product));
    product->id = id;
    strcpy(product->name, name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to display a product
void displayProduct(Product* product) {
    printf("Product ID: %d\n", product->id);
    printf("Product Name: %s\n", product->name);
    printf("Product Quantity: %d\n", product->quantity);
    printf("Product Price: %.2f\n", product->price);
}

// Function to add a product to the inventory
void addProduct(Product** inventory, int* count, Product* product) {
    // Reallocate the inventory to make space for the new product
    *inventory = realloc(*inventory, (*count + 1) * sizeof(Product));
    // Add the new product to the inventory
    (*inventory)[*count] = *product;
    // Increment the count of products in the inventory
    (*count)++;
}

// Function to remove a product from the inventory
void removeProduct(Product** inventory, int* count, int id) {
    // Find the index of the product to be removed
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if ((*inventory)[i].id == id) {
            index = i;
            break;
        }
    }
    // If the product was found, remove it from the inventory
    if (index != -1) {
        for (int i = index; i < *count - 1; i++) {
            (*inventory)[i] = (*inventory)[i + 1];
        }
        // Decrement the count of products in the inventory
        (*count)--;
        // Reallocate the inventory to reduce its size
        *inventory = realloc(*inventory, *count * sizeof(Product));
    }
}

// Function to update the quantity of a product in the inventory
void updateProductQuantity(Product** inventory, int* count, int id, int newQuantity) {
    // Find the index of the product to be updated
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if ((*inventory)[i].id == id) {
            index = i;
            break;
        }
    }
    // If the product was found, update its quantity
    if (index != -1) {
        (*inventory)[index].quantity = newQuantity;
    }
}

// Function to search for a product in the inventory
Product* searchProduct(Product** inventory, int* count, int id) {
    // Find the index of the product to be searched
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if ((*inventory)[i].id == id) {
            index = i;
            break;
        }
    }
    // If the product was found, return it
    if (index != -1) {
        return &(*inventory)[index];
    } else {
        return NULL;
    }
}

// Function to print the inventory
void printInventory(Product** inventory, int* count) {
    printf("Inventory:\n");
    for (int i = 0; i < *count; i++) {
        displayProduct(&(*inventory)[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the inventory
    Product* inventory = NULL;
    int count = 0;

    // Add some products to the inventory
    addProduct(&inventory, &count, createProduct(1, "Apple", 10, 1.00));
    addProduct(&inventory, &count, createProduct(2, "Orange", 5, 1.50));
    addProduct(&inventory, &count, createProduct(3, "Banana", 15, 2.00));

    // Print the inventory
    printInventory(&inventory, &count);

    // Search for a product in the inventory
    Product* product = searchProduct(&inventory, &count, 2);
    if (product != NULL) {
        printf("Product found:\n");
        displayProduct(product);
    } else {
        printf("Product not found.\n");
    }

    // Update the quantity of a product in the inventory
    updateProductQuantity(&inventory, &count, 1, 15);

    // Print the updated inventory
    printInventory(&inventory, &count);

    // Remove a product from the inventory
    removeProduct(&inventory, &count, 3);

    // Print the updated inventory
    printInventory(&inventory, &count);

    // Free the memory allocated for the inventory
    free(inventory);

    return 0;
}