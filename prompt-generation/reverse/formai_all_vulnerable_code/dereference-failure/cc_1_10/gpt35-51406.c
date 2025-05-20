//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include <stdio.h>
#include <string.h>

struct Product {
    char name[50];
    int quantity;
};

void displayProducts(struct Product products[], int numProducts) {
    printf("\n\n ----- Products in Warehouse -----\n\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d) %s - Quantity: %d\n", i+1, products[i].name, products[i].quantity);
    }
}

void addProduct(struct Product products[], int numProducts) {
    char name[50];
    int quantity;
    printf("Please enter the product name: ");
    scanf("%s", name);
    printf("Please enter the quantity: ");
    scanf("%d", &quantity);
    strcpy(products[numProducts].name, name);
    products[numProducts].quantity = quantity;
    printf("\nProduct added successfully!");
}

void removeProduct(struct Product products[], int numProducts) {
    int indexToDelete;
    printf("Please enter the index of the product you want to remove: ");
    scanf("%d", &indexToDelete);
    for (int i = indexToDelete-1; i < numProducts-1; i++) {
        strcpy(products[i].name, products[i+1].name);
        products[i].quantity = products[i+1].quantity;
    }
    printf("\nProduct removed successfully!");
}

void updateProduct(struct Product products[], int numProducts) {
    int indexToUpdate;
    int newQuantity;
    printf("Please enter the index of the product you want to update: ");
    scanf("%d", &indexToUpdate);
    printf("Please enter the new quantity: ");
    scanf("%d", &newQuantity);
    products[indexToUpdate-1].quantity = newQuantity;
    printf("\nProduct updated successfully!");
}

int main() {
    struct Product products[50];
    char choice;
    int numProducts = 0;
    while (1) {
        printf("\n\n ------ Warehouse Management System -------\n\n");
        printf("1) Display Products\n");
        printf("2) Add Product\n");
        printf("3) Remove Product\n");
        printf("4) Update Product\n");
        printf("5) Exit\n");
        printf("\nPlease enter your choice: ");
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                displayProducts(products, numProducts);
                break;
            case '2':
                addProduct(products, numProducts);
                numProducts++;
                break;
            case '3':
                removeProduct(products, numProducts);
                numProducts--;
                break;
            case '4':
                updateProduct(products, numProducts);
                break;
            case '5':
                printf("\n\nThank you for using Warehouse Management System!");
                return 0;
            default:
                printf("\n\nInvalid choice. Please try again.");
                break;
        }
    }
    return 0;
}