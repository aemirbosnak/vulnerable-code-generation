//FormAI DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char *name;
    int sku;
    int quantity;
    float price;
};

void addProduct(struct Product *inventory, int *numProducts);
void editProduct(struct Product *inventory, int numProducts);
void deleteProduct(struct Product *inventory, int *numProducts);
void printProducts(struct Product *inventory, int numProducts);

int main() {
    struct Product inventory[100];
    int numProducts = 0;
    int choice;

    printf("Welcome to the Product Inventory System\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add product to inventory\n");
        printf("2. Edit a product in inventory\n");
        printf("3. Delete a product from inventory\n");
        printf("4. View all products in inventory\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                editProduct(inventory, numProducts);
                break;
            case 3:
                deleteProduct(inventory, &numProducts);
                break;
            case 4:
                printProducts(inventory, numProducts);
                break;
            case 5:
                printf("Thanks for using the Product Inventory System!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

void addProduct(struct Product *inventory, int *numProducts) {
    char name[100];

    printf("Enter product name: ");
    scanf("%s", name);

    inventory[*numProducts].name = malloc(strlen(name) + 1);
    strcpy(inventory[*numProducts].name, name);

    printf("Enter SKU: ");
    scanf("%d", &inventory[*numProducts].sku);

    printf("Enter quantity: ");
    scanf("%d", &inventory[*numProducts].quantity);

    printf("Enter price: ");
    scanf("%f", &inventory[*numProducts].price);

    (*numProducts)++;

    printf("\nProduct added to inventory!\n");
}

void editProduct(struct Product *inventory, int numProducts) {
    int sku;
    int i;
    int found = 0;

    printf("Enter SKU of product to edit: ");
    scanf("%d", &sku);

    for (i = 0; i < numProducts; i++) {
        if (inventory[i].sku == sku) {
            found = 1;
            break;
        }
    }

    if (found) {
        char name[100];

        printf("Enter new product name (leave blank to keep \"%s\"): ", inventory[i].name);
        scanf("%s", name);

        if (strcmp(name, "") != 0) {
            inventory[i].name = realloc(inventory[i].name, strlen(name) + 1);
            strcpy(inventory[i].name, name);
        }

        printf("Enter new quantity (leave blank to keep %d): ", inventory[i].quantity);
        char quantity[10];
        scanf("%s", quantity);
        if (strcmp(quantity, "") != 0) {
          inventory[i].quantity = atoi(quantity);
        }

        printf("Enter new price (leave blank to keep %.2f): ", inventory[i].price);
        char price[10];
        scanf("%s", price);
        if (strcmp(price, "") != 0) {
          inventory[i].price = atof(price);
        }

        printf("\nProduct updated!\n");
    } else {
        printf("\nProduct not found!\n");
    }
}

void deleteProduct(struct Product *inventory, int *numProducts) {
    int sku;
    int i;
    int found = 0;

    printf("Enter SKU of product to delete: ");
    scanf("%d", &sku);

    for (i = 0; i < *numProducts; i++) {
        if (inventory[i].sku == sku) {
            found = 1;
            break;
        }
    }

    if (found) {
        free(inventory[i].name);

        for (; i < *numProducts - 1; i++) {
            inventory[i] = inventory[i + 1];
        }

        (*numProducts)--;

        printf("\nProduct deleted!\n");
    } else {
        printf("\nProduct not found!\n");
    }
}

void printProducts(struct Product *inventory, int numProducts) {
    if (numProducts == 0) {
        printf("\nInventory is empty!\n");
    }

    int i;

    for (i = 0; i < numProducts; i++) {
        printf("\nProduct #%d:\n", i + 1);
        printf("Name: %s\n", inventory[i].name);
        printf("SKU: %d\n", inventory[i].sku);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: $%.2f\n", inventory[i].price);
    }
}