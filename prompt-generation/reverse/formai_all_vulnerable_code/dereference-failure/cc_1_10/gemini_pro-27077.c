//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function to create a new product
Product* createProduct(int id, char* name, int quantity, float price) {
    Product* product = (Product*)malloc(sizeof(Product));
    product->id = id;
    strcpy(product->name, name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to print product details
void printProduct(Product* product) {
    printf("ID: %d\n", product->id);
    printf("Name: %s\n", product->name);
    printf("Quantity: %d\n", product->quantity);
    printf("Price: %.2f\n", product->price);
}

// Function to add a product to the inventory
void addProduct(Product** inventory, int* size, Product* product) {
    *inventory = (Product*)realloc(*inventory, sizeof(Product) * (*size + 1));
    (*inventory)[*size] = *product;
    (*size)++;
}

// Function to remove a product from the inventory
void removeProduct(Product** inventory, int* size, int id) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if ((*inventory)[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < *size - 1; i++) {
            (*inventory)[i] = (*inventory)[i + 1];
        }
        *inventory = (Product*)realloc(*inventory, sizeof(Product) * (*size - 1));
        (*size)--;
    }
}

// Function to update the quantity of a product in the inventory
void updateProductQuantity(Product** inventory, int* size, int id, int quantity) {
    for (int i = 0; i < *size; i++) {
        if ((*inventory)[i].id == id) {
            (*inventory)[i].quantity = quantity;
            break;
        }
    }
}

// Function to search for a product in the inventory by name
Product* searchProductByName(Product** inventory, int* size, char* name) {
    for (int i = 0; i < *size; i++) {
        if (strcmp((*inventory)[i].name, name) == 0) {
            return &(*inventory)[i];
        }
    }
    return NULL;
}

// Function to print the inventory
void printInventory(Product** inventory, int* size) {
    printf("Inventory:\n");
    for (int i = 0; i < *size; i++) {
        printProduct(&(*inventory)[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create an empty inventory
    Product** inventory = NULL;
    int size = 0;

    // Add some products to the inventory
    addProduct(&inventory, &size, createProduct(1, "Apple", 10, 1.50));
    addProduct(&inventory, &size, createProduct(2, "Orange", 15, 2.00));
    addProduct(&inventory, &size, createProduct(3, "Banana", 20, 2.50));

    // Print the inventory
    printInventory(&inventory, &size);

    // Search for a product by name
    Product* product = searchProductByName(&inventory, &size, "Orange");
    if (product != NULL) {
        printf("Found product: ");
        printProduct(product);
        printf("\n");
    } else {
        printf("Product not found!\n");
    }

    // Update the quantity of a product
    updateProductQuantity(&inventory, &size, 2, 20);

    // Remove a product from the inventory
    removeProduct(&inventory, &size, 3);

    // Print the inventory again
    printInventory(&inventory, &size);

    // Free the memory allocated for the inventory
    for (int i = 0; i < size; i++) {
        free(inventory[i]);
    }
    free(inventory);

    return 0;
}