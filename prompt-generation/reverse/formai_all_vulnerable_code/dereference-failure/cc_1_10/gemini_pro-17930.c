//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items in an order
#define MAX_ITEMS 10

// Define the menu items and their prices
const char *menu_items[] = {"Coffee", "Tea", "Soda", "Water", "Muffin", "Donut", "Cookie", "Chips", "Fruit", "Yogurt"};
const double menu_prices[] = {1.50, 1.00, 1.25, 0.75, 2.00, 1.50, 1.00, 1.25, 1.50, 1.75};

// Define the order structure
typedef struct {
    int item_count;
    int item_ids[MAX_ITEMS];
    int item_quantities[MAX_ITEMS];
} order_t;

// Create a new order
order_t *new_order() {
    order_t *order = malloc(sizeof(order_t));
    order->item_count = 0;
    return order;
}

// Add an item to an order
void add_item(order_t *order, int item_id, int quantity) {
    if (order->item_count < MAX_ITEMS) {
        order->item_ids[order->item_count] = item_id;
        order->item_quantities[order->item_count] = quantity;
        order->item_count++;
    } else {
        printf("Error: Order is full\n");
    }
}

// Calculate the total price of an order
double calculate_total(order_t *order) {
    double total = 0.0;
    for (int i = 0; i < order->item_count; i++) {
        total += menu_prices[order->item_ids[i]] * order->item_quantities[i];
    }
    return total;
}

// Print an order
void print_order(order_t *order) {
    printf("Order:\n");
    for (int i = 0; i < order->item_count; i++) {
        printf("%s x %d\n", menu_items[order->item_ids[i]], order->item_quantities[i]);
    }
    printf("Total: $%.2f\n", calculate_total(order));
}

// Free an order
void free_order(order_t *order) {
    free(order);
}

// Main function
int main() {
    // Create a new order
    order_t *order = new_order();

    // Add some items to the order
    add_item(order, 0, 2); // Coffee x 2
    add_item(order, 1, 1); // Tea x 1
    add_item(order, 2, 1); // Soda x 1

    // Print the order
    print_order(order);

    // Free the order
    free_order(order);

    return 0;
}