//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

void displayProducts(Product *products, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s - %d - %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void addProduct(Product *products, int *size) {
    *size++;
    products = (Product *)realloc(products, *size * sizeof(Product));
    products[*size - 1].name[0] = '\0';
    products[*size - 1].quantity = 0;
    products[*size - 1].price = 0.0f;
}

void modifyProduct(Product *products, int size) {
    char name[50];
    printf("Enter the name of the product to modify:");
    scanf("%s", name);

    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Enter the new quantity:");
            scanf("%d", &products[i].quantity);

            printf("Enter the new price:");
            scanf("%f", &products[i].price);
        }
    }
}

void searchProducts(Product *products, int size) {
    char name[50];
    printf("Enter the name of the product to search:");
    scanf("%s", name);

    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("%s - %d - %.2f\n", products[i].name, products[i].quantity, products[i].price);
        }
    }
}

int main() {
    Product *products = NULL;
    int size = 0;

    while (1) {
        int choice;

        printf("1. Display Products\n");
        printf("2. Add Product\n");
        printf("3. Modify Product\n");
        printf("4. Search Products\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayProducts(products, size);
                break;
            case 2:
                addProduct(products, &size);
                break;
            case 3:
                modifyProduct(products, size);
                break;
            case 4:
                searchProducts(products, size);
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to continue? (Y/N)");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N') {
            break;
        }
    }

    return 0;
}