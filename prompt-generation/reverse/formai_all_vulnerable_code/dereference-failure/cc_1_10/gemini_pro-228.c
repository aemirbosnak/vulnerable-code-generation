//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store product information
typedef struct Product {
    int id;
    char name[50];
    int quantity;
    double price;
} Product;

// Function to create a new product
Product* createProduct(int id, char* name, int quantity, double price) {
    Product* product = (Product*)malloc(sizeof(Product));
    product->id = id;
    strcpy(product->name, name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to print product details
void printProduct(Product* product) {
    printf("Product ID: %d\n", product->id);
    printf("Product Name: %s\n", product->name);
    printf("Product Quantity: %d\n", product->quantity);
    printf("Product Price: $%.2f\n", product->price);
}

// Main function
int main() {
    // Create an array of products
    Product* products[] = {
        createProduct(1, "Apple", 100, 1.0),
        createProduct(2, "Orange", 50, 1.5),
        createProduct(3, "Banana", 75, 2.0),
        createProduct(4, "Grape", 125, 3.0),
        createProduct(5, "Strawberry", 100, 4.0)
    };

    // Print the details of each product
    for (int i = 0; i < 5; i++) {
        printProduct(products[i]);
        printf("\n");
    }

    // Search for a product by name
    char searchName[50];
    printf("Enter the name of the product you want to search for: ");
    scanf("%s", searchName);

    Product* foundProduct = NULL;
    for (int i = 0; i < 5; i++) {
        if (strcmp(products[i]->name, searchName) == 0) {
            foundProduct = products[i];
            break;
        }
    }

    // Print the details of the found product
    if (foundProduct != NULL) {
        printf("Product found:\n");
        printProduct(foundProduct);
    } else {
        printf("Product not found.\n");
    }

    return 0;
}