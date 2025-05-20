//FormAI DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int id;
    float price;
    int quantity;
};

void addProduct(struct product **inventory, int *numProducts);
void removeProduct(struct product **inventory, int *numProducts);
void searchProduct(struct product *inventory, int numProducts);
void displayInventory(struct product *inventory, int numProducts);
void updateProduct(struct product *inventory, int numProducts);

int main() {
    struct product *inventory = NULL;
    int numProducts = 0;
    int choice = 0;

    do {
        printf("\n========= Product Inventory System =========\n\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Search Product\n");
        printf("4. Display Inventory\n");
        printf("5. Update Product\n");
        printf("6. Exit\n\n");
        printf("============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&inventory, &numProducts);
                break;
            case 2:
                removeProduct(&inventory, &numProducts);
                break;
            case 3:
                searchProduct(inventory, numProducts);
                break;
            case 4:
                displayInventory(inventory, numProducts);
                break;
            case 5:
                updateProduct(inventory, numProducts);
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 6);

    free(inventory);
    return 0;
}

void addProduct(struct product **inventory, int *numProducts) {
    struct product newProduct;
    printf("\nEnter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    (*inventory) = realloc((*inventory), (*numProducts + 1) * sizeof(struct product));
    if (!(*inventory)) {
        printf("\nError allocating memory!\n");
        exit(1);
    }

    (*inventory)[*numProducts] = newProduct;
    (*numProducts)++;
    printf("\nProduct added successfully.\n");
}

void removeProduct(struct product **inventory, int *numProducts) {
    int targetID = 0;
    printf("\nEnter the ID of the product to be removed: ");
    scanf("%d", &targetID);

    int found = 0;
    for (int i = 0; i < (*numProducts); i++) {
        if ((*inventory)[i].id == targetID) {
            found = 1;
            for (int j = i; j < (*numProducts) - 1; j++) {
                (*inventory)[j] = (*inventory)[j + 1];
            }
            (*numProducts)--;
            (*inventory) = realloc((*inventory), (*numProducts) * sizeof(struct product));
            if (!(*inventory)) {
                printf("\nError allocating memory!\n");
                exit(1);
            }
            printf("\nProduct removed successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found!\n");
    }
}

void searchProduct(struct product *inventory, int numProducts) {
    int targetID = 0;
    printf("\nEnter the ID of the product to be searched: ");
    scanf("%d", &targetID);

    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == targetID) {
            found = 1;
            printf("\n================= Product Details =================\n");
            printf("Name: %s\n", inventory[i].name);
            printf("ID: %d\n", inventory[i].id);
            printf("Price: $%.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("====================================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found!\n");
    }
}

void displayInventory(struct product *inventory, int numProducts) {
    printf("\n================= Inventory =================\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t\t$%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("==============================================\n");
}

void updateProduct(struct product *inventory, int numProducts) {
    int targetID = 0;
    printf("\nEnter the ID of the product to be updated: ");
    scanf("%d", &targetID);

    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == targetID) {
            found = 1;
            printf("\nEnter new product name: ");
            scanf("%s", inventory[i].name);
            printf("Enter new product price: ");
            scanf("%f", &inventory[i].price);
            printf("Enter new product quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("\nProduct updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found!\n");
    }
}