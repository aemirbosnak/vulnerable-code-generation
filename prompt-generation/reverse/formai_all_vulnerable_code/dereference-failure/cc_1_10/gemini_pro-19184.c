//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    float price;
} Product;

typedef struct {
    char *name;
    int quantity;
} Order;

typedef struct {
    char *name;
    int quantity;
    float price;
} Shipment;

Product* createProduct(char *name, int quantity, float price) {
    Product *product = malloc(sizeof(Product));
    product->name = strdup(name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

Order* createOrder(char *name, int quantity) {
    Order *order = malloc(sizeof(Order));
    order->name = strdup(name);
    order->quantity = quantity;
    return order;
}

Shipment* createShipment(char *name, int quantity, float price) {
    Shipment *shipment = malloc(sizeof(Shipment));
    shipment->name = strdup(name);
    shipment->quantity = quantity;
    shipment->price = price;
    return shipment;
}

void printProduct(Product *product) {
    printf("Product: %s, Quantity: %d, Price: %f\n", product->name, product->quantity, product->price);
}

void printOrder(Order *order) {
    printf("Order: %s, Quantity: %d\n", order->name, order->quantity);
}

void printShipment(Shipment *shipment) {
    printf("Shipment: %s, Quantity: %d, Price: %f\n", shipment->name, shipment->quantity, shipment->price);
}

int main() {
    // Create some products
    Product *product1 = createProduct("Product 1", 10, 10.0);
    Product *product2 = createProduct("Product 2", 20, 20.0);
    Product *product3 = createProduct("Product 3", 30, 30.0);

    // Create some orders
    Order *order1 = createOrder("Order 1", 10);
    Order *order2 = createOrder("Order 2", 20);
    Order *order3 = createOrder("Order 3", 30);

    // Create some shipments
    Shipment *shipment1 = createShipment("Shipment 1", 10, 10.0);
    Shipment *shipment2 = createShipment("Shipment 2", 20, 20.0);
    Shipment *shipment3 = createShipment("Shipment 3", 30, 30.0);

    // Print the products
    printf("Products:\n");
    printProduct(product1);
    printProduct(product2);
    printProduct(product3);

    // Print the orders
    printf("Orders:\n");
    printOrder(order1);
    printOrder(order2);
    printOrder(order3);

    // Print the shipments
    printf("Shipments:\n");
    printShipment(shipment1);
    printShipment(shipment2);
    printShipment(shipment3);

    return 0;
}