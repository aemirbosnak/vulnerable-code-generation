//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    double price;
    int quantity;
} Item;

typedef struct {
    int id;
    char name[50];
    int quantity;
} OrderItem;

typedef struct {
    int id;
    char name[50];
    double total;
} Order;

// Function to create a new item
Item *create_item(int id, char *name, double price, int quantity) {
    Item *item = (Item *)malloc(sizeof(Item));
    item->id = id;
    strcpy(item->name, name);
    item->price = price;
    item->quantity = quantity;
    return item;
}

// Function to create a new order item
OrderItem *create_order_item(int id, char *name, int quantity) {
    OrderItem *order_item = (OrderItem *)malloc(sizeof(OrderItem));
    order_item->id = id;
    strcpy(order_item->name, name);
    order_item->quantity = quantity;
    return order_item;
}

// Function to create a new order
Order *create_order(int id, char *name, double total) {
    Order *order = (Order *)malloc(sizeof(Order));
    order->id = id;
    strcpy(order->name, name);
    order->total = total;
    return order;
}

// Function to add an item to an order
void add_item_to_order(Order *order, Item *item) {
    order->total += item->price * item->quantity;
}

// Function to print an item
void print_item(Item *item) {
    printf("ID: %d\n", item->id);
    printf("Name: %s\n", item->name);
    printf("Price: %lf\n", item->price);
    printf("Quantity: %d\n", item->quantity);
}

// Function to print an order item
void print_order_item(OrderItem *order_item) {
    printf("ID: %d\n", order_item->id);
    printf("Name: %s\n", order_item->name);
    printf("Quantity: %d\n", order_item->quantity);
}

// Function to print an order
void print_order(Order *order) {
    printf("ID: %d\n", order->id);
    printf("Name: %s\n", order->name);
    printf("Total: %lf\n", order->total);
}

// Main function
int main() {
    // Create some items
    Item *item1 = create_item(1, "Coffee", 2.50, 1);
    Item *item2 = create_item(2, "Tea", 1.50, 2);
    Item *item3 = create_item(3, "Cake", 3.00, 1);

    // Create an order
    Order *order = create_order(1, "John Doe", 0.0);

    // Add items to the order
    add_item_to_order(order, item1);
    add_item_to_order(order, item2);
    add_item_to_order(order, item3);

    // Print the order
    print_order(order);

    return 0;
}