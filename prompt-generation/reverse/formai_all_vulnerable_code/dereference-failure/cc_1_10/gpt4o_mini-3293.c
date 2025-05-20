//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

typedef struct {
    Product *products;
    int count;
} Inventory;

Inventory* create_inventory() {
    Inventory *inv = (Inventory *)malloc(sizeof(Inventory));
    if (inv == NULL) {
        fprintf(stderr, "Error allocating memory for inventory.\n");
        exit(EXIT_FAILURE);
    }
    inv->products = NULL;
    inv->count = 0;
    return inv;
}

void add_product(Inventory *inv, const char *name, int quantity, float price) {
    inv->count++;
    inv->products = realloc(inv->products, inv->count * sizeof(Product));
    if (inv->products == NULL) {
        fprintf(stderr, "Error reallocating memory for products.\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(inv->products[inv->count - 1].name, name);
    inv->products[inv->count - 1].quantity = quantity;
    inv->products[inv->count - 1].price = price;
}

void view_inventory(Inventory *inv) {
    if (inv->count == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Inventory List:\n");
    for (int i = 0; i < inv->count; i++) {
        printf("Product %d: %s | Quantity: %d | Price: %.2f\n", 
               i + 1, 
               inv->products[i].name, 
               inv->products[i].quantity, 
               inv->products[i].price);
    }
}

void delete_product(Inventory *inv, int index) {
    if (index < 0 || index >= inv->count) {
        printf("Invalid index. Unable to delete product.\n");
        return;
    }

    for (int i = index; i < inv->count - 1; i++) {
        inv->products[i] = inv->products[i + 1];
    }
    inv->count--;
    inv->products = realloc(inv->products, inv->count * sizeof(Product));
    if (inv->products == NULL && inv->count > 0) {
        fprintf(stderr, "Error reallocating memory for products after deletion.\n");
        exit(EXIT_FAILURE);
    }
}

void free_inventory(Inventory *inv) {
    free(inv->products);
    free(inv);
}

int main() {
    Inventory *inventory = create_inventory();
    int choice, quantity, index;
    float price;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Delete Product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                add_product(inventory, name, quantity, price);
                break;
            case 2:
                view_inventory(inventory);
                break;
            case 3:
                printf("Enter the index of product to delete (0 to %d): ", inventory->count - 1);
                scanf("%d", &index);
                delete_product(inventory, index);
                break;
            case 4:
                free_inventory(inventory);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}