//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_QUANTITY 10000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    struct Product* next;
} Product;

Product* createProduct(char* name, int quantity) {
    Product* product = (Product*)malloc(sizeof(Product));
    strncpy(product->name, name, MAX_NAME_LEN);
    product->quantity = quantity;
    product->next = NULL;
    return product;
}

void addProduct(Product** head, char* name, int quantity) {
    Product* product = *head;
    if (product == NULL) {
        *head = createProduct(name, quantity);
        return;
    }
    while (product->next!= NULL) {
        product = product->next;
    }
    product->next = createProduct(name, quantity);
}

void printProducts(Product* product) {
    while (product!= NULL) {
        printf("%s: %d\n", product->name, product->quantity);
        product = product->next;
    }
}

int main() {
    Product* productHead = NULL;
    addProduct(&productHead, "Apples", 10);
    addProduct(&productHead, "Oranges", 5);
    addProduct(&productHead, "Bananas", 15);
    addProduct(&productHead, "Grapes", 20);
    printProducts(productHead);
    return 0;
}