//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in an order
#define MAX_ITEMS 10

// Define the menu items and their prices
char *menu_items[] = { "Coffee", "Tea", "Soda", "Muffin", "Donut" };
float menu_prices[] = { 2.50, 1.50, 1.75, 2.00, 1.25 };

// Define the tax rate
#define TAX_RATE 0.08

// Define the order structure
typedef struct {
    char *item;
    int quantity;
    float price;
} order_item;

// Define the order structure
typedef struct {
    order_item items[MAX_ITEMS];
    int num_items;
    float subtotal;
    float tax;
    float total;
} order;

// Create a new order
order *create_order() {
    order *order = malloc(sizeof(order));
    order->num_items = 0;
    order->subtotal = 0.0;
    order->tax = 0.0;
    order->total = 0.0;
    return order;
}

// Add an item to an order
void add_item_to_order(order *order, char *item, int quantity) {
    // Find the item in the menu
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(item, menu_items[i]) == 0) {
            break;
        }
    }

    // If the item was not found, return
    if (i == 5) {
        return;
    }

    // Add the item to the order
    order->items[order->num_items].item = item;
    order->items[order->num_items].quantity = quantity;
    order->items[order->num_items].price = menu_prices[i] * quantity;
    order->num_items++;

    // Update the order's subtotal
    order->subtotal += order->items[order->num_items - 1].price;
}

// Calculate the order's tax
void calculate_tax(order *order) {
    order->tax = order->subtotal * TAX_RATE;
}

// Calculate the order's total
void calculate_total(order *order) {
    order->total = order->subtotal + order->tax;
}

// Print the order
void print_order(order *order) {
    int i;

    printf("Order Summary\n");
    printf("---------------------\n");
    for (i = 0; i < order->num_items; i++) {
        printf("%s: %d x %0.2f = %0.2f\n",
            order->items[i].item,
            order->items[i].quantity,
            menu_prices[i],
            order->items[i].price);
    }
    printf("Subtotal: %0.2f\n", order->subtotal);
    printf("Tax: %0.2f\n", order->tax);
    printf("Total: %0.2f\n", order->total);
}

// Main function
int main() {
    // Create an order
    order *order = create_order();

    // Add items to the order
    add_item_to_order(order, "Coffee", 2);
    add_item_to_order(order, "Muffin", 1);
    add_item_to_order(order, "Soda", 3);

    // Calculate the order's tax and total
    calculate_tax(order);
    calculate_total(order);

    // Print the order
    print_order(order);

    return 0;
}