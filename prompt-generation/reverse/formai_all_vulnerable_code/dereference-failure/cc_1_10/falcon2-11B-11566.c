//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    float price;
    int quantity;
} Item;

typedef struct {
    char* customer_name;
    int order_total;
    int order_date;
    int shipping_address;
} Order;

typedef struct {
    char* shipment_id;
    char* shipper;
    char* receiver;
    int weight;
    int delivery_date;
} Shipment;

int main() {
    // Initialize inventory
    Item items[5] = {
        {"Apple", 0.99, 100},
        {"Banana", 0.99, 200},
        {"Orange", 0.99, 150},
        {"Grapes", 1.99, 50},
        {"Mango", 2.99, 30}
    };

    // Initialize orders
    Order orders[10] = {
        {"John Doe", 50.00, 100, 1},
        {"Jane Smith", 75.00, 200, 2},
        {"Bob Johnson", 40.00, 300, 3},
        {"Alice Williams", 80.00, 150, 4},
        {"Charlie Brown", 60.00, 100, 5},
        {"David Williams", 35.00, 200, 6},
        {"Sarah Johnson", 45.00, 300, 7},
        {"Emily Brown", 65.00, 150, 8},
        {"Michael Williams", 50.00, 200, 9},
        {"Nicole Johnson", 25.00, 300, 10}
    };

    // Initialize shipments
    Shipment shipments[5] = {
        {"123456", "FedEx", "John Doe", 10, 100},
        {"789012", "UPS", "Jane Smith", 20, 150},
        {"345678", "USPS", "Bob Johnson", 30, 200},
        {"987654", "DHL", "Alice Williams", 40, 150},
        {"111111", "TNT", "Charlie Brown", 50, 200}
    };

    // Add new items to the inventory
    for (int i = 0; i < 5; i++) {
        strcpy(items[i].name, "New Item ");
        strcat(items[i].name, i + 1);
        items[i].price = 1.99;
        items[i].quantity = 100;
    }

    // Place orders
    for (int i = 0; i < 10; i++) {
        orders[i].order_date = i + 1;
    }

    // Generate shipping labels
    for (int i = 0; i < 5; i++) {
        printf("Shipment %s: ", shipments[i].shipment_id);
        printf("Shipper: %s\n", shipments[i].shipper);
        printf("Receiver: %s\n", shipments[i].receiver);
        printf("Weight: %d\n", shipments[i].weight);
        printf("Delivery Date: %d\n", shipments[i].delivery_date);
    }

    return 0;
}