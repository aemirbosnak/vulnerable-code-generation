//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 100

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Product;

typedef struct {
    Product *products;
    int size;
    int capacity;
} Inventory;

void initializeInventory(Inventory *inventory) {
    inventory->size = 0;
    inventory->capacity = 2;
    inventory->products = (Product *)malloc(inventory->capacity * sizeof(Product));
}

void expandInventory(Inventory *inventory) {
    inventory->capacity *= 2;
    inventory->products = (Product *)realloc(inventory->products, inventory->capacity * sizeof(Product));
}

void addProduct(Inventory *inventory) {
    if (inventory->size >= inventory->capacity) {
        expandInventory(inventory);
    }
    Product newProduct;
    newProduct.id = inventory->size + 1; // Simple ID generation
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    inventory->products[inventory->size++] = newProduct;
    printf("Product added successfully.\n");
}

void updateProduct(Inventory *inventory) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > inventory->size) {
        printf("Product ID not found.\n");
        return;
    }

    Product *product = &inventory->products[id - 1];
    printf("Updating product: %s\n", product->name);
    printf("Enter new name (current: %s): ", product->name);
    scanf("%s", product->name);
    printf("Enter new quantity (current: %d): ", product->quantity);
    scanf("%d", &product->quantity);
    printf("Enter new price (current: %.2f): ", product->price);
    scanf("%f", &product->price);
    printf("Product updated successfully.\n");
}

void removeProduct(Inventory *inventory) {
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > inventory->size) {
        printf("Product ID not found.\n");
        return;
    }

    for (int i = id - 1; i < inventory->size - 1; i++) {
        inventory->products[i] = inventory->products[i + 1];
    }
    inventory->size--;
    printf("Product removed successfully.\n");
}

void displayInventory(const Inventory *inventory) {
    if (inventory->size == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("\nProduct List:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < inventory->size; i++) {
        Product *product = &inventory->products[i];
        printf("%d\t%s\t\t%d\t\t%.2f\n", product->id, product->name, product->quantity, product->price);
    }
}

void freeInventory(Inventory *inventory) {
    free(inventory->products);
}

int main() {
    Inventory inventory;
    initializeInventory(&inventory);
    int choice;

    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Remove Product\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(&inventory); break;
            case 2: updateProduct(&inventory); break;
            case 3: removeProduct(&inventory); break;
            case 4: displayInventory(&inventory); break;
            case 5:
                freeInventory(&inventory);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}