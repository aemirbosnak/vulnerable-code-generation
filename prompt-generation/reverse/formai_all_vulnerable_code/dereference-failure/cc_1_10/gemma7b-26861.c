//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 10

struct Product {
    char name[20];
    int quantity;
    float price;
};

struct Product products[MAX_PRODUCTS];

void displayProducts() {
    printf("Products:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].quantity > 0) {
            printf("%s (%d) - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
        }
    }
}

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", products[MAX_PRODUCTS - 1].name);

    printf("Enter quantity: ");
    scanf("%d", &products[MAX_PRODUCTS - 1].quantity);

    printf("Enter price: ");
    scanf("%f", &products[MAX_PRODUCTS - 1].price);

    products[MAX_PRODUCTS - 1].quantity++;
}

void updateProduct() {
    printf("Enter product name: ");
    scanf("%s", products[MAX_PRODUCTS - 1].name);

    printf("Enter quantity change: ");
    int quantityChange = atoi(scanf("%d"));

    products[MAX_PRODUCTS - 1].quantity += quantityChange;
}

void removeProduct() {
    printf("Enter product name: ");
    scanf("%s", products[MAX_PRODUCTS - 1].name);

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(products[i].name, products[MAX_PRODUCTS - 1].name) == 0) {
            products[i].quantity = 0;
        }
    }
}

int main() {
    int choice;

    displayProducts();

    printf("Enter 1 to add product, 2 to update product, 3 to remove product: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            updateProduct();
            break;
        case 3:
            removeProduct();
            break;
        default:
            printf("Invalid choice.\n");
    }

    displayProducts();

    return 0;
}