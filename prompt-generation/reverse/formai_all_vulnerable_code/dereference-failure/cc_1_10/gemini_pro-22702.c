//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the menu items and their prices
char *menu_items[] = {
    "Coffee",
    "Tea",
    "Espresso",
    "Cappuccino",
    "Latte",
    "Muffin",
    "Cookie",
    "Scone",
    "Pastry",
    "Bagel"
};

float menu_prices[] = {
    1.50,
    1.25,
    2.00,
    2.50,
    3.00,
    2.00,
    1.00,
    1.50,
    2.00,
    1.75
};

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
    float total_price;
} order;

// Function to create a new order
order *create_order() {
    order *new_order = (order *)malloc(sizeof(order));
    new_order->num_items = 0;
    new_order->total_price = 0.0;
    return new_order;
}

// Function to add an item to an order
void add_item_to_order(order *order, char *item, int quantity) {
    // Check if the order is full
    if (order->num_items >= MAX_ITEMS) {
        printf("Error: Order is full.\n");
        return;
    }

    // Find the index of the item in the menu
    int item_index = -1;
    for (int i = 0; i < 10; i++) {
        if (strcmp(item, menu_items[i]) == 0) {
            item_index = i;
            break;
        }
    }

    // Check if the item is valid
    if (item_index == -1) {
        printf("Error: Invalid item.\n");
        return;
    }

    // Add the item to the order
    order->items[order->num_items].item = menu_items[item_index];
    order->items[order->num_items].quantity = quantity;
    order->items[order->num_items].price = menu_prices[item_index] * quantity;
    order->num_items++;
    order->total_price += order->items[order->num_items - 1].price;
}

// Function to print an order
void print_order(order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s x%d: $%.2f\n", order->items[i].item, order->items[i].quantity, order->items[i].price);
    }
    printf("Total: $%.2f\n", order->total_price);
}

// Function to free the memory allocated for an order
void free_order(order *order) {
    free(order);
}

// Main function
int main() {
    // Create a new order
    order *order = create_order();

    // Add items to the order
    add_item_to_order(order, "Coffee", 2);
    add_item_to_order(order, "Tea", 1);
    add_item_to_order(order, "Muffin", 3);

    // Print the order
    print_order(order);

    // Free the memory allocated for the order
    free_order(order);

    return 0;
}