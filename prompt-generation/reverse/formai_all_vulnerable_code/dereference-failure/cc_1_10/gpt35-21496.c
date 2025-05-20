//FormAI DATASET v1.0 Category: Product Inventory System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product_t {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct inventory_t {
    Product *products[MAX_PRODUCTS];
    int size;
} Inventory;

Product* createProduct(int id, char* name, int quantity, float price) {
    Product *p = (Product*) malloc(sizeof(Product));
    p->id = id;
    strcpy(p->name, name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

Inventory* createInventory() {
    Inventory *inv = (Inventory*) malloc(sizeof(Inventory));
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        inv->products[i] = NULL;
    }
    inv->size = 0;
    return inv;
}

void addProduct(Inventory *inv, Product *p) {
    inv->products[inv->size] = p;
    inv->size++;
}

void removeProduct(Inventory *inv, int id) {
    for (int i = 0; i < inv->size; i++) {
        if (inv->products[i]->id == id) {
            free(inv->products[i]);
            inv->products[i] = NULL;
            inv->size--;
            return;
        }
    }
}

int searchProduct(Inventory *inv, int id) {
    for (int i = 0; i < inv->size; i++) {
        if (inv->products[i]->id == id) {
            return i;
        }
    }
    return -1;
}

void updateProduct(Inventory *inv, int id, char* name, int quantity, float price) {
    int index = searchProduct(inv, id);
    if (index == -1) {
        printf("Product not found\n");
    } else {
        strcpy(inv->products[index]->name, name);
        inv->products[index]->quantity = quantity;
        inv->products[index]->price = price;
    }
}

void printProduct(Product *p) {
    printf("%d    %s      %d      %.2f\n", p->id, p->name, p->quantity, p->price);
}

void printInventory(Inventory *inv) {
    printf("Inventory:\n");
    printf("ID   NAME    QUANTITY    PRICE\n");
    for (int i = 0; i < inv->size; i++) {
        if (inv->products[i] != NULL) {
            printProduct(inv->products[i]);
        }
    }
}

int main() {
    Inventory *inv = createInventory();
    Product *p1 = createProduct(1, "Product 1", 10, 9.99);
    Product *p2 = createProduct(2, "Product 2", 5, 19.99);
    Product *p3 = createProduct(3, "Product 3", 3, 29.99);
    addProduct(inv, p1);
    addProduct(inv, p2);
    addProduct(inv, p3);
    printInventory(inv);

    updateProduct(inv, 2, "Product 2 Updated", 10, 24.99);
    removeProduct(inv, 1);
    printInventory(inv);

    return 0;
}