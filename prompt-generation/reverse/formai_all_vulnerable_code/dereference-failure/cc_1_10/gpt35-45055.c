//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for the products */
typedef struct product {
    int id;
    char name[50];
    int quantity;
} Product;

/* Struct for the warehouse */
typedef struct warehouse {
    int size;
    Product *products;
} Warehouse;

/* Function to initialize the warehouse */
void initWarehouse(Warehouse *warehouse, int size) {
    warehouse->size = size;
    warehouse->products = (Product*) malloc(size * sizeof(Product));
}

/* Function to add a product to the warehouse */
void addProduct(Warehouse *warehouse, Product product) {
    /* Check if there is enough space in the warehouse */
    if (warehouse->size == 0) {
        printf("There is no more space in the warehouse!\n");
        return;
    }
    /* Add the product to the warehouse */
    warehouse->products[warehouse->size-1] = product;
    warehouse->size--;
}

/* Function to remove a product from the warehouse */
void removeProduct(Warehouse *warehouse, int productId) {
    /* Search for the product id */
    int index = -1;
    for (int i = 0; i < warehouse->size; i++) {
        if (warehouse->products[i].id == productId) {
            index = i;
            break;
        }
    }
    /* If the product id is found, remove it */
    if (index != -1) {
        /* Move the products after the deleted product */
        for (int i = index; i < warehouse->size - 1; i++) {
            warehouse->products[i] = warehouse->products[i+1];
        }
        warehouse->size++;
        printf("Product %d removed from the warehouse.\n", productId);
    } else {
        printf("Product %d not found in the warehouse.\n", productId);
    }
}

/* Function to print all the products in the warehouse */
void printWarehouse(Warehouse warehouse) {
    if (warehouse.size == 0) {
        printf("The warehouse is empty!\n");
        return;
    }
    printf("Warehouse contents:\n");
    for (int i = 0; i < warehouse.size; i++) {
        printf("Product ID: %d, Name: %s, Quantity: %d\n",
            warehouse.products[i].id,
            warehouse.products[i].name,
            warehouse.products[i].quantity);
    }
}

int main() {
    Warehouse warehouse;
    initWarehouse(&warehouse, 5);

    /* Add some products to the warehouse */
    Product product1 = {1, "Product 1", 10};
    addProduct(&warehouse, product1);
    Product product2 = {2, "Product 2", 20};
    addProduct(&warehouse, product2);
    Product product3 = {3, "Product 3", 30};
    addProduct(&warehouse, product3);

    /* Display the warehouse contents */
    printWarehouse(warehouse);

    /* Remove a product from the warehouse */
    removeProduct(&warehouse, 2);

    /* Display the warehouse contents again */
    printWarehouse(warehouse);

    /* Add a new product to the warehouse */
    Product product4 = {4, "Product 4", 40};
    addProduct(&warehouse, product4);

    /* Display the warehouse contents once more */
    printWarehouse(warehouse);

    /* Deallocate the warehouse memory */
    free(warehouse.products);

    return 0;
}