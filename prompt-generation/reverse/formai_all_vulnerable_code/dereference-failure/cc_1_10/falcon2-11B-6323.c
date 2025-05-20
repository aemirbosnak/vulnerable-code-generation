//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char address[100];
    int age;
    int phone;
} Customer;

typedef struct {
    char name[50];
    int quantity;
    double price;
    int category;
} Product;

typedef struct {
    char name[50];
    double price;
} Supplier;

int main() {
    Customer* customers = NULL;
    Product* products = NULL;
    Supplier* suppliers = NULL;

    // Initialize customers
    customers = (Customer*)malloc(sizeof(Customer));
    strcpy(customers->name, "John Doe");
    strcpy(customers->address, "123 Main St");
    customers->age = 30;
    customers->phone = 555-1234;

    // Initialize products
    products = (Product*)malloc(sizeof(Product));
    strcpy(products->name, "Aspirin");
    products->quantity = 10;
    products->price = 5.99;
    products->category = 1;

    // Initialize suppliers
    suppliers = (Supplier*)malloc(sizeof(Supplier));
    strcpy(suppliers->name, "ABC Pharmaceuticals");
    suppliers->price = 3.99;

    // Display customer information
    printf("Customer: %s, %s, %d, %d\n", customers->name, customers->address, customers->age, customers->phone);

    // Display product information
    printf("Product: %s, %d, %.2f, %d\n", products->name, products->quantity, products->price, products->category);

    // Display supplier information
    printf("Supplier: %s, %.2f\n", suppliers->name, suppliers->price);

    return 0;
}