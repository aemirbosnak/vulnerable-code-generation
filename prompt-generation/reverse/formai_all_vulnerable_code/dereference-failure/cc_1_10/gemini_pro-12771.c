//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item Structure
typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

// Order Structure
typedef struct Order {
    char customerName[50];
    Item items[100];
    int numItems;
    float total;
} Order;

// Function to create a new order
Order* createOrder(char* customerName) {
    Order* order = (Order*)malloc(sizeof(Order));
    strcpy(order->customerName, customerName);
    order->numItems = 0;
    order->total = 0.0;
    return order;
}

// Function to add an item to an order
void addItem(Order* order, char* itemName, float price, int quantity) {
    strcpy(order->items[order->numItems].name, itemName);
    order->items[order->numItems].price = price;
    order->items[order->numItems].quantity = quantity;
    order->numItems++;
    order->total += price * quantity;
}

// Function to print the order
void printOrder(Order* order) {
    printf("Customer Name: %s\n", order->customerName);
    printf("Items:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("\t%s\t%.2f\t%d\n", order->items[i].name, order->items[i].price, order->items[i].quantity);
    }
    printf("Total: %.2f\n", order->total);
}

// Main Function
int main() {
    // Create a new order for the customer "John Doe"
    Order* order = createOrder("John Doe");

    // Add items to the order
    addItem(order, "Coffee", 2.50, 2);
    addItem(order, "Tea", 1.50, 1);
    addItem(order, "Cake", 3.00, 1);

    // Print the order
    printOrder(order);

    return 0;
}