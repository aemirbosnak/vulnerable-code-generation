//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 10

typedef struct Product {
    char name[50];
    int id;
    float price;
    char description[100];
    char category[20];
    struct Product *next;
} Product;

void addProduct(Product **catalog, Product *newProduct) {
    Product *current = *catalog;

    if (*catalog == NULL) {
        *catalog = newProduct;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newProduct;
}

Product *createProduct(char *name, int id, float price, char *description, char *category) {
    Product *newProduct = (Product *) malloc(sizeof(Product));

    strcpy(newProduct->name, name);
    newProduct->id = id;
    newProduct->price = price;
    strcpy(newProduct->description, description);
    strcpy(newProduct->category, category);
    newProduct->next = NULL;

    return newProduct;
}

void displayCatalog(Product *catalog) {
    Product *current = catalog;

    printf("---------------------\n");
    printf("| Product Catalog   |\n");
    printf("---------------------\n");

    while (current != NULL) {
        printf("| ID: %d         |\n", current->id);
        printf("| Name: %s        |\n", current->name);
        printf("| Price: %.2f     |\n", current->price);
        printf("| Description: %s|\n", current->description);
        printf("| Category: %s    |\n", current->category);
        printf("---------------------\n");
        current = current->next;
    }
}

int main() {
    Product *catalog = NULL;
    Product *product1 = createProduct("Futuristic Robot", 1, 1250.50, "A highly advanced robot", "Electronics");
    Product *product2 = createProduct("Quantum Computer", 2, 5000.00, "A state-of-the-art computing device", "Computing");
    Product *product3 = createProduct("Anti-Gravity Chair", 3, 2500.75, "A chair that defies gravity", "Furniture");

    addProduct(&catalog, product1);
    addProduct(&catalog, product2);
    addProduct(&catalog, product3);

    displayCatalog(catalog);

    return 0;
}