//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Product {
    char name[50];
    int quantity;
    float price;
};

struct Warehouse {
    int capacity;
    struct Product **inventory;
};

void addProduct(struct Warehouse *warehouse, char *name, int quantity, float price) {
    // Check if there is enough capacity to add the product
    if (warehouse->capacity == 0) {
        printf("Warehouse full! Cannot add more products.\n");
        return;
    }
    
    // Allocate memory for the new product
    struct Product *newProduct = (struct Product*) malloc(sizeof(struct Product));
    strcpy(newProduct->name, name);
    newProduct->quantity = quantity;
    newProduct->price = price;
    
    // Allocate memory for the new inventory array
    struct Product **newInventory = (struct Product**) malloc(sizeof(struct Product*) * (warehouse->capacity - 1));
    for (int i = 0; i < warehouse->capacity; i++) {
        newInventory[i] = warehouse->inventory[i];
    }
    newInventory[warehouse->capacity - 1] = newProduct;
    
    // Free old inventory and update the warehouse
    free(warehouse->inventory);
    warehouse->inventory = newInventory;
    warehouse->capacity--;
    
    printf("%d units of %s added to the warehouse at $%.2f each.\n", quantity, name, price);
}

void removeProduct(struct Warehouse *warehouse, char *name, int quantity) {
    int index = -1;
    struct Product *product;
    // Search for the product
    for (int i = 0; i < warehouse->capacity; i++) {
        if (strcmp(warehouse->inventory[i]->name, name) == 0) {
            index = i;
            product = warehouse->inventory[i];
            break;
        }
    }
    // If the product is not found
    if (index == -1) {
        printf("Product not found in the warehouse.\n");
        return;
    }
    // If there is not enough quantity to remove
    if (product->quantity < quantity) {
        printf("Not enough quantity of %s to remove %d units.\n", name, quantity);
        return;
    }
    // Update the inventory and quantity
    product->quantity -= quantity;
    printf("%d units of %s removed from the warehouse.\n", quantity, name);
}

void displayInventory(struct Warehouse *warehouse) {
    printf("Current inventory in the warehouse:\n\n");
    for (int i = 0; i < warehouse->capacity; i++) {
        struct Product *product = warehouse->inventory[i];
        printf("%s - Quantity: %d - Price: $%.2f\n", product->name, product->quantity, product->price);
    }
    printf("\n");
}

int main() {
    // Initialize the warehouse
    struct Warehouse warehouse;
    warehouse.capacity = 5;
    warehouse.inventory = (struct Product**) malloc(sizeof(struct Product*) * warehouse.capacity);
    
    // Add some products to the warehouse
    addProduct(&warehouse, "Laptop", 10, 1000.00);
    addProduct(&warehouse, "Smartphone", 20, 500.00);
    addProduct(&warehouse, "Headphones", 30, 100.00);
    
    // Display the inventory
    displayInventory(&warehouse);
    
    // Remove some products from the warehouse
    removeProduct(&warehouse, "Laptop", 5);
    removeProduct(&warehouse, "TV", 2);
    
    // Display the inventory again
    displayInventory(&warehouse);
    
    return 0;
}