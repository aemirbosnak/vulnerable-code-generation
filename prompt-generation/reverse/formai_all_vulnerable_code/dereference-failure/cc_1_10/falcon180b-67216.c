//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 1000
#define MAX_PRODUCT_NAME_SIZE 50
#define MAX_PRODUCT_QUANTITY 1000

typedef struct {
    char name[MAX_PRODUCT_NAME_SIZE];
    int quantity;
} Product;

typedef struct {
    Product products[MAX_WAREHOUSE_SIZE];
    int size;
} Warehouse;

Warehouse* createWarehouse() {
    Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
    warehouse->size = 0;
    return warehouse;
}

void addProduct(Warehouse* warehouse, char* name, int quantity) {
    Product product = {.name = name,.quantity = quantity};
    if (warehouse->size >= MAX_WAREHOUSE_SIZE) {
        printf("Warehouse is full\n");
        return;
    }
    strcpy(warehouse->products[warehouse->size].name, name);
    warehouse->products[warehouse->size].quantity = quantity;
    warehouse->size++;
}

void removeProduct(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->size; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            warehouse->size--;
            for (int j = i; j < warehouse->size; j++) {
                strcpy(warehouse->products[j].name, warehouse->products[j+1].name);
                warehouse->products[j].quantity = warehouse->products[j+1].quantity;
            }
            break;
        }
    }
}

void printWarehouse(Warehouse* warehouse) {
    printf("Warehouse:\n");
    for (int i = 0; i < warehouse->size; i++) {
        printf("%s - %d\n", warehouse->products[i].name, warehouse->products[i].quantity);
    }
}

int main() {
    Warehouse* warehouse = createWarehouse();
    addProduct(warehouse, "Apples", 100);
    addProduct(warehouse, "Oranges", 200);
    addProduct(warehouse, "Bananas", 300);
    printWarehouse(warehouse);
    removeProduct(warehouse, "Oranges");
    printWarehouse(warehouse);
    return 0;
}