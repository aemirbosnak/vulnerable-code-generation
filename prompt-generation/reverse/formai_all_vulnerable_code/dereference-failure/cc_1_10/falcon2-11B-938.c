//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a product to the inventory
void addProduct(char* productName, int quantity) {
    char* newProduct = malloc(sizeof(char) * (strlen(productName) + 5));
    sprintf(newProduct, "%s (%d)", productName, quantity);
    printf("%s\n", newProduct);
    free(newProduct);
}

// Function to remove a product from the inventory
void removeProduct(char* productName) {
    char* newProduct = malloc(sizeof(char) * (strlen(productName) + 5));
    sprintf(newProduct, "%s (0)", productName);
    printf("%s\n", newProduct);
    free(newProduct);
}

// Function to display the inventory
void displayInventory() {
    char* product = malloc(sizeof(char) * 100);
    char* quantity = malloc(sizeof(char) * 5);
    char* newProduct = malloc(sizeof(char) * (strlen(product) + strlen(quantity) + 5));
    sprintf(newProduct, "%s (%s)", product, quantity);
    printf("%s\n", newProduct);
    free(product);
    free(quantity);
    free(newProduct);
}

int main() {
    char* product1 = malloc(sizeof(char) * 100);
    char* product2 = malloc(sizeof(char) * 100);
    char* product3 = malloc(sizeof(char) * 100);

    printf("Enter the name of the first product: ");
    scanf("%s", product1);
    addProduct(product1, 10);

    printf("Enter the name of the second product: ");
    scanf("%s", product2);
    addProduct(product2, 20);

    printf("Enter the name of the third product: ");
    scanf("%s", product3);
    addProduct(product3, 30);

    displayInventory();

    printf("Enter the name of the product to remove: ");
    scanf("%s", product1);
    removeProduct(product1);

    displayInventory();

    return 0;
}