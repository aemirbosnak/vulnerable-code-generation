//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define the cafe menu
typedef struct {
    char *name;
    float price;
} MenuItem;

MenuItem menu[] = {
    {"Espresso", 3.00},
    {"Cappuccino", 3.50},
    {"Latte", 4.00},
    {"Mocha", 4.50},
    {"Tea", 2.50},
    {"Hot chocolate", 3.00},
    {"Pastry", 2.00},
    {"Muffin", 2.50}
};

// Define the customer order
typedef struct {
    int item_count;
    MenuItem *items;
} Order;

// Function to create a new order
Order *new_order(int item_count) {
    Order *order = malloc(sizeof(Order));
    order->item_count = item_count;
    order->items = malloc(sizeof(MenuItem) * item_count);
    return order;
}

// Function to add an item to an order
void add_item_to_order(Order *order, MenuItem *item) {
    order->items[order->item_count++] = *item;
}

// Function to calculate the total price of an order
float calculate_total_price(Order *order) {
    float total_price = 0.00;
    for (int i = 0; i < order->item_count; i++) {
        total_price += order->items[i].price;
    }
    return total_price;
}

// Function to print an order
void print_order(Order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->item_count; i++) {
        printf("  %s: $%.2f\n", order->items[i].name, order->items[i].price);
    }
    printf("Total: $%.2f\n", calculate_total_price(order));
}

// Function to free the memory allocated for an order
void free_order(Order *order) {
    free(order->items);
    free(order);
}

// Main function
int main() {
    // Create a new order
    Order *order = new_order(3);

    // Add items to the order
    add_item_to_order(order, &menu[0]);
    add_item_to_order(order, &menu[2]);
    add_item_to_order(order, &menu[6]);

    // Print the order
    print_order(order);

    // Free the memory allocated for the order
    free_order(order);

    return 0;
}