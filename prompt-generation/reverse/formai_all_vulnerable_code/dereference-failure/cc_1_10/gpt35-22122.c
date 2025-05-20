//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
int totalProducts = 0;

// Declare structs for Product and Warehouse
typedef struct {
    int productId;
    char productName[50];
    int quantity;
} Product;

typedef struct {
    int warehouseId;
    char warehouseName[50];
    Product products[100];
} Warehouse;

// Function to add new warehouse
void addWarehouse(Warehouse *warehouses, int *numOfWarehouses) {
    printf("Enter the warehouse name: ");
    scanf("%s", warehouses[*numOfWarehouses].warehouseName);
    warehouses[*numOfWarehouses].warehouseId = *numOfWarehouses+1;
    printf("Warehouse added successfully with ID: %d\n", warehouses[*numOfWarehouses].warehouseId);
    (*numOfWarehouses)++;
}

// Function to add new product
void addProduct(Warehouse *warehouses, int *numOfWarehouses) {
    int warehouseId, productId, quantity;
    printf("Enter the warehouse ID in which you want to add the product: ");
    scanf("%d", &warehouseId);
    if (warehouseId > *numOfWarehouses) {
        printf("Invalid warehouse ID. Please try again.\n");
        return;
    }
    printf("Enter the product name: ");
    scanf("%s", warehouses[warehouseId-1].products[totalProducts].productName);
    printf("Enter the product quantity: ");
    scanf("%d", &quantity);
    warehouses[warehouseId-1].products[totalProducts].productId = totalProducts+1;
    warehouses[warehouseId-1].products[totalProducts].quantity = quantity;
    printf("Product added successfully with ID: %d\n", warehouses[warehouseId-1].products[totalProducts].productId);
    totalProducts++;
}

// Function to display all warehouses and their products
void displayAllProducts(Warehouse *warehouses, int *numOfWarehouses) {
    printf("Warehouses and their products:\n");
    for (int i = 0; i < *numOfWarehouses; i++) {
        printf("Warehouse ID: %d\nWarehouse Name: %s\nProducts:\n", warehouses[i].warehouseId, warehouses[i].warehouseName);
        for (int j = 0; j < totalProducts; j++) {
            if (warehouses[i].products[j].quantity > 0) {
                printf("Product ID: %d\tProduct Name: %s\tProduct Quantity: %d\n", warehouses[i].products[j].productId, warehouses[i].products[j].productName, warehouses[i].products[j].quantity);
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, numOfWarehouses = 0;
    Warehouse warehouses[10];
    do {
        printf("Warehouse Management System\n");
        printf("1. Add new warehouse\n");
        printf("2. Add new product\n");
        printf("3. Display all products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addWarehouse(warehouses, &numOfWarehouses);
                break;
            case 2:
                addProduct(warehouses, &numOfWarehouses);
                break;
            case 3:
                displayAllProducts(warehouses, &numOfWarehouses);
                break;
            case 4:
                printf("Thank you for using Warehouse Management System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while(1);
    return 0;
}