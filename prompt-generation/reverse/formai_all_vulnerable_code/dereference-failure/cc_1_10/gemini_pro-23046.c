//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and prices
char *menu_items[] = {
    "Coffee",
    "Tea",
    "Espresso",
    "Cappuccino",
    "Latte",
    "Mocha",
    "Hot Chocolate",
    "Apple Pie",
    "Blueberry Muffin",
    "Chocolate Chip Cookie"
};

double menu_prices[] = {
    1.50,
    1.25,
    2.00,
    2.50,
    3.00,
    3.50,
    2.75,
    1.75,
    1.50,
    1.25
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order item
typedef struct order_item {
    char *item_name;
    double item_price;
    int item_quantity;
} order_item;

// Define the structure of an order
typedef struct order {
    order_item items[MAX_ITEMS];
    int num_items;
    double total_price;
} order;

// Create a new order
order *create_order() {
    order *new_order = malloc(sizeof(order));
    new_order->num_items = 0;
    new_order->total_price = 0.0;
    return new_order;
}

// Add an item to an order
void add_item_to_order(order *order, char *item_name, double item_price, int item_quantity) {
    if (order->num_items < MAX_ITEMS) {
        order->items[order->num_items].item_name = item_name;
        order->items[order->num_items].item_price = item_price;
        order->items[order->num_items].item_quantity = item_quantity;
        order->num_items++;
        order->total_price += item_price * item_quantity;
    } else {
        printf("Error: cannot add more than %d items to an order.\n", MAX_ITEMS);
    }
}

// Print an order
void print_order(order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("  %s x %d = $%.2f\n", order->items[i].item_name, order->items[i].item_quantity, order->items[i].item_price * order->items[i].item_quantity);
    }
    printf("Total: $%.2f\n", order->total_price);
}

// Free the memory allocated for an order
void free_order(order *order) {
    free(order);
}

// Main function
int main() {
    // Create a new order
    order *my_order = create_order();

    // Add some items to the order
    add_item_to_order(my_order, "Coffee", 1.50, 2);
    add_item_to_order(my_order, "Tea", 1.25, 1);
    add_item_to_order(my_order, "Apple Pie", 1.75, 1);

    // Print the order
    print_order(my_order);

    // Free the memory allocated for the order
    free_order(my_order);

    return 0;
}