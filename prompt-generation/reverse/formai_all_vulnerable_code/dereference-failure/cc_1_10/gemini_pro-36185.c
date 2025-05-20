//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
} product;

// Function to create a new product
product* createProduct(int id, char* name, float price, int quantity) {
    product* p = (product*)malloc(sizeof(product));
    p->id = id;
    strcpy(p->name, name);
    p->price = price;
    p->quantity = quantity;
    return p;
}

// Function to display a product
void displayProduct(product* p) {
    printf("ID: %d\n", p->id);
    printf("Name: %s\n", p->name);
    printf("Price: %.2f\n", p->price);
    printf("Quantity: %d\n\n", p->quantity);
}

// Function to add a product to the inventory
void addProduct(product** inventory, int* size, product* p) {
    *inventory = (product*)realloc(*inventory, (*size + 1) * sizeof(product));
    (*inventory)[*size] = *p;
    (*size)++;
}

// Function to search for a product by ID
product* searchProductById(product** inventory, int size, int id) {
    for (int i = 0; i < size; i++) {
        if ((*inventory)[i].id == id) {
            return &(*inventory)[i];
        }
    }
    return NULL;
}

// Function to update a product's quantity
void updateProductQuantity(product** inventory, int size, int id, int quantity) {
    product* p = searchProductById(inventory, size, id);
    if (p != NULL) {
        p->quantity = quantity;
    }
}

// Function to delete a product from the inventory
void deleteProduct(product** inventory, int* size, int id) {
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
        *size = *size - 1;
        *inventory = (product*)realloc(*inventory, (*size) * sizeof(product));
    }
}

// Main function
int main() {
    // Create an inventory of products
    product* inventory = NULL;
    int size = 0;

    // Add some products to the inventory
    addProduct(&inventory, &size, createProduct(1, "Apple", 1.00, 10));
    addProduct(&inventory, &size, createProduct(2, "Banana", 1.50, 15));
    addProduct(&inventory, &size, createProduct(3, "Orange", 2.00, 20));

    // Display the inventory
    printf("Inventory:\n");
    for (int i = 0; i < size; i++) {
        displayProduct(&inventory[i]);
    }

    // Search for a product by ID
    int id = 2;
    product* p = searchProductById(&inventory, size, id);
    if (p != NULL) {
        printf("Product found:\n");
        displayProduct(p);
    } else {
        printf("Product not found.\n");
    }

    // Update a product's quantity
    id = 1;
    int quantity = 15;
    updateProductQuantity(&inventory, size, id, quantity);

    // Display the updated inventory
    printf("Updated inventory:\n");
    for (int i = 0; i < size; i++) {
        displayProduct(&inventory[i]);
    }

    // Delete a product from the inventory
    id = 3;
    deleteProduct(&inventory, &size, id);

    // Display the updated inventory
    printf("Updated inventory:\n");
    for (int i = 0; i < size; i++) {
        displayProduct(&inventory[i]);
    }

    // Free the memory allocated for the inventory
    free(inventory);

    return 0;
}