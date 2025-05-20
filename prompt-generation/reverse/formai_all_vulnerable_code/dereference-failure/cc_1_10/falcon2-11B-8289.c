//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
struct Product {
    char name[100];
    int price;
};

// Structure to represent a product inventory
struct Inventory {
    struct Product* products;
    int numProducts;
};

// Function to initialize a product inventory
struct Inventory initializeInventory(int numProducts) {
    struct Inventory inventory;
    inventory.numProducts = numProducts;
    inventory.products = (struct Product*)malloc(sizeof(struct Product) * numProducts);
    for (int i = 0; i < numProducts; i++) {
        inventory.products[i].name[0] = '\0';
        inventory.products[i].price = 0;
    }
    return inventory;
}

// Function to add a product to the inventory
void addProductToInventory(struct Inventory* inventory, char* name, int price) {
    inventory->products[inventory->numProducts].name[0] = '\0';
    strcpy(inventory->products[inventory->numProducts].name, name);
    inventory->products[inventory->numProducts].price = price;
    inventory->numProducts++;
}

// Function to display the product inventory
void displayInventory(struct Inventory inventory) {
    for (int i = 0; i < inventory.numProducts; i++) {
        printf("%s - $%.2f\n", inventory.products[i].name, inventory.products[i].price);
    }
}

// Function to remove a product from the inventory
void removeProductFromInventory(struct Inventory* inventory, char* name) {
    for (int i = 0; i < inventory->numProducts; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            for (int j = i; j < inventory->numProducts - 1; j++) {
                inventory->products[j] = inventory->products[j + 1];
            }
            inventory->numProducts--;
            break;
        }
    }
}

// Function to update the price of a product in the inventory
void updateProductPriceInInventory(struct Inventory* inventory, char* name, int newPrice) {
    for (int i = 0; i < inventory->numProducts; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            inventory->products[i].price = newPrice;
            break;
        }
    }
}

int main() {
    int numProducts;
    printf("Enter the number of products: ");
    scanf("%d", &numProducts);

    struct Inventory inventory = initializeInventory(numProducts);

    for (int i = 0; i < numProducts; i++) {
        char name[100];
        printf("Enter the name of product %d: ", i + 1);
        fgets(name, sizeof(name), stdin);
        char* nameCopy = strdup(name);
        int price;
        printf("Enter the price of product %d: ", i + 1);
        scanf("%d", &price);
        addProductToInventory(&inventory, nameCopy, price);
        free(nameCopy);
    }

    displayInventory(inventory);

    char name[100];
    printf("Enter the name of the product to remove: ");
    fgets(name, sizeof(name), stdin);
    removeProductFromInventory(&inventory, name);
    displayInventory(inventory);

    char name2[100];
    printf("Enter the name of the product to update price: ");
    fgets(name2, sizeof(name2), stdin);
    int newPrice;
    printf("Enter the new price: ");
    scanf("%d", &newPrice);
    updateProductPriceInInventory(&inventory, name2, newPrice);
    displayInventory(inventory);

    return 0;
}