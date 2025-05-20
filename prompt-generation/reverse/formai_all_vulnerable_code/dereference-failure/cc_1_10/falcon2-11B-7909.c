//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold product details
struct Product {
    char name[50];
    int quantity;
};

void addProduct(struct Product* products, int size) {
    // Prompt user for new product details
    printf("Enter new product name: ");
    fgets(products[size].name, sizeof(products[size].name), stdin);
    
    // Check if product is already present
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(products[i].name, products[size].name) == 0) {
            printf("Product already exists!\n");
            return;
        }
    }
    
    // Add new product to list
    products[size].quantity = 0;
    printf("Product added successfully!\n");
}

void displayProducts(struct Product* products, int size) {
    // Display all products
    int i;
    for (i = 0; i < size; i++) {
        printf("%s - %d\n", products[i].name, products[i].quantity);
    }
}

void updateProduct(struct Product* products, int size, char* productName, int newQuantity) {
    // Prompt user for updated product details
    printf("Enter updated product name: ");
    fgets(productName, sizeof(productName), stdin);
    
    // Check if product is present
    int found = 0;
    int j;
    for (j = 0; j < size; j++) {
        if (strcmp(products[j].name, productName) == 0) {
            products[j].quantity = newQuantity;
            found = 1;
            break;
        }
    }
    
    // Display updated quantity
    if (found) {
        printf("Product quantity updated to %d.\n", products[j].quantity);
    } else {
        printf("Product not found!\n");
    }
}

int main() {
    struct Product products[10];
    int size = sizeof(products)/sizeof(products[0]);
    
    // Add new product
    addProduct(products, size);
    
    // Display all products
    displayProducts(products, size);
    
    // Update product quantity
    char productName[50];
    int newQuantity;
    printf("Enter product name: ");
    fgets(productName, sizeof(productName), stdin);
    printf("Enter new quantity: ");
    scanf("%d", &newQuantity);
    updateProduct(products, size, productName, newQuantity);
    
    // Display updated products
    displayProducts(products, size);
    
    return 0;
}