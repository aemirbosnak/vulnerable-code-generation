//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
} product;

// Function to create a new product
product* createProduct(int id, char name[], float price, int quantity) {
    product* p = (product*)malloc(sizeof(product));
    p->id = id;
    strcpy(p->name, name);
    p->price = price;
    p->quantity = quantity;
    return p;
}

// Function to add a product to the inventory
void addProduct(product** inventory, int* size, product* p) {
    *inventory = (product*)realloc(*inventory, (*size + 1) * sizeof(product));
    (*inventory)[*size] = *p;
    (*size)++;
}

// Function to remove a product from the inventory
void removeProduct(product** inventory, int* size, int id) {
    int i;
    for (i = 0; i < *size; i++) {
        if ((*inventory)[i].id == id) {
            (*inventory)[i] = (*inventory)[*size - 1];
            (*size)--;
            break;
        }
    }
}

// Function to update the quantity of a product in the inventory
void updateProductQuantity(product** inventory, int* size, int id, int quantity) {
    int i;
    for (i = 0; i < *size; i++) {
        if ((*inventory)[i].id == id) {
            (*inventory)[i].quantity = quantity;
            break;
        }
    }
}

// Function to print the inventory
void printInventory(product** inventory, int size) {
    int i;
    printf("Product Inventory\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for (i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\t%d\n", (*inventory)[i].id, (*inventory)[i].name, (*inventory)[i].price, (*inventory)[i].quantity);
    }
}

// Main function
int main() {
    // Create an empty inventory
    product** inventory = NULL;
    int size = 0;

    // Add some products to the inventory
    addProduct(&inventory, &size, createProduct(1, "Apple", 1.00, 10));
    addProduct(&inventory, &size, createProduct(2, "Orange", 1.50, 5));
    addProduct(&inventory, &size, createProduct(3, "Banana", 0.75, 15));

    // Print the inventory
    printInventory(inventory, size);

    // Remove a product from the inventory
    removeProduct(&inventory, &size, 2);

    // Update the quantity of a product in the inventory
    updateProductQuantity(&inventory, &size, 1, 20);

    // Print the inventory again
    printInventory(inventory, size);

    // Free the memory allocated for the inventory
    for (int i = 0; i < size; i++) {
        free(inventory[i]);
    }
    free(inventory);

    return 0;
}