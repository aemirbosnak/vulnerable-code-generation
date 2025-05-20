//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in a single order
#define MAX_ITEMS 10

// Define the menu items
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the order items
typedef struct {
    MenuItem item;
    int quantity;
} OrderItem;

// Define the order
typedef struct {
    OrderItem items[MAX_ITEMS];
    int num_items;
    float total_price;
} Order;

// Function to create a new menu item
MenuItem *create_menu_item(char *name, float price) {
    MenuItem *item = malloc(sizeof(MenuItem));
    strcpy(item->name, name);
    item->price = price;
    return item;
}

// Function to create a new order item
OrderItem *create_order_item(MenuItem *item, int quantity) {
    OrderItem *order_item = malloc(sizeof(OrderItem));
    order_item->item = *item;
    order_item->quantity = quantity;
    return order_item;
}

// Function to create a new order
Order *create_order() {
    Order *order = malloc(sizeof(Order));
    order->num_items = 0;
    order->total_price = 0.0f;
    return order;
}

// Function to add an item to an order
void add_item_to_order(Order *order, OrderItem *order_item) {
    order->items[order->num_items] = *order_item;
    order->num_items++;
    order->total_price += order_item->item.price * order_item->quantity;
}

// Function to print an order
void print_order(Order *order) {
    printf("Order Summary:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s x%d = $%.2f\n", order->items[i].item.name, order->items[i].quantity, order->items[i].item.price * order->items[i].quantity);
    }
    printf("Total Price: $%.2f\n", order->total_price);
}

// Main function
int main() {
    // Create a menu
    MenuItem *menu_items[] = {
        create_menu_item("Coffee", 2.50f),
        create_menu_item("Tea", 1.50f),
        create_menu_item("Cake", 3.00f),
        create_menu_item("Cookie", 1.00f),
    };

    // Create an order
    Order *order = create_order();

    // Add items to the order
    add_item_to_order(order, create_order_item(menu_items[0], 2));
    add_item_to_order(order, create_order_item(menu_items[1], 1));
    add_item_to_order(order, create_order_item(menu_items[2], 1));

    // Print the order
    print_order(order);

    // Free the allocated memory
    for (int i = 0; i < 4; i++) {
        free(menu_items[i]);
    }
    for (int i = 0; i < order->num_items; i++) {
        free(&order->items[i]);
    }
    free(order);

    return 0;
}