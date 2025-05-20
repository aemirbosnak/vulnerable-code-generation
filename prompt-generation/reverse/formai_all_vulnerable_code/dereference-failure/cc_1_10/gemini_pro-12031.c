//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A struct to represent a menu item
typedef struct MenuItem {
    char* name;
    double price;
} MenuItem;

// A struct to represent an order
typedef struct Order {
    MenuItem* item;
    int quantity;
} Order;

// A struct to represent a cafe
typedef struct Cafe {
    MenuItem* menu;
    int num_menu_items;
    Order* orders;
    int num_orders;
} Cafe;

// Create a new cafe
Cafe* create_cafe() {
    Cafe* cafe = malloc(sizeof(Cafe));
    cafe->menu = NULL;
    cafe->num_menu_items = 0;
    cafe->orders = NULL;
    cafe->num_orders = 0;

    // TODO: Initialize the cafe with some menu items

    return cafe;
}

// Add a menu item to the cafe
void add_menu_item(Cafe* cafe, MenuItem* item) {
    cafe->menu = realloc(cafe->menu, (cafe->num_menu_items + 1) * sizeof(MenuItem));
    cafe->menu[cafe->num_menu_items] = *item;
    cafe->num_menu_items++;
}

// Add an order to the cafe
void add_order(Cafe* cafe, Order* order) {
    cafe->orders = realloc(cafe->orders, (cafe->num_orders + 1) * sizeof(Order));
    cafe->orders[cafe->num_orders] = *order;
    cafe->num_orders++;
}

// Calculate the total cost of an order
double calculate_order_total(Order* order) {
    return order->item->price * order->quantity;
}

// Calculate the total cost of all orders in the cafe
double calculate_cafe_total(Cafe* cafe) {
    double total = 0;
    for (int i = 0; i < cafe->num_orders; i++) {
        total += calculate_order_total(&cafe->orders[i]);
    }
    return total;
}

// Print the menu
void print_menu(Cafe* cafe) {
    printf("Menu:\n");
    for (int i = 0; i < cafe->num_menu_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, cafe->menu[i].name, cafe->menu[i].price);
    }
}

// Print an order
void print_order(Order* order) {
    printf("%s x%d - $%.2f\n", order->item->name, order->quantity, calculate_order_total(order));
}

// Print all orders in the cafe
void print_orders(Cafe* cafe) {
    printf("Orders:\n");
    for (int i = 0; i < cafe->num_orders; i++) {
        print_order(&cafe->orders[i]);
    }
}

// Print the cafe's total revenue
void print_cafe_total(Cafe* cafe) {
    printf("Total: $%.2f\n", calculate_cafe_total(cafe));
}

// Free the memory allocated for the cafe
void free_cafe(Cafe* cafe) {
    for (int i = 0; i < cafe->num_menu_items; i++) {
        free(cafe->menu[i].name);
    }
    free(cafe->menu);
    for (int i = 0; i < cafe->num_orders; i++) {
        free(cafe->orders[i].item);
    }
    free(cafe->orders);
    free(cafe);
}

// Main function
int main() {
    // Create a new cafe
    Cafe* cafe = create_cafe();

    // Add some menu items to the cafe
    MenuItem item1 = {"Coffee", 2.50};
    add_menu_item(cafe, &item1);
    MenuItem item2 = {"Tea", 1.50};
    add_menu_item(cafe, &item2);
    MenuItem item3 = {"Cake", 3.00};
    add_menu_item(cafe, &item3);

    // Add some orders to the cafe
    Order order1 = {&item1, 2};
    add_order(cafe, &order1);
    Order order2 = {&item2, 1};
    add_order(cafe, &order2);
    Order order3 = {&item3, 1};
    add_order(cafe, &order3);

    // Print the menu
    print_menu(cafe);

    // Print the orders
    print_orders(cafe);

    // Print the cafe's total revenue
    print_cafe_total(cafe);

    // Free the memory allocated for the cafe
    free_cafe(cafe);

    return 0;
}