//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: medieval
/* 
 * A medieval-style C Warehouse Management System
 * By Lord Smith, the Keeper of the Realm's Stores
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a product in the warehouse
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Define the structure for a warehouse
typedef struct {
    char name[50];
    int capacity;
    int total_capacity;
    Product* products;
} Warehouse;

// Function to add a new product to the warehouse
void addProduct(Warehouse* warehouse, const char* product_name, int quantity, float price) {
    warehouse->products = (Product*)realloc(warehouse->products, sizeof(Product) * (warehouse->total_capacity + 1));
    if (warehouse->total_capacity == warehouse->capacity) {
        printf("The warehouse is full! Cannot add more products.\n");
        return;
    }
    strcpy(warehouse->products[warehouse->total_capacity].name, product_name);
    warehouse->products[warehouse->total_capacity].quantity = quantity;
    warehouse->products[warehouse->total_capacity].price = price;
    warehouse->total_capacity++;
}

// Function to remove a product from the warehouse
void removeProduct(Warehouse* warehouse, const char* product_name) {
    int i;
    for (i = 0; i < warehouse->total_capacity; i++) {
        if (strcmp(warehouse->products[i].name, product_name) == 0) {
            strcpy(warehouse->products[i].name, "");
            warehouse->products[i].quantity = 0;
            warehouse->products[i].price = 0;
            break;
        }
    }
}

// Function to display all products in the warehouse
void displayProducts(Warehouse* warehouse) {
    int i;
    printf("Products in the %s warehouse:\n", warehouse->name);
    for (i = 0; i < warehouse->total_capacity; i++) {
        printf("Product: %s\n", warehouse->products[i].name);
        printf("Quantity: %d\n", warehouse->products[i].quantity);
        printf("Price: %f\n", warehouse->products[i].price);
        printf("\n");
    }
}

// Function to update the quantity of a product in the warehouse
void updateProductQuantity(Warehouse* warehouse, const char* product_name, int quantity) {
    int i;
    for (i = 0; i < warehouse->total_capacity; i++) {
        if (strcmp(warehouse->products[i].name, product_name) == 0) {
            warehouse->products[i].quantity = quantity;
            break;
        }
    }
}

// Function to update the price of a product in the warehouse
void updateProductPrice(Warehouse* warehouse, const char* product_name, float price) {
    int i;
    for (i = 0; i < warehouse->total_capacity; i++) {
        if (strcmp(warehouse->products[i].name, product_name) == 0) {
            warehouse->products[i].price = price;
            break;
        }
    }
}

// Function to calculate the total value of all products in the warehouse
float calculateTotalValue(Warehouse* warehouse) {
    float total_value = 0.0;
    int i;
    for (i = 0; i < warehouse->total_capacity; i++) {
        total_value += warehouse->products[i].quantity * warehouse->products[i].price;
    }
    return total_value;
}

// Function to calculate the total quantity of all products in the warehouse
int calculateTotalQuantity(Warehouse* warehouse) {
    int total_quantity = 0;
    int i;
    for (i = 0; i < warehouse->total_capacity; i++) {
        total_quantity += warehouse->products[i].quantity;
    }
    return total_quantity;
}

// Function to calculate the average price of all products in the warehouse
float calculateAveragePrice(Warehouse* warehouse) {
    float total_price = 0.0;
    int i;
    for (i = 0; i < warehouse->total_capacity; i++) {
        total_price += warehouse->products[i].price;
    }
    return total_price / calculateTotalQuantity(warehouse);
}

int main() {
    // Create a warehouse named "The Royal Storehouse" with a capacity of 100 and a total capacity of 50
    Warehouse royal_storehouse = {"The Royal Storehouse", 100, 50, NULL};

    // Add some products to the warehouse
    addProduct(&royal_storehouse, "Shield", 10, 50.0);
    addProduct(&royal_storehouse, "Sword", 5, 30.0);
    addProduct(&royal_storehouse, "Armor", 20, 100.0);

    // Display all products in the warehouse
    displayProducts(&royal_storehouse);

    // Remove a product from the warehouse
    removeProduct(&royal_storehouse, "Sword");

    // Display all products in the warehouse again
    displayProducts(&royal_storehouse);

    // Update the quantity of a product in the warehouse
    updateProductQuantity(&royal_storehouse, "Armor", 15);

    // Display all products in the warehouse again
    displayProducts(&royal_storehouse);

    // Update the price of a product in the warehouse
    updateProductPrice(&royal_storehouse, "Shield", 60.0);

    // Display all products in the warehouse again
    displayProducts(&royal_storehouse);

    // Calculate the total value of all products in the warehouse
    float total_value = calculateTotalValue(&royal_storehouse);
    printf("Total value of all products: %f\n", total_value);

    // Calculate the total quantity of all products in the warehouse
    int total_quantity = calculateTotalQuantity(&royal_storehouse);
    printf("Total quantity of all products: %d\n", total_quantity);

    // Calculate the average price of all products in the warehouse
    float average_price = calculateAveragePrice(&royal_storehouse);
    printf("Average price of all products: %f\n", average_price);

    return 0;
}