//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
} Product;

typedef struct {
    int id;
    Product product;
    struct warehouse *next;
} WarehouseShelf;

typedef struct {
    int capacity;
    WarehouseShelf *first;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse, int capacity) {
    warehouse->capacity = capacity;
    warehouse->first = NULL;
}

void addProductToShelf(Warehouse *warehouse, Product product) {
    WarehouseShelf *newShelf = (WarehouseShelf *)malloc(sizeof(WarehouseShelf));
    newShelf->product = product;
    newShelf->id = warehouse->first ? warehouse->first->id + 1 : 1;
    newShelf->next = warehouse->first;
    warehouse->first = newShelf;
}

void printWarehouse(Warehouse *warehouse) {
    WarehouseShelf *current = warehouse->first;
    while (current != NULL) {
        printf("Shelf %d: %s - %d units\n", current->id, current->product.name, current->product.quantity);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    Warehouse warehouse;
    initializeWarehouse(&warehouse, 10);

    Product apple = {"Apple", 50};
    Product banana = {"Banana", 30};
    Product cherry = {"Cherry", 20};

    addProductToShelf(&warehouse, apple);
    addProductToShelf(&warehouse, banana);
    addProductToShelf(&warehouse, cherry);

    printf("Initial state:\n");
    printWarehouse(&warehouse);

    // Ephemeral style: random changes to the warehouse
    for (int i = 0; i < 5; i++) {
        Product randomProduct;
        sprintf(randomProduct.name, "Product %d", rand() % 10 + 1);
        randomProduct.quantity = rand() % 100 + 1;
        addProductToShelf(&warehouse, randomProduct);
    }

    printf("\nAfter ephemeral changes:\n");
    printWarehouse(&warehouse);

    return 0;
}