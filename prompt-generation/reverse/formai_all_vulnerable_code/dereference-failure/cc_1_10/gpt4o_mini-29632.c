//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char name[50];
    int quantity;
    float price;
    struct Product *next;
} Product;

Product *head = NULL;

void addProduct(char *name, int quantity, float price) {
    Product *newProduct = (Product *)malloc(sizeof(Product));
    strcpy(newProduct->name, name);
    newProduct->quantity = quantity;
    newProduct->price = price;
    newProduct->next = head;
    head = newProduct;
    printf("Oh fair product, thou hast been added to my store!\n");
}

void displayProducts() {
    if (!head) {
        printf("Alas! No products in this wretched bazaar!\n");
        return;
    }
    printf("\nList of Products in the Inventory:\n");
    Product *current = head;
    while (current) {
        printf("Product: %s | Quantity: %d | Price: %.2f\n",
               current->name, current->quantity, current->price);
        current = current->next;
    }
}

void searchProduct(char *name) {
    Product *current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            printf("Lo! Thou hath found it! Product: %s | Quantity: %d | Price: %.2f\n",
                   current->name, current->quantity, current->price);
            return;
        }
        current = current->next;
    }
    printf("Ah, the fated product is not among us, dear friend.\n");
}

void updateQuantity(char *name, int quantity) {
    Product *current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            current->quantity += quantity;
            printf("Hark! The quantity of %s hath been updated to %d.\n",
                   current->name, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("Alas! The product is not found. Verily a tragic fate!\n");
}

void deleteProduct(char *name) {
    Product *current = head;
    Product *previous = NULL;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            printf("The product of yore hath been banished from our realm!\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Oh woe! The product art not found to be removed!\n");
}

void freeInventory() {
    Product *current = head;
    while (current) {
        Product *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    printf("The inventory hath been cleansed, like a gentle wind upon the evening tide.\n");
}

int main() {
    int choice;
    char name[50];
    int quantity;
    float price;

    printf("Welcome to our noble Product Inventory System! Verily, let us begin...\n");

    do {
        printf("\nChoose thine action:\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product Quantity\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume the newline character after number input

        switch (choice) {
            case 1:
                printf("Name of the product: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // remove newline
                printf("Quantity of the product: ");
                scanf("%d", &quantity);
                printf("Price of the product: ");
                scanf("%f", &price);
                addProduct(name, quantity, price);
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                printf("Name of the product to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // remove newline
                searchProduct(name);
                break;
            case 4:
                printf("Name of the product to update: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // remove newline
                printf("Quantity to add: ");
                scanf("%d", &quantity);
                updateQuantity(name, quantity);
                break;
            case 5:
                printf("Name of the product to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // remove newline
                deleteProduct(name);
                break;
            case 6:
                freeInventory();
                printf("Thou hast chosen to exit. Farewell, brave merchant!\n");
                break;
            default:
                printf("Thou hast chosen an invalid option! Try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}