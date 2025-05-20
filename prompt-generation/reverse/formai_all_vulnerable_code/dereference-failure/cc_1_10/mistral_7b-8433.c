//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_LENGTH 50
#define PRODUCT_QUANTITY_LENGTH 10

typedef struct Product {
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
    struct Product* next;
} Product;

Product* inventory = NULL;

void addProduct(char* name, int quantity) {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    strcpy(newProduct->name, name);
    newProduct->quantity = quantity;

    if (inventory == NULL) {
        inventory = newProduct;
    } else {
        Product* current = inventory;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newProduct;
    }
}

void displayInventory() {
    Product* current = inventory;
    printf("\nCurrent Inventory:\n");
    while (current != NULL) {
        printf("%s: %d\n", current->name, current->quantity);
        current = current->next;
    }
}

void updateProductQuantity(char* name, int newQuantity) {
    Product* current = inventory;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->quantity = newQuantity;
            printf("Product %s quantity updated to %d.\n", name, newQuantity);
            return;
        }
        current = current->next;
    }
    printf("Product %s not found in inventory.\n", name);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        char productName[PRODUCT_NAME_LENGTH];
        sprintf(productName, "Product %d", i + 1);
        addProduct(productName, rand() % 50 + 1);
    }

    displayInventory();

    char name[PRODUCT_NAME_LENGTH];
    int choice, quantity;

    while (1) {
        printf("\n1. Add product\n2. Display inventory\n3. Update product quantity\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                addProduct(name, quantity);
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                printf("Enter product name to update quantity: ");
                scanf("%s", name);
                printf("Enter new product quantity: ");
                scanf("%d", &quantity);
                updateProductQuantity(name, quantity);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}