//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Menu items
typedef struct MenuItem {
    char name[30];
    float price;
} MenuItem;

// Order items
typedef struct OrderItem {
    int quantity;
    MenuItem *item;
} OrderItem;

// Order
typedef struct Order {
    OrderItem *items;
    int num_items;
    float total_price;
} Order;

// Create a new menu item
MenuItem *create_menu_item(char *name, float price) {
    MenuItem *item = malloc(sizeof(MenuItem));
    strcpy(item->name, name);
    item->price = price;
    return item;
}

// Create a new order item
OrderItem *create_order_item(MenuItem *item, int quantity) {
    OrderItem *order_item = malloc(sizeof(OrderItem));
    order_item->item = item;
    order_item->quantity = quantity;
    return order_item;
}

// Create a new order
Order *create_order() {
    Order *order = malloc(sizeof(Order));
    order->items = NULL;
    order->num_items = 0;
    order->total_price = 0.0f;
    return order;
}

// Add an item to an order
void add_item_to_order(Order *order, OrderItem *item) {
    order->items = realloc(order->items, (order->num_items + 1) * sizeof(OrderItem));
    order->items[order->num_items++] = *item;
    order->total_price += item->item->price * item->quantity;
}

// Print the menu
void print_menu(MenuItem *menu, int num_items) {
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Print an order
void print_order(Order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%d. %s x%d - $%.2f\n", i + 1, order->items[i].item->name, order->items[i].quantity, order->items[i].item->price * order->items[i].quantity);
    }
    printf("Total: $%.2f\n", order->total_price);
}

// Get user input
int get_int_input(char *prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

// Main function
int main() {
    // Create the menu
    MenuItem menu[] = {
        {"Coffee", 2.50f},
        {"Tea", 1.50f},
        {"Cake", 3.00f},
        {"Muffin", 2.00f}
    };
    int num_menu_items = sizeof(menu) / sizeof(MenuItem);

    // Create an order
    Order *order = create_order();

    // Print the menu
    print_menu(menu, num_menu_items);

    // Get user input
    int choice;
    do {
        choice = get_int_input("Enter the number of the item you want to order, or 0 to quit: ");
        if (choice > 0 && choice <= num_menu_items) {
            int quantity = get_int_input("Enter the quantity: ");
            OrderItem *item = create_order_item(&menu[choice - 1], quantity);
            add_item_to_order(order, item);
        }
    } while (choice != 0);

    // Print the order
    print_order(order);

    return 0;
}