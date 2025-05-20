//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
typedef enum {
    COFFEE,
    TEA,
    CAKE,
    PIE
} MenuItem;

const char *menuItems[] = {
    "Coffee",
    "Tea",
    "Cake",
    "Pie"
};

const double menuPrices[] = {
    2.00,
    1.50,
    3.00,
    2.50
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the struct for an order item
typedef struct {
    MenuItem item;
    int quantity;
} OrderItem;

// Define the struct for an order
typedef struct {
    OrderItem items[MAX_ITEMS];
    int numItems;
    double total;
} Order;

// Create a new order
Order *newOrder() {
    Order *order = malloc(sizeof(Order));
    order->numItems = 0;
    order->total = 0.0;
    return order;
}

// Add an item to an order
void addItem(Order *order, MenuItem item, int quantity) {
    if (order->numItems < MAX_ITEMS) {
        order->items[order->numItems].item = item;
        order->items[order->numItems].quantity = quantity;
        order->total += menuPrices[item] * quantity;
        order->numItems++;
    } else {
        printf("Error: Maximum number of items reached.\n");
    }
}

// Remove an item from an order
void removeItem(Order *order, int index) {
    if (index >= 0 && index < order->numItems) {
        for (int i = index; i < order->numItems - 1; i++) {
            order->items[i] = order->items[i + 1];
        }
        order->numItems--;
        order->total -= menuPrices[order->items[index].item] * order->items[index].quantity;
    } else {
        printf("Error: Invalid index.\n");
    }
}

// Print an order
void printOrder(Order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("  %-10s x%2d\t$%.2f\n", menuItems[order->items[i].item], order->items[i].quantity, menuPrices[order->items[i].item] * order->items[i].quantity);
    }
    printf("Total: $%.2f\n", order->total);
}

// Free the memory allocated for an order
void freeOrder(Order *order) {
    free(order);
}

// Main function
int main() {
    // Create a new order
    Order *order = newOrder();

    // Add some items to the order
    addItem(order, COFFEE, 2);
    addItem(order, TEA, 1);
    addItem(order, CAKE, 1);

    // Print the order
    printOrder(order);

    // Remove an item from the order
    removeItem(order, 1);

    // Print the order again
    printOrder(order);

    // Free the memory allocated for the order
    freeOrder(order);

    return 0;
}