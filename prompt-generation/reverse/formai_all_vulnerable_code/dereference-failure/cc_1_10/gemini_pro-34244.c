//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Function to create a new product
product* createProduct(int id, char name[], int quantity, float price) {
    product* newProduct = (product*)malloc(sizeof(product));
    newProduct->id = id;
    strcpy(newProduct->name, name);
    newProduct->quantity = quantity;
    newProduct->price = price;
    return newProduct;
}

// Function to add a product to the inventory
void addProduct(product* products[], int* numProducts, product* newProduct) {
    products[*numProducts] = newProduct;
    (*numProducts)++;
}

// Function to remove a product from the inventory
void removeProduct(product* products[], int* numProducts, int id) {
    int i;
    for (i = 0; i < *numProducts; i++) {
        if (products[i]->id == id) {
            products[i] = products[*numProducts - 1];
            (*numProducts)--;
            break;
        }
    }
}

// Function to update the quantity of a product in the inventory
void updateProduct(product* products[], int* numProducts, int id, int newQuantity) {
    int i;
    for (i = 0; i < *numProducts; i++) {
        if (products[i]->id == id) {
            products[i]->quantity = newQuantity;
            break;
        }
    }
}

// Function to print the inventory
void printInventory(product* products[], int numProducts) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < numProducts; i++) {
        printf("%d %s %d %.2f\n", products[i]->id, products[i]->name, products[i]->quantity, products[i]->price);
    }
}

// Main function
int main() {
    int numProducts = 0;
    product* products[100];

    // Create some products
    product* product1 = createProduct(1, "Product 1", 10, 10.00);
    product* product2 = createProduct(2, "Product 2", 20, 20.00);
    product* product3 = createProduct(3, "Product 3", 30, 30.00);

    // Add the products to the inventory
    addProduct(products, &numProducts, product1);
    addProduct(products, &numProducts, product2);
    addProduct(products, &numProducts, product3);

    // Print the inventory
    printInventory(products, numProducts);

    // Remove a product from the inventory
    removeProduct(products, &numProducts, 2);

    // Print the inventory
    printInventory(products, numProducts);

    // Update the quantity of a product in the inventory
    updateProduct(products, &numProducts, 1, 15);

    // Print the inventory
    printInventory(products, numProducts);

    return 0;
}