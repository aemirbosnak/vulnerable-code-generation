//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
    int location;
} Item;

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
    int location;
} Order;

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
    int location;
} Customer;

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
    int location;
} Supplier;

int main() {
    // Randomly generate some data
    srand(time(0));
    int num_items = 100;
    int num_orders = 50;
    int num_customers = 10;
    int num_suppliers = 5;

    // Generate random item IDs
    Item* items = (Item*)malloc(num_items * sizeof(Item));
    for (int i = 0; i < num_items; i++) {
        items[i].id = rand() % 100000;
        items[i].name[0] = 'A' + (rand() % 26);
        items[i].quantity = rand() % 100;
        items[i].price = rand() % 1000;
        items[i].location = rand() % 10;
    }

    // Generate random order IDs
    Order* orders = (Order*)malloc(num_orders * sizeof(Order));
    for (int i = 0; i < num_orders; i++) {
        orders[i].id = rand() % 10000;
        orders[i].name[0] = 'O' + (rand() % 26);
        orders[i].quantity = rand() % 100;
        orders[i].price = rand() % 1000;
        orders[i].location = rand() % 10;
    }

    // Generate random customer IDs
    Customer* customers = (Customer*)malloc(num_customers * sizeof(Customer));
    for (int i = 0; i < num_customers; i++) {
        customers[i].id = rand() % 10000;
        customers[i].name[0] = 'C' + (rand() % 26);
        customers[i].quantity = rand() % 100;
        customers[i].price = rand() % 1000;
        customers[i].location = rand() % 10;
    }

    // Generate random supplier IDs
    Supplier* suppliers = (Supplier*)malloc(num_suppliers * sizeof(Supplier));
    for (int i = 0; i < num_suppliers; i++) {
        suppliers[i].id = rand() % 10000;
        suppliers[i].name[0] = 'S' + (rand() % 26);
        suppliers[i].quantity = rand() % 100;
        suppliers[i].price = rand() % 1000;
        suppliers[i].location = rand() % 10;
    }

    // Print the generated data
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f, Location: %d\n", items[i].id, items[i].name, items[i].quantity, items[i].price, items[i].location);
    }
    printf("\nOrders:\n");
    for (int i = 0; i < num_orders; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f, Location: %d\n", orders[i].id, orders[i].name, orders[i].quantity, orders[i].price, orders[i].location);
    }
    printf("\nCustomers:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f, Location: %d\n", customers[i].id, customers[i].name, customers[i].quantity, customers[i].price, customers[i].location);
    }
    printf("\nSuppliers:\n");
    for (int i = 0; i < num_suppliers; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f, Location: %d\n", suppliers[i].id, suppliers[i].name, suppliers[i].quantity, suppliers[i].price, suppliers[i].location);
    }

    free(items);
    free(orders);
    free(customers);
    free(suppliers);

    return 0;
}